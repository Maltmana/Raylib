#pragma once
#include "Enums.h"

struct GraphicsComponent
{
	typedef std::unique_ptr<GraphicsComponent> upt;
	GraphicsComponent(GraphicsTypes graphicsType_);
	~GraphicsComponent();
	// NO FUNCTIONS
	GraphicsTypes _graphicsType;

};

