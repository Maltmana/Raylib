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
}

void CreatureContainer::DrawCreatures(CreatureVisualizer const & cv_, std::list<Graphic> const & graphics_) const
{
	for (auto const & creature : _creatures)
	{
		cv_.visualize(creature, graphics_.front());
	}
}
