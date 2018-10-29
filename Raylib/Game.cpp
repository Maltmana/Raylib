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


	// draws UI stuff like selection rect
	controller.Draw();
	// draw creatures
	_drawHandler.handle_drawing(_entityContainer, _graphicContainer);

	// delete
	float rotation = 0.f;
	// NOTE: Source rectangle (part of the texture to use for drawing)
	Rectangle sourceRec = { 0, 0, 16, 16 };
	// NOTE: Destination rectangle (screen rectangle where drawing part of texture)
	Rectangle destRec = { 100,100, 32, 32};
	// NOTE: Origin of the texture (rotation/scale point), it's relative to destination rectangle size
	Vector2 origin = { 0,0 };

	int typeOffset = (0);
	int frameOffset = (0);

	DrawTexturePro(_graphicContainer.getGraphics().back()->m_texture, sourceRec, destRec, origin, rotation, WHITE);
	// delete


	// Ray
	EndDrawing();
}
// adds some initial textures to graphics
void Game::LoadTextures()
{
	_graphicContainer.getGraphics().emplace_back(std::make_unique<Graphic>(GraphicType::NobleMale, "assets/NobleMale.png", characterSpritesCol, characterSpritesRow));
	_graphicContainer.getGraphics().emplace_back(std::make_unique<Graphic>(GraphicType::EdgeLord, "assets/EdgeLord.png", characterSpritesCol, characterSpritesRow));
	_graphicContainer.getGraphics().emplace_back(std::make_unique<Graphic>(GraphicType::Satyr, "assets/Satyr.png", characterSpritesCol, characterSpritesRow));
	_graphicContainer.getGraphics().emplace_back(std::make_unique<Graphic>(GraphicType::BootsOfSpeed, "assets/BootsOfSpeed.png", 1, 1));
	items.emplace_back();
}
