#pragma once
// std
// libs
// nonsys
#include "stdafx.h"
#include "Enums.h"
// sys
#include "Graphic.h"
#include "GraphicsComponent.h"
#include "PhysicalComponent.h"
#include "AnimationComponent.h"

// operates on CONST graphics components and CONST physics components drawing from graphicsContainer.
class GraphicsSystem
{
public:
	GraphicsSystem(std::vector<std::unique_ptr<Graphic>> const & graphicsContainer_);
	~GraphicsSystem();
public:
	// gets graphics enum from graphicsComp, gives it to TextureProvider, Draws returned texture to where physicalComp tells it to.
	void draw(GraphicsComponent const & graphicsComp_, PhysicalComponent const & physicalComp_, AnimationComponent const & animationComp_);
private:
public:
private:
	std::vector<std::unique_ptr<Graphic>> const & _graphicsContainer;
};

