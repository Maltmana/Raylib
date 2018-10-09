#pragma once
#include "stdafx.h"
#include "Animation.h"


enum class CreatureGraphicsTypes
{
	Monk,
	Fabio,
	DKnight,
	Wizard,
	Druid,
	Priest
};

enum class FacingDirections
{
	North,
	East,
	South,
	West
};

/* Creature interactions is the point of game. Mainly holds functions and data to carry out those interactions. Secondarily holds visual data that is connected to it. */
class Creature
{
public:
	Creature(Vector2 const & p_pos);
	~Creature();
	// Creature(const Creature& other) = delete; // copy constructor // TODO xmemory error
	// Creature(Creature&& other) = delete; // move constructor // TODO xmemory error
	// Creature & operator=(const Creature & other) = delete; // copy assignment // TODO xmemory error
	// Creature & operator=(Creature&& other) noexcept = delete; // move assignment // TODO xmemory error

public:
	// member functions
	void Update(std::vector<Creature> const & p_creatures);

	void collideSolidly(std::vector<Creature> const & p_creatures); // COLLISION LIB

	void run_waypoints();

	void change_facing(Vector2 const & p_normalizedVector);
	void change_targ(Vector2 p_targPos);

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

};

