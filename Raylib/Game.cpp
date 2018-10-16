#include "Game.h"

// load sprites, reserve room for creatures.
Game::Game()
{
	LoadTextures();
}

Game::~Game()
{
}

void Game::loop()
{
	while (!WindowShouldClose())
	{
		Update();
		Draw();
	}
}

void Game::Update()
{

	controller.Update(paused, creatures, selectedCreatures);

	for (auto & creature : creatures)
	{

		creature.Update(creatures);

	}


}

void Game::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	// draw selection rect
	DrawRectangleLinesEx(controller.selectionRect, 2, GREEN);

	// draw creatures
	for (auto const & creature : creatures)
	{
		cv.visualize(creature, graphics.front());
	}



	EndDrawing();
}
// adds some initial textures to graphics
void Game::LoadTextures()
{
	graphics.emplace_back("assets/charsprites.png", characterSpritesCol, characterSpritesRow);
	graphics.emplace_back("assets/singleTile.png", 1, 1);
}
