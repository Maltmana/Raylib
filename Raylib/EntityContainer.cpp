#include "stdafx.h"
#include "EntityContainer.h"


EntityContainer::EntityContainer()
{
}


EntityContainer::~EntityContainer()
{
}

void EntityContainer::UpdateCreatures()
{
	for (auto & creature : _entities)
	{
		creature->Update(*this);
	}
	// TODO huge error
	// first pass creature that is flagged for delete is successfully deleted.
	// good seems to loop from back
	// second pass the deleted creature is referenced again... dangit.
	// crashes program

	// possibly why:
	// maybe the way deqeue works is when there is a pop operation it then moves the first one.

	// better solution, google it.
	_entitiesIt = _entities.begin();
	while (_entitiesIt != _entities.end())
	{
		delete_dead(*_entitiesIt);
		
	}

}

void EntityContainer::delete_dead(std::shared_ptr<Creature> & creature_)
{
		if (creature_->_deleteMe)
		{

			_entitiesIt = _entities.erase(_entitiesIt);
		}
		else
		{
			_entitiesIt++;
		}
}

void EntityContainer::DrawCreatures(CreatureVisualizer const & cv_, std::vector<std::unique_ptr<Graphic>> const & graphics_) const
{
	for (auto const & creature : _entities)
	{
		cv_.visualize(creature, *graphics_.front().get());
	}
}
