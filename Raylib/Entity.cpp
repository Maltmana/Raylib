#include "stdafx.h"
#include "Entity.h"

int Entity::staticID = 1;
Entity::Entity(std::unique_ptr<PhysicalComponent> physicalComponent_,
	std::unique_ptr<GraphicsComponent> graphicsComponent_,
	std::unique_ptr<CombatComponent> combatComponent_,
	std::unique_ptr<AIComponent> aiComponent_,
	std::unique_ptr<AnimationComponent> animationComponent_)
	:
	_id{ staticID++ },
	_physicalComponent{ std::move(physicalComponent_) },
	_graphicsComponent{ std::move(graphicsComponent_) },
	_combatComponent{ std::move(combatComponent_) },
	_aiComponent{ std::move(aiComponent_) },
	_animationComponent{ std::move(animationComponent_) }
{
}
Entity::~Entity()
{
}
