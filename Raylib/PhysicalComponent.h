#pragma once
// std
// libs
// non-sys
#include "enums.h"
// sys

struct PhysicalComponent
{
	PhysicalComponent(Vector2 position_ = { 0.f,0.f }, Vector2 velocity_ = { 0.f,0.f }, float speed_ = { 0.f });
	~PhysicalComponent();
	// NO FUNCTIONS
	// movement
	Vector2 _position;
	Vector2 _velocity;
	float _speed;
	// movement temporary stuff
	Vector2 _targPos = _position;
	Vector2 _vecToTarg = { 0.f,0.f };
	Vector2 _vecToTargNorm = { 0.f,0.f };
	Vector2 _newPos = { 0.f,0.f };
	// direction
	FacingDirections _facing = FacingDirections::South;
	// collision
	float _collisionRadius = { 5.f };
};

