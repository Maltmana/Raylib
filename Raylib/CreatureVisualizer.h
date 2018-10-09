#pragma once


class Creature;
class Graphic;

// This allows Creature to have no graphical information whatsoever
class CreatureVisualizer
{
public:
	CreatureVisualizer();
	~CreatureVisualizer();

	void visualize(Creature const & creature, Graphic const & graphic);

private:

};



