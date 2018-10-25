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
	inline std::vector<std::unique_ptr<Graphic>>& getGraphics() { return _graphics; };
private:
	std::vector<std::unique_ptr<Graphic>> _graphics;
};

