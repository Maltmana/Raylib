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
#include "CreatureContainer.h"
#include "Item.h"
#include "GraphicsSystem.h"

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
	int _characterSpriteSizeX = 16; // TODO MOVE TO FILE
	int _characterSpriteSizeY = 18; // TODO MOVE TO FILE
	int _itemSpriteSizeX = 16; // TODO MOVE TO FILE
	int _itemSpriteSizeY = 16; // TODO MOVE TO FILE
	// flags
	bool paused = false;
	// containers
	std::list<std::weak_ptr<Creature>> _selectedCreatures;
	std::list<std::shared_ptr<std::vector<Item>>> _items;
	std::vector<std::unique_ptr<Graphic>> _graphicsContainer;
	// objects
	Controller controller;
	CreatureContainer _creatureContainer;
	CreatureVisualizer cv;

	// systems
	GraphicsSystem _graphicsSystem;






};

