#pragma once
// std
// libs
// non-sys
// sys
#include "ComponentContainer.h"
class Entity
{
public:
	Entity(); /*!< Sets _id to statID and increments statID */
	~Entity();
public:
private:
public:
	// primitives
	int _id;
	// objects
	ComponentContainer _componentContainer;
private:
	static int statID;
};

