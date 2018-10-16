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
	controller.Update(paused, _creatureContainer._creatures, selectedCreatures);
	_creatureContainer.UpdateCreatures();

}

void Game::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	// draw selection rect
	DrawRectangleLinesEx(controller.selectionRect, 2, GREEN);

	// draw creatures
	_creatureContainer.DrawCreatures(cv, graphics);



	EndDrawing();
}
// adds some initial textures to graphics
void Game::LoadTextures()
{
	graphics.emplace_back("assets/charsprites.png", characterSpritesCol, characterSpritesRow);
	graphics.emplace_back("assets/singleTile.png", 1, 1);
}
