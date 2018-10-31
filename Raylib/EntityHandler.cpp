#include "stdafx.h"
#include "EntityHandler.h"


EntityHandler::EntityHandler()
{
}


EntityHandler::~EntityHandler()
{
}

void EntityHandler::UpdateCreatures(EntityContainer& entityContainer_)
{
	for (auto & creature : entityContainer_._entities)
	{
		creature->Update(entityContainer_);
	}
	// TODO huge error
	// first pass creature that is flagged for delete is successfully deleted.
	// good seems to loop from back
	// second pass the deleted creature is referenced again... dangit.
	// crashes program

	// possibly why:
	// maybe the way deqeue works is when there is a pop operation it then moves the first one.

	// better solution, google it.
	entityContainer_._entitiesIt = entityContainer_._entities.begin();
	while (entityContainer_._entitiesIt != entityContainer_._entities.end())
	{
		delete_dead(*entityContainer_._entitiesIt, entityContainer_);

	}

}

void EntityHandler::delete_dead(std::shared_ptr<Creature>& creature_, EntityContainer& entityContainer_)
{
	if (creature_->_deleteMe)
	{

		entityContainer_._entitiesIt = entityContainer_._entities.erase(entityContainer_._entitiesIt);
	}
	else
	{
		entityContainer_._entitiesIt++;
	}
}