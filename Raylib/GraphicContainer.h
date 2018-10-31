#pragma once
#include "Graphic.h"
class GraphicContainer
{
public:
	GraphicContainer();
	~GraphicContainer();
public:
private:
public:
	inline std::vector<std::unique_ptr<Graphic>>& getGraphics() { return _graphics; };
private:
	std::vector<std::unique_ptr<Graphic>> _graphics;
};

