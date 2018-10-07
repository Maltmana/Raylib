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
	void Update()
	{
		Vector2 subtractedVector = RayMath::Vector2Subtract(m_targPos, m_pos);
		Vector2 normalizedVector = RayMath::Vector2Normalize(subtractedVector);
		m_pos = RayMath::Vector2Add(m_pos, normalizedVector);

		m_collision = { m_pos.x, m_pos.y, 16, 18 },

		change_facing(normalizedVector);


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

	Vector2 m_pos;
	Rectangle m_collision = { 0,0,0,0};
	Vector2 m_targPos;
	int m_facing = (int)FacingDirections::South;
	float animTime = 1.f;
	float elapsedAnimTime = 0.f;
	bool rising = true;
	int currentFrame = 2;
	int currentFrameRow = 0;
	int frameAmount = 3;
	std::string creatureName = "dude";
};

