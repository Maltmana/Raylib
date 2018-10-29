#pragma once
#include "Creature.h"
#include "EntityContainer.h"
class EntityHandler
{
public:
	EntityHandler();
	~EntityHandler();
public:
	void UpdateCreatures(EntityContainer& entityContainer_);
	void delete_dead(std::shared_ptr<Creature> & creature_, EntityContainer& entityContainer_);
private:
public:
private:
};

