#pragma once
// std
// lib
// non-system
#include "stdafx.h"
// system
#include "Creature.h"
#include "Graphic.h"
#include "GraphicContainer.h"
class EntityContainer
{
public:
	EntityContainer();
	~EntityContainer();
public:

private:
public:
	// primitives
	// flags
	// containers
	std::vector<std::shared_ptr<Creature>> _entities;
	std::vector<std::weak_ptr<Creature>> _entitiesWP; // TODO there has got to be a better way than making 2 containers for two types.. templates or something
	// objects
	std::vector<std::shared_ptr<Creature>>::iterator _entitiesIt;
private:
	// primitives
	// flags
	// objects
};

