#pragma once
#include "EntityContainer.h"
#include "Creature.h"
#include "GraphicContainer.h"
#include "Graphic.h"

class DrawHandler
{
public:
	DrawHandler();
	~DrawHandler();
public:
private:
public:
	void hande_drawing(EntityContainer entityContainer_, GraphicContainer graphicContainer_);
private:
};

