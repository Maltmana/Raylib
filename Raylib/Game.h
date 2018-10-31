#pragma once
// std
// lib
// non-system
#include "stdafx.h"
// system
#include "Creature.h"
#include "Graphic.h"
#include "Controller.h"
#include "EntityContainer.h"
#include "Item.h"
#include "GraphicContainer.h"
#include "DrawHandler.h"
#include "Enums.h"
#include "EntityHandler.h"


/*
MAIN TODO
gut out the creature class into components and an entity class.
make handlers.
plot out uml
wrap up all your libraries and raylib.
be able to pick up and drop items and get effects from them.
learn an hour a day
*/

// containers of creatures interact and then containers of graphics used to draw them
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
	int characterSpritesCol = 3; // TODO MOVE TO FILE
	int characterSpritesRow = 4; // TODO MOVE TO FILE
	// flags
	bool paused = false;
	// containers
	std::list<std::shared_ptr<std::vector<Item>>> items;
	GraphicContainer _graphicContainer;
	// objects
	Controller controller;
	EntityContainer _entityContainer;

	// handlers
	DrawHandler _drawHandler;
	EntityHandler _entityHandler;






};

