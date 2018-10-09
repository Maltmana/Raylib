#include "Game.h"


Game::Game()
	:
	characterSprites("assets/charsprites.png", characterSpritesCol, characterSpritesRow),
	grassTile("assets/singleTile.png", 1, 1)
{
	creatures.reserve(1000); // TODO THIS WILL BUG OUT IF GOES PAST RESERVE CAUSE Iterator invalidation rules
	selectedCreatures.reserve(1000); // TODO THIS WILL BUG OUT IF GOES PAST RESERVE CAUSE Iterator invalidation rules
}

Game::~Game()
{
}

void Game::Update()
{

	controller.update(paused, creatures, selectedCreatures);

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
		cv.visualize(creature, characterSprites);
	}



	EndDrawing();
}

void Game::load_textures()
{

}
