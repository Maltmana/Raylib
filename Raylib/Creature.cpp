#include "Creature.h"


// class functions
Creature::Creature(Vector2 const & p_pos)
	:
	m_pos{ p_pos }
{
	puts("creature created");
}

Creature::~Creature()
{
}

void Creature::Update(std::list<Creature> const & p_creatures)
{
	CalculateVectorToTarget();
	Move();


	m_collision = { m_pos.x, m_pos.y, 16, 18 },

		change_facing(m_vecToTargNorm);

	run_waypoints();

	collideSolidly(p_creatures);


	m_animation.UpdateAnimation(m_facing);

}

void Creature::Move()
{
	// Bug : without deadZone can't see sprites and they shake rapidly back and forth when at targPos.
	float deadZone = 10.f; // TODO not need so much deadzone
	if (!(MyHelperLib::approx(m_pos.x, m_targPos.x, deadZone) && MyHelperLib::approx(m_pos.y, m_targPos.y, deadZone)))
	{
		float pixPerSecond = _speed * GetFrameTime();
		Vector2 scaled = RayMath::Vector2Scale(m_vecToTargNorm, pixPerSecond);
		m_pos = RayMath::Vector2Add(m_pos, scaled);
	}
	// Clamp movement for collision

}

void Creature::collideSolidly(std::list<Creature> const & p_creatures)
{
	for (auto & creature : p_creatures)
	{
		if (m_pos.x != creature.m_pos.x && m_pos.y != creature.m_pos.y)
		{
			if (m_collision.y <= creature.m_collision.y + creature.m_collision.height &&
				creature.m_collision.y <= m_collision.y + m_collision.height &&
				m_collision.x <= creature.m_collision.x + creature.m_collision.width &&
				creature.m_collision.x <= m_collision.x + m_collision.width)
			{
				if (MyHelperLib::approx(m_collision.y, creature.m_collision.y + creature.m_collision.height, 1))
				{
					m_collidingTop = true;
				}
				else
				{
					m_collidingTop = false;
				}

				if (MyHelperLib::approx(m_collision.y + m_collision.height, creature.m_collision.y, 1))
				{
					m_collidingBottom = true;
				}
				else
				{
					m_collidingBottom = false;
				}

				if (MyHelperLib::approx(m_collision.x, creature.m_collision.x + creature.m_collision.width, 1))
				{
					m_collidingLeft = true;
				}
				else
				{
					m_collidingLeft = false;
				}

				if (MyHelperLib::approx(m_collision.x + m_collision.width, creature.m_collision.x, 1))
				{
					m_collidingRight = true;
				}
				else
				{
					m_collidingRight = false;
				}
			}
			else
			{
				m_collidingTop = false;
				m_collidingBottom = false;
				m_collidingLeft = false;
				m_collidingRight = false;
			}
		}
	}
}

void Creature::run_waypoints()
{
	if (!m_wayPoints.empty() && m_wayPoints[0].x != m_targPos.x && m_wayPoints[0].y != m_targPos.y)
	{
		m_targPos = m_wayPoints[0];

	}
	if (!m_wayPoints.empty() && (m_pos.x < m_targPos.x + 5 && m_pos.x > m_targPos.x - 5) && (m_pos.y < m_targPos.y + 5 && m_pos.y > m_targPos.y - 5))
	{
		m_wayPoints.pop_front();
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

void Creature::CalculateVectorToTarget()
{
	m_vecToTarg = RayMath::Vector2Subtract(m_targPos, m_pos);
	m_vecToTargNorm = RayMath::Vector2Normalize(m_vecToTarg);
}




