#include "Creature.h"

int Creature::id = 1;

// class functions
Creature::Creature(Vector2 const & p_pos)
	:
	m_pos{ p_pos },
	_id{ id }
{

	std::cout << "creature created. ID: " << id << '\n';
	id++;
}

Creature::~Creature()
{
}

void Creature::Update(std::list<Creature> const & p_creatures)
{
	CalculateVectorToTarget();
	start_move_process(p_creatures);
	change_facing(m_vecToTargNorm);
	if (m_creatureTargetWayPoints.empty())
		run_waypoints();
	else
		run_creature_waypoints();
	m_animation.UpdateAnimation(m_facing);
}

void Creature::start_move_process(std::list<Creature> const & p_creatures)
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

void Creature::Move()
{
	m_pos = m_newPos;
}

void Creature::calculate_move()
{
	float pixPerSecond = _speed * GetFrameTime();
	Vector2 scaled = RayMath::Vector2Scale(m_vecToTargNorm, pixPerSecond);
	m_newPos = RayMath::Vector2Add(m_pos, scaled);
}

bool Creature::is_colliding(std::list<Creature> const & p_creatures)
{
	for (auto const & creature : p_creatures)
	{
		if (!(this == &creature))
		{
			Vector2 differenceVector = RayMath::Vector2Subtract(m_newPos, creature.m_pos);

			if (RayMath::Vector2Length(differenceVector) < m_collisionRadius * 2)
			{
				std::cout << "is colliding!";
				return true;
			}
		}

	}
	return false;
}

void Creature::run_waypoints()
{
	if (!m_wayPoints.empty())
	{
		m_targPos = m_wayPoints[0];
		if ((m_pos.x < m_targPos.x + 5 && m_pos.x > m_targPos.x - 5) && (m_pos.y < m_targPos.y + 5 && m_pos.y > m_targPos.y - 5))
		{
			m_wayPoints.pop_front();
		}
	}
}

void Creature::run_creature_waypoints()
{
	int closeness = 100;
	if (!m_creatureTargetWayPoints.empty())
	{
			m_targPos = m_creatureTargetWayPoints.back().get().m_pos;
	}
}

void Creature::change_facing(Vector2 const & p_normalizedVector)
{
	// x,y normalised = destiantion minus position.  if x is positive and abs y is less than square root of 2 then face right. if the same but x neg face left. otherwise if y is greater than 
	// square of 2 and positive, face north, else face south. 
	if (p_normalizedVector.x > 0 && std::abs(p_normalizedVector.y) < RayMath::sin_45)
	{
		m_facing = (int)FacingDirections::East;
		return;
	}
	if (p_normalizedVector.x < 0 && std::abs(p_normalizedVector.y) < RayMath::sin_45)
	{
		m_facing = (int)FacingDirections::West;
		return;
	}
	else if (p_normalizedVector.y < 0)
	{
		m_facing = (int)FacingDirections::North;
		return;
	}
	else if (p_normalizedVector.y > 0)
	{
		m_facing = (int)FacingDirections::South;
		return;
	}
}

void Creature::change_targ(Vector2 p_targPos)
{
	m_targPos = p_targPos; // TODO this throws read access violation.
}

void Creature::process_attacking()
{
}

void Creature::attack()
{
}

void Creature::take_damage()
{
}

void Creature::CalculateVectorToTarget()
{
	m_vecToTarg = RayMath::Vector2Subtract(m_targPos, m_pos);
	m_vecToTargNorm = RayMath::Vector2Normalize(m_vecToTarg);
}




