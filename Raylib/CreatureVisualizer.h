#pragma once


class Creature;

// This allows Creature to have no graphical information whatsoever
class CreatureVisualizer
{
public:
	CreatureVisualizer();
	~CreatureVisualizer();

	void visualize(Creature const & creature);

private:

};



