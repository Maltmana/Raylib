#pragma once
// std
// libs
// non-sys
// sys
#include "PhysicalComponent.h"
#include "GraphicsComponent.h"
#include "CombatComponent.h"
#include "AIComponent.h"

// using
using PhysComp = std::unique_ptr<PhysicalComponent>;
using GraphComp = std::unique_ptr<GraphicsComponent>;
using CombatComp = std::unique_ptr<CombatComponent>;
using AIComp = std::unique_ptr<AIComponent>;

struct ComponentContainer
{
	ComponentContainer();
	~ComponentContainer();
	// NO FUNCTIONS
	// TODO change from hard coded components to some kind of container thingy.
	PhysComp _physicalComponent;
	GraphComp _graphicsComponent;
	CombatComp _combatComponent;
	AIComp _aiComponent;
};

