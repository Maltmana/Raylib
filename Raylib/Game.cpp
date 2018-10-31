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
	controller.Update(paused, _entityContainer);
	_entityHandler.UpdateCreatures(_entityContainer);
}

void Game::Draw()
{
	// Ray
	BeginDrawing();
	ClearBackground(RAYWHITE);
	// Ray

	// Mine
	// draws UI stuff like selection rect
	controller.Draw();
	// draw creatures
	_drawHandler.handle_drawing(_entityContainer, _graphicContainer);
	// Mine

	// Ray
	EndDrawing();
	// Ray
}
// adds some initial textures to graphics
void Game::LoadTextures()
{
	_graphicContainer.getGraphics().emplace_back(std::make_unique<Graphic>(GraphicType::NobleMale, "assets/NobleMale.png", characterSpritesCol, characterSpritesRow));
	_graphicContainer.getGraphics().emplace_back(std::make_unique<Graphic>(GraphicType::EdgeLord, "assets/EdgeLord.png", characterSpritesCol, characterSpritesRow));
	_graphicContainer.getGraphics().emplace_back(std::make_unique<Graphic>(GraphicType::Satyr, "assets/Satyr.png", characterSpritesCol, characterSpritesRow));
	items.emplace_back();
}
