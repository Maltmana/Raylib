#pragma once
#include "Graphic.h"
class GraphicsContainer
{
public:
	GraphicsContainer();
	~GraphicsContainer();
public:
private:
public:
	inline std::vector<Graphic>& getGraphics() { return _graphics; };
private:
	std::vector<Graphic> _graphics;
};

