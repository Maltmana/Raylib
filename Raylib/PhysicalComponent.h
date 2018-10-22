#pragma once
// std
// libs
// non-sys
#include "enums.h"
// sys

struct PhysicalComponent
{
	PhysicalComponent(Vector2 position_, Vector2 velocity_ = { 0.f,0.f }, float speed_ = {0.f});
	~PhysicalComponent();
	// NO FUNCTIONS
	// movement
	Vector2 _position;
	Vector2 _velocity;
	float _speed;
	// movement temporary stuff
	Vector2 m_targPos = _position;
	Vector2 m_vecToTarg = { 0.f,0.f };
	Vector2 m_vecToTargNorm = { 0.f,0.f };
	Vector2 m_newPos = { 0.f,0.f };
	// direction
	int m_facing = (int)FacingDirections::South;
	// collision
	float m_collisionRadius = { 5.f };
};

