#include "stdafx.h"
#include "AnimationSystem.h"


AnimationSystem::AnimationSystem()
{
}


AnimationSystem::~AnimationSystem()
{
}

void AnimationSystem::UpdateAnimation(AnimationComponent & animationComponent_, FacingDirections facingDirection_)
{
	// connecting the facing to the animation row here.
	switch (facingDirection_)
	{
	case FacingDirections::North: animationComponent_._currentFrameRow = 0;
		break;
	case FacingDirections::East: animationComponent_._currentFrameRow = 1;
		break;
	case FacingDirections::South: animationComponent_._currentFrameRow = 2;
		break;
	case FacingDirections::West: animationComponent_._currentFrameRow = 3;
		break;
	default:
		break;
	}

	// animation column.
	animationComponent_._elapsedAnimTime = animationComponent_._elapsedAnimTime + GetFrameTime();
	if (animationComponent_._elapsedAnimTime >= animationComponent_._animTime)
	{
		if (animationComponent_._rising)
		{
			animationComponent_._currentFrameCol += 1;
			if (animationComponent_._currentFrameCol == animationComponent_._frameAmount)
			{
				animationComponent_._rising = false;
			}
		}
		else
		{
			animationComponent_._currentFrameCol -= 1;
			if (animationComponent_._currentFrameCol == 1)
			{
				animationComponent_._rising = true;
			}
		}
		animationComponent_._elapsedAnimTime = 0.f;
	}
}
