#pragma once
// std
// lib
// non-system
#include "stdafx.h"
// system
#include "Creature.h"
#include "CreatureVisualizer.h"
#include "Graphic.h"
class EntityContainer
{
public:
	EntityContainer();
	~EntityContainer();
public:
	void UpdateCreatures();
	void delete_dead(std::shared_ptr<Creature> & creature_);
	void DrawCreatures(CreatureVisualizer const & cv_, std::list<Graphic> const & graphics_) const;
private:
public:
	// primitives
	// flags
	// containers
	std::vector<std::shared_ptr<Creature>> _entities;
	// objects
	std::vector<std::shared_ptr<Creature>>::iterator _entitiesIt;
private:
	// primitives
	// flags
	// objects
};

