#pragma once
// std
// libs
// non-sys
// sys
#include "PhysicalComponent.h"
#include "GraphicsComponent.h"
#include "CombatComponent.h"
#include "AIComponent.h"
#include "AnimationComponent.h"

class Entity
{

public:
	Entity(std::unique_ptr<PhysicalComponent> physicalComponent_ = nullptr,
		std::unique_ptr<GraphicsComponent> graphicsComponent_ = nullptr,
		std::unique_ptr<CombatComponent> combatComponent_ = nullptr,
		std::unique_ptr<AIComponent> aiComponent_ = nullptr,
		std::unique_ptr<AnimationComponent> animationComponent_ = nullptr); /*!< Sets _id to statID and increments statID */
	~Entity();
public:
private:
public:
	// primitives
	int _id;
	// components
	std::unique_ptr<PhysicalComponent> _physicalComponent;
	std::unique_ptr<GraphicsComponent> _graphicsComponent;
	std::unique_ptr<CombatComponent> _combatComponent;
	std::unique_ptr<AIComponent> _aiComponent;
	std::unique_ptr<AnimationComponent> _animationComponent;
private:
	static int staticID;
};

