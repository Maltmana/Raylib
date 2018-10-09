#pragma once
#include "stdafx.h"
class Window
{
public:
	Window();
	~Window();

private:

};

// TODO load params from file
Window::Window()
{
	constexpr int screenWidth = 1000;
	constexpr int screenHeight = 800;
	InitWindow(screenWidth, screenHeight, "ARENA");
	SetTargetFPS(60);
}

Window::~Window()
{
	CloseWindow();
}