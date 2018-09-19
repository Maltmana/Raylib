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
		elapsedAnimTime = 0.f;
	}
	// member functions
	void Update(Vector2 p_targPos)
	{

	}
	void UpdateAnimation()
	{
		elapsedAnimTime = elapsedAnimTime + GetFrameTime();
		if (elapsedAnimTime >= animTime)
		{
			if (rising)
			{
				currentFrame += 1;
				printf("%d\n", currentFrame);
				if (currentFrame == frameAmount)
				{
					rising = false;
				}
			}
			else
			{
				currentFrame -= 1;
				printf("%d\n", currentFrame);
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
	float animTime = 1.f;
	float elapsedAnimTime;
	bool rising = true;
	int currentFrame = 2;
	int frameAmount = 3;
};
