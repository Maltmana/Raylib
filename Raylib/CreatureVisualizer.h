#pragma once


class Creature;
class Graphic;

/* Meant to help seperate visual functions out of Creature. */
class CreatureVisualizer
{
public:
	CreatureVisualizer();
	~CreatureVisualizer();

	void visualize(Creature const & creature, Graphic const & graphic) const;

	void update_animation(Creature const & creature) const;

	void draw(Creature const & creature, Graphic const & graphic) const;

private:

};



