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

class Creature
{
public:
	// class functions
	Creature(Vector2 const & p_pos)
	{
		m_pos = p_pos;
	}
	// member functions
	void Update(Vector2 p_targPos)
	{
		Vector2 subtractedVector = Vector2Subtract(p_targPos, m_pos);
		printf("%f\n", subtractedVector.y);
		m_pos = Vector2Add(m_pos, Vector2Normalize(subtractedVector));
		if (subtractedVector.y < 0 && (subtractedVector.x < 100 && subtractedVector.x > -100))
		{
			m_facing = 0;
			return;
		}
		if (subtractedVector.y >= 0 && (subtractedVector.x < 100 && subtractedVector.x > -100))
		{
			m_facing = 2;
			return;
		}
		if (subtractedVector.x < 0)
		{
			m_facing = 3;
		}
		if (subtractedVector.x >= 0)
		{
			m_facing = 1;
		}


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
	/*
	void UpdateAnimation()

		local frameAmount = 3
		if (elapsedTime >= 0.3) then
			if (rising) then
				currentFrame = currentFrame + 1
				if (currentFrame == frameAmount) then
					rising = false
					print("rising false")
					end
				else
					currentFrame = currentFrame - 1;
	if (currentFrame == 1) then
		rising = true
		print("rising true")
		end
		end
		activeFrame = frames[currentFrame]
		elapsedTime = 0
		end
		end*/
	void UpdateDraw()
	{

	}

	// member variables
	Vector2 m_pos;
	Vector2 m_targPos;
	int m_facing = 0;
	float animTime = 1.f;
	float elapsedAnimTime = 0.f;
	bool rising = true;
	int currentFrame = 2;
	int currentFrameRow = 0;
	int frameAmount = 3;
};
