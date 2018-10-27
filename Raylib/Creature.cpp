#include "Creature.h"
#include "EntityContainer.h"

int Creature::id = 1;

// class functions
Creature::Creature(GraphicType graphicType_, Vector2 const & p_pos)
	:
	_graphicType{graphicType_},
	m_pos{ p_pos },
	_id{ id }
{

	std::cout << "creature created. ID: " << _id << '\n';
	id++;
}

Creature::~Creature()
{
	std::cout << "creature destroyed. ID: " << _id << '\n';
}

void Creature::Update(EntityContainer & entityContainer_)
{
	CalculateVectorToTarget();
	start_move_process(entityContainer_);
	change_facing(m_vecToTargNorm); 
	if (m_creatureTargetWayPoints.empty()) // TODO bug when something dies it does not get removed from creatureTargetwaypoints
		run_waypoints();
	else
		run_creature_waypoints();
	m_animation.UpdateAnimation(m_facing);

	// combat
	if (!m_creatureTargetWayPoints.empty())
	{
		if (RayMath::Vector2Length(m_vecToTarg) < _attackRange)
		{
			process_attacking();
		}
	}
	handle_death();
	if (_isDead)
	{
		set_deleteMe();
	}

}

void Creature::start_move_process(EntityContainer & entityContainer_)
{
	// Bug : without deadZone can't see sprites and they shake rapidly back and forth when at targPos.
	float deadZone = 5.f; // TODO not need so much deadzone
	if (!(MyHelperLib::approx(m_pos.x, m_targPos.x, deadZone) && MyHelperLib::approx(m_pos.y, m_targPos.y, deadZone)))
	{
		calculate_move();
		if (is_colliding(entityContainer_))
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

bool Creature::is_colliding(EntityContainer & entityContainer_)
{
	for (auto const & entity : entityContainer_._entities)
	{
		if (!(this == entity.get()))
		{
			Vector2 differenceVector = RayMath::Vector2Subtract(m_newPos, entity->m_pos);

			if (RayMath::Vector2Length(differenceVector) < m_collisionRadius * 2)
			{
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
		if (auto const & validCreature = m_creatureTargetWayPoints.front().lock())
		{
			m_targPos = validCreature->m_pos;
		}
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
	_attackCooldownCounter += GetFrameTime();
	if (_attackCooldownCounter * _attacksPerSec >= 1)
	{
		bool isTargKilled = attack(); // returns true if is killed
		_attackCooldownCounter = 0;
		if (isTargKilled) // TODO this doesn't work if I have like 5 dudes all attacking one dude. only works for guy who got killing blow.
		{
			m_creatureTargetWayPoints.pop_front();
			puts("popped");
		}
	}

}

bool Creature::attack()
{
	std::cout << _id << " : is attacking\n";
	if (!m_creatureTargetWayPoints.empty())
	{
		if (auto const & validCreature = m_creatureTargetWayPoints.front().lock())
		{
			return validCreature->take_damage(_attackDamage);
		}
	}
}

bool Creature::take_damage(int const damage)
{
	_hp -= damage;
	std::cout << _id << ' ' << _hp << " : hp";
	return (_hp<=0);
}

void Creature::handle_death()
{
	if (_hp <= 0)
	{
		_isDead = true;
	}
}



void Creature::set_deleteMe()
{
	_deleteMe = true;
}

void Creature::CalculateVectorToTarget()
{
	m_vecToTarg = RayMath::Vector2Subtract(m_targPos, m_pos);
	m_vecToTargNorm = RayMath::Vector2Normalize(m_vecToTarg);
}




