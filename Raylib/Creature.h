#pragma once
// std
// lib
// non-system
#include "stdafx.h"
#include "Enums.h"
// system
#include "Animation.h"

class Creature
{
public:
	Creature(Vector2 const & p_pos);
	~Creature();
public:
	void Update(std::list<Creature> const & p_creatures);
	void start_move_process(std::list<Creature> const & p_creatures);
	void Move();
	void calculate_move();
	bool is_colliding(std::list<Creature> const & p_creatures);
	void run_waypoints();
	void change_facing(Vector2 const & p_normalizedVector);
	void change_targ(Vector2 p_targPos);
private:
	void CalculateVectorToTarget();
public:
	// primitives
	float m_collisionRadius = {5.f};
	// structs
	Vector2 m_pos;
	Vector2 m_targPos = m_pos;
	Vector2 m_vecToTarg = { 0.f,0.f };
	Vector2 m_vecToTargNorm = { 0.f,0.f };
	Vector2 m_newPos = { 0.f,0.f };
	// flags
	int m_facing = (int)FacingDirections::South;
	int type = (int)CreatureGraphicsTypes::Druid;
	// containers
	std::deque<Vector2> m_wayPoints;
	std::string creatureName = "dude";
	// objects
	Animation m_animation;
private:
	int _speed = 100;
};

