#pragma once
#include "AnimationComponent.h"
#include "Enums.h"

// updates animation components
class AnimationSystem
{
public:
	AnimationSystem();
	~AnimationSystem();

	void UpdateAnimation(AnimationComponent & animationComponent_, FacingDirections facingDirection_);
};

