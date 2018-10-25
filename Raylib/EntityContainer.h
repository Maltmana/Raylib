#pragma once
#include "Entity.h"
class EntityContainer
{
public:
	EntityContainer();
	~EntityContainer();
public:
	bool Add(std::unique_ptr<Entity> entity_);
private:
public:
private:
	std::vector<std::shared_ptr<Entity>> _entityContainer;
};

