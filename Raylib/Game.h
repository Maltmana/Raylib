#pragma once
#include "stdafx.h"
#include "Creature.h"
#include "CreatureVisualizer.h"
#include "Graphic.h"
#include "Controller.h"
/* Accepts input. Simulates creatures. Presents graphics. */
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
	void Update();
	void Draw();
	void load_textures();
private:

	// controller
	Controller controller;

	// creature container
	std::vector<Creature> creatures;

	// selection system
	std::vector<std::reference_wrapper<Creature>> selectedCreatures;

	//visualizer
	CreatureVisualizer cv;






	// Variables
	int characterSpritesCol = 18; // MOVE TO FILE
	int characterSpritesRow = 8; // MOVE TO FILE
	Graphic characterSprites;
	Graphic grassTile;

	//flags
	bool paused = false;


};

