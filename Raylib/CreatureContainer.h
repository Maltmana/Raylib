#pragma once
// std
// lib
// non-system
#include "stdafx.h"
// system
#include "Creature.h"
#include "CreatureVisualizer.h"
#include "Graphic.h"
class CreatureContainer
{
public:
	CreatureContainer();
	~CreatureContainer();
public:
	void UpdateCreatures();
	void delete_dead(Creature const & creature_);
	void DrawCreatures(CreatureVisualizer const & cv_, std::list<Graphic> const & graphics_) const;
private:
public:
	// primitives
	// flags
	// containers
	std::list<Creature> _creatures;
	// objects
	std::list<Creature>::iterator _creatureIt;
private:
	// primitives
	// flags
	// objects
};

