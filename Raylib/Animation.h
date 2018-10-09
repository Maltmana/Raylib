#pragma once
#include "stdafx.h"

/* Holds persistent graphics data and functions for creatures. */
class Animation
{
public:
	Animation();
	~Animation();

public:
	void UpdateAnimation(int p_facing); // VISUAL
public:

	float animTime = 1.f; // VISUAL
	float elapsedAnimTime = 0.f; // VISUAL
	bool rising = true; // VISUAL
	int currentFrame = 2; // VISUAL
	int currentFrameRow = 0; // VISUAL
	int frameAmount = 3; // VISUAL

};
