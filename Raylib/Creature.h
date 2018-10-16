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
	void Move();
	void Collision(std::list<Creature> const & p_creatures);
	void collideSolidly(std::list<Creature> const & p_creatures); // COLLISION LIB
	void run_waypoints();
	void change_facing(Vector2 const & p_normalizedVector);
	void change_targ(Vector2 p_targPos);
private:
	void CalculateVectorToTarget();
public:
	// primitives
	Vector2 m_pos;
	Vector2 m_targPos = m_pos;
	Vector2 m_vecToTarg = { 0.f,0.f };
	Vector2 m_vecToTargNorm = { 0.f,0.f };
	Rectangle m_collision = { 0.f,0.f,0.f,0.f };
	// flags
	int m_facing = (int)FacingDirections::South;
	int type = (int)CreatureGraphicsTypes::Druid;
	bool m_collidingLeft = false;
	bool m_collidingRight = false;
	bool m_collidingTop = false;
	bool m_collidingBottom = false;
	// containers
	std::deque<Vector2> m_wayPoints;
	std::string creatureName = "dude";
	// objects
	Animation m_animation;
private:
	int _speed = 100;
};

