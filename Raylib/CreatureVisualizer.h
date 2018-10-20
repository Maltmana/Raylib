#pragma once
#include "stdafx.h"


class Creature;
class Graphic;

/* Meant to help seperate visual functions out of Creature. */
class CreatureVisualizer
{
public:
	CreatureVisualizer();
	~CreatureVisualizer();

	void visualize(std::shared_ptr<Creature> const & creature, Graphic const & graphic) const;

	void update_animation(std::shared_ptr<Creature> const & creature) const;

	void draw(std::shared_ptr<Creature> const & creature, Graphic const & graphic) const;

private:

};



