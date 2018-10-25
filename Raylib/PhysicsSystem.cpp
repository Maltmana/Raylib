#include "stdafx.h"
#include "PhysicsSystem.h"


PhysicsSystem::PhysicsSystem()
{
}

PhysicsSystem::~PhysicsSystem()
{
}

void PhysicsSystem::Update(Vector2 const & targetVector, PhysicalComponent & physicalComponent_, std::list<std::shared_ptr<Creature>> const & p_creatures)
{
	// cache reference
	_physicalComponent = &physicalComponent_;

	CalculateVectorToTarget();
	start_move_process(p_creatures);
	change_facing();
}

void PhysicsSystem::start_move_process(std::list<std::shared_ptr<Creature>> const & p_creatures)
{
	// Bug : without deadZone can't see sprites and they shake rapidly back and forth when at targPos.
	float deadZone = 5.f; // TODO not need so much deadzone
	if (!(MyHelperLib::approx(m_pos.x, m_targPos.x, deadZone) && MyHelperLib::approx(m_pos.y, m_targPos.y, deadZone)))
	{
		calculate_move();
		if (is_colliding(p_creatures))
		{
		}
		else
		{
			Move();
		}
	}
}

void PhysicsSystem::Move()
{
	m_pos = m_newPos;
}

void PhysicsSystem::calculate_move()
{
	float pixPerSecond = _physicalComponent->_speed * GetFrameTime();
	Vector2 scaled = RayMath::Vector2Scale(_physicalComponent->_vecToTargNorm, pixPerSecond);
	_physicalComponent->_newPos = RayMath::Vector2Add(_physicalComponent->_position, scaled);
}

bool PhysicsSystem::is_colliding(std::list<std::shared_ptr<Creature>> const & p_creatures)
{
	for (auto const & creature : p_creatures)
	{
		if (!(this == creature.get()))
		{
			Vector2 differenceVector = RayMath::Vector2Subtract(_physicalComponent->_newPos, creature->m_pos);

			if (RayMath::Vector2Length(differenceVector) < _physicalComponent->_collisionRadius * 2)
			{
				return true;
			}
		}

	}
	return false;
}

void PhysicsSystem::change_facing()
{
	// x,y normalised = destiantion minus position.  if x is positive and abs y is less than square root of 2 then face right. if the same but x neg face left. otherwise if y is greater than 
	// square of 2 and positive, face north, else face south. 
	if (_physicalComponent->_vecToTargNorm.x > 0 && std::abs(_physicalComponent->_vecToTargNorm.y) < RayMath::sin_45)
	{
		_physicalComponent->_facing = FacingDirections::East;
		return;
	}
	if (_physicalComponent->_vecToTargNorm.x < 0 && std::abs(_physicalComponent->_vecToTargNorm.y) < RayMath::sin_45)
	{
		_physicalComponent->_facing = FacingDirections::West;
		return;
	}
	else if (_physicalComponent->_vecToTargNorm.y < 0)
	{
		_physicalComponent->_facing = FacingDirections::North;
		return;
	}
	else if (_physicalComponent->_vecToTargNorm.y > 0)
	{
		_physicalComponent->_facing = FacingDirections::South;
		return;
	}
}

void PhysicsSystem::CalculateVectorToTarget()
{
	_physicalComponent->_vecToTarg = RayMath::Vector2Subtract(_physicalComponent->_targPos, _physicalComponent->_position);
	_physicalComponent->_vecToTargNorm = RayMath::Vector2Normalize(_physicalComponent->_vecToTarg);
}

