#pragma once
// std
// lib
// non-system
#include "stdafx.h"
// system
#include "Entity.h"
#include "Graphic.h"
// systems
#include "GraphicsSystem.h"
#include "PhysicsSystem.h"
#include "AISystem.h"
#include "CombatSystem.h"
#include "AnimationSystem.h"
#include "Entity.h"

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
	void DrawProcess();
	void Draw();
	void LoadTextures();
	void MakeTestEntities();
public:
	// static
	static bool paused;
private:
	// primitives
	int _characterSpriteSizeX = 16; // TODO MOVE TO FILE
	int _characterSpriteSizeY = 18; // TODO MOVE TO FILE
	int _itemSpriteSizeX = 16; // TODO MOVE TO FILE
	int _itemSpriteSizeY = 16; // TODO MOVE TO FILE
	// flags

	// graphics
	std::vector<std::unique_ptr<Graphic>> _graphicsContainer;
	// Entities
	std::vector<std::shared_ptr<Entity>> _entityContainer;
	// Components
	// Systems
	GraphicsSystem _graphicsSystem;
	PhysicsSystem _physicsSystem;
	AISystem _aiSystem;
	CombatSystem _combatSystem;
	AnimationSystem _animationSystem;






};

