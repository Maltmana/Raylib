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
	// member functions
	void Update(std::list<Creature> const & p_creatures);

	void collideSolidly(std::list<Creature> const & p_creatures); // COLLISION LIB

	void run_waypoints();

	void change_facing(Vector2 const & p_normalizedVector);
	void change_targ(Vector2 p_targPos);
private:
	// member variables
public:
	Vector2 m_pos;
	Rectangle m_collision = { 0,0,0,0};
	Vector2 m_targPos;
	std::deque<Vector2> m_wayPoints;
	int m_facing = (int)FacingDirections::South;

	int type = (int)CreatureGraphicsTypes::Druid;

	Animation m_animation;

	std::string creatureName = "dude";

	bool m_collidingLeft = false;
	bool m_collidingRight = false;
	bool m_collidingTop = false;
	bool m_collidingBottom = false;
private:

};

