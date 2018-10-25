#pragma once
// std
// libs
// nonsys
// sys
#include "PhysicalComponent.h"

// updates location and facing and collision
// takes in a target vector then changes the physics component based on it if the collision checks work out ok.
class PhysicsSystem
{  
public:
	PhysicsSystem();
	~PhysicsSystem();
public:
	void Update(Vector2 const & targetVector_, PhysicalComponent & physicalComponent_, std::vector<std::shared_ptr<PhysicalComponent>> const & allPhysicsComponents_);
	void start_move_process();
	void Move();
	void calculate_move();
	bool is_colliding();
	void change_facing();
	void CalculateVectorToTarget();

	//// cached reference
	//PhysicalComponent * _physicalComponent;
	//std::vector<std::shared_ptr<PhysicalComponent>> const & _allPhysicsComponents;
};

