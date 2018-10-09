#pragma once
#include "stdafx.h"
#include "Creature.h"
#include "Graphic.h"
#include "Clock.h"

class Game
{
public:
	Game();
	~Game();

	void Update();

private:
	void load_textures()
	{

		
		
	}

	// creature container
	std::vector<Creature> creatures;

	// selection system
	std::vector<std::reference_wrapper<Creature>> selectedCreatures;

	Vector2 mouseDownPosition = { 0,0 };

	Rectangle selectionRect = { 0,0,0,0 };




	// Variables
	int characterSpritesCol = 18;
	int characterSpritesRow = 8;
	Graphic characterSprites;
	Graphic grassTile;

	//flags
	bool paused = false;

	// clock
	Clock clock;


};

// TODO load params from file
