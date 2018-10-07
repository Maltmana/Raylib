#pragma once
#include "stdafx.h"

class Clock
{
public:
	Clock()
	{
	};

	bool returnTrueEvery(float per)
	{
		float frameTime = GetFrameTime();
		timer1 += frameTime;
		if (timer1 >= per)
		{
			timer1 = 0.f;
			return true;
		}
		else
		{
			return false;
		}
	}
	float timer1;
	std::vector<float> timers;

};

