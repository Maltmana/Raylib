#include "Animation.h"

Animation::Animation()
{
}

Animation::~Animation()
{
}


void Animation::UpdateAnimation(int p_facing)
{
	// connecting the facing to the animation row here.
	switch (p_facing)
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