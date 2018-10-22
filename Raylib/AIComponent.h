#pragma once
#include "Creature.h"
struct AIComponent
{
public:
	AIComponent();
	~AIComponent();
	// flags
	// primitives
	// containers
	// objects
	std::deque<std::weak_ptr<Creature>> m_creatureTargetWayPoints;
	std::deque<Vector2> m_wayPoints;
};

