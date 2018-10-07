#pragma once
#include "stdafx.h"


enum class CreatureGraphicsTypes
{
	Monk,
	Fabio,
	DKnight,
	Wizard,
	Druid,
	Priest
};

enum class FacingDirections
{
	North,
	East,
	South,
	West
};

class Creature
{
public:
	// class functions
	Creature(Vector2 const & p_pos)
		:
		m_pos{p_pos},
		m_targPos{ p_pos.x +1, p_pos.y +1 }
	{
		puts("creature created");
	}
	// member functions
	void Update(std::vector<Creature> const & p_creatures)
	{
		Vector2 subtractedVector = RayMath::Vector2Subtract(m_targPos, m_pos);
		Vector2 normalizedVector = RayMath::Vector2Normalize(subtractedVector);
		if (!(m_pos.x < m_targPos.x + 1 && m_pos.x > m_targPos.x - 1) && !(m_pos.y < m_targPos.y + 1 && m_pos.y > m_targPos.y - 1))
		{

			m_pos = RayMath::Vector2Add(m_pos, normalizedVector);
		}


		m_collision = { m_pos.x, m_pos.y, 16, 18 },

		change_facing(normalizedVector);

		run_waypoints();

		collideSolidly(p_creatures);

	}

	void collideSolidly(std::vector<Creature> const & p_creatures)
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
					m_targPos.x = m_pos.x;
					m_targPos.y = m_pos.y;
				}
			}
		}
	}

	void run_waypoints()
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

	void change_facing(Vector2 const & p_normalizedVector)
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
	void change_targ(Vector2 p_targPos)
	{
		m_targPos = p_targPos; // TODO this throws read access violation.
	}
	void UpdateAnimation()
	{
		// connecting the facing to the animation row here.
		switch (m_facing)
		{
			case 0: currentFrameRow = 0;
				break;
			case 1: currentFrameRow = 1;
				break;
			case 2: currentFrameRow = 2;
				break;
			case 3: currentFrameRow = 3;
				break;
		default:
			break;
		}

		// animation column.
		elapsedAnimTime = elapsedAnimTime + GetFrameTime();
		if (elapsedAnimTime >= animTime)
		{
			if (rising)
			{
				currentFrame += 1;
				if (currentFrame == frameAmount)
				{
					rising = false;
				}
			}
			else
			{
				currentFrame -= 1;
				if (currentFrame == 1)
				{
					rising = true;
				}
			}
			elapsedAnimTime = 0.f;
		}
	}

	void UpdateDraw()
	{

	}

	// member variables
	public:
	Vector2 m_pos;
	Rectangle m_collision = { 0,0,0,0};
	Vector2 m_targPos;
	std::deque<Vector2> m_wayPoints;
	int m_facing = (int)FacingDirections::South;
	float animTime = 1.f;
	float elapsedAnimTime = 0.f;
	bool rising = true;
	int currentFrame = 2;
	int currentFrameRow = 0;
	int frameAmount = 3;
	std::string creatureName = "dude";
};

