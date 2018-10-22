#include "Game.h"

// load sprites, reserve room for creatures.
Game::Game()
	:
	_graphicsSystem(_graphicsContainer)
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
	// Ray
	BeginDrawing();
	ClearBackground(RAYWHITE);
	// Ray


	// draws UI stuff like selection rect
	controller.Draw();
	// draw creatures
	_creatureContainer.DrawCreatures(cv, graphics);

	DrawTextEx(GetFontDefault(), "hey", { 20,20 }, 14, 3, RED);

	// Ray
	EndDrawing();
}
// adds some initial textures to graphics
void Game::LoadTextures()
{
	_graphicsContainer.emplace_back("assets/FemaleSoldier.png", GraphicsTypes::FemaleSoldier, _characterSpriteSizeX, _characterSpriteSizeY);
	_graphicsContainer.emplace_back("assets/MaleBarbarian.png", GraphicsTypes::MaleBarbarian, _characterSpriteSizeX, _characterSpriteSizeY);
	_graphicsContainer.emplace_back("assets/MaleDarkKnight.png", GraphicsTypes::MaleDarkKnight, _characterSpriteSizeX, _characterSpriteSizeY);
	_graphicsContainer.emplace_back("assets/MaleWarrior.png", GraphicsTypes::MaleWarrior, _characterSpriteSizeX, _characterSpriteSizeY);
	_graphicsContainer.emplace_back("assets/BootsOfSpeed.png", GraphicsTypes::BootsOfSpeed, _itemSpriteSizeX, _itemSpriteSizeY);
	_graphicsContainer.emplace_back("assets/ThunderSword.png", GraphicsTypes::ThunderSword, _itemSpriteSizeX, _itemSpriteSizeY);
	Graphics
}
