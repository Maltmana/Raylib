#pragma once
struct AnimationComponent
{
	AnimationComponent();
	~AnimationComponent();

	float _animTime = 1.f; // 1 second per frame
	float _elapsedAnimTime = 0.f;  // counter
	bool _rising = true; // flag to go back and forth through frame columns
	int _currentFrameCol = 0;
	int _currentFrameRow = 0; 
	int _frameAmount = 3; // there are 3 columns // TODO make this come from graphic directly

};

