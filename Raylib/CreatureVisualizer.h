#pragma once


class Creature;
class Graphic;

/* Meant to help seperate visual functions out of Creature. */
class CreatureVisualizer
{
public:
	CreatureVisualizer();
	~CreatureVisualizer();

	void visualize(Creature const & creature, Graphic const & graphic);

	void update_animation(Creature const & creature);

	void draw(Creature const & creature, Graphic const & graphic);

private:

};



