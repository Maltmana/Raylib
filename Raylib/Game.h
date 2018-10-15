#pragma once
// std
// lib
// non-system
#include "stdafx.h"
// system
#include "Creature.h"
#include "CreatureVisualizer.h"
#include "Graphic.h"
#include "Controller.h"

// does everything.
class Game
{
public:
	Game();
	~Game();
	Game(const Game& other) = delete; // copy constructor
	Game(Game&& other) = delete; // move constructor
	Game & operator=(const Game & other) = delete; // copy assignment
	Game & operator=(Game&& other) noexcept = delete; // move assignment
public:
	// game loop
	void loop();
private:
	// run all game world logic
	void Update();
	// draw things from game world
	void Draw();
	void LoadTextures();
public:
private:
	// primitives
	int characterSpritesCol = 18; // TODO MOVE TO FILE
	int characterSpritesRow = 8; // TODO MOVE TO FILE
	//flags
	bool paused = false;
	// objects
	Controller controller;
	std::vector<Creature> creatures;
	std::vector<std::reference_wrapper<Creature>> selectedCreatures;
	CreatureVisualizer cv;
	std::list<Graphic> graphics;




};

