#include "stdafx.h"
#include "Entity.h"

int Entity::statID = 1;
Entity::Entity()
	:
	_id{ statID++ }
{
}
Entity::~Entity()
{
}
