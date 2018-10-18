#include "stdafx.h"
#include "CreatureContainer.h"


CreatureContainer::CreatureContainer()
{
}


CreatureContainer::~CreatureContainer()
{
}

void CreatureContainer::UpdateCreatures()
{
	for (auto & creature : _creatures)
	{
		creature.Update(_creatures);
	}
	// TODO huge error
	// first pass creature that is flagged for delete is successfully deleted.
	// good seems to loop from back
	// second pass the deleted creature is referenced again... dangit.
	// crashes program

	// possibly why:
	// maybe the way deqeue works is when there is a pop operation it then moves the first one.

	// better solution, google it.
	_creatureIt = _creatures.begin();
	while (_creatureIt != _creatures.end())
	{
		delete_dead(*_creatureIt);
		
	}

}

void CreatureContainer::delete_dead(Creature const & creature_)
{
		if (creature_._deleteMe)
		{

			_creatureIt = _creatures.erase(_creatureIt);
		}
		else
		{
			_creatureIt++;
		}
}

void CreatureContainer::DrawCreatures(CreatureVisualizer const & cv_, std::list<Graphic> const & graphics_) const
{
	for (auto const & creature : _creatures)
	{
		cv_.visualize(creature, graphics_.front());
	}
}
