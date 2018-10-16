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
	void DrawCreatures(CreatureVisualizer const & cv_, std::list<Graphic> const & graphics_) const;
private:
public:
	// primitives
	// flags
	// containers
	std::list<Creature> _creatures;
	// objects
private:
	// primitives
	// flags
	// objects
};

