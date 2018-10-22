#include "Game.h"

bool Game::paused = false;

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
		DrawProcess();
	}
}

void Game::Update()
{
}

void Game::DrawProcess()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	Draw();
	EndDrawing();
}

void Game::Draw()
{
	for (auto entity : _entityContainer)
	{
		if (&entity->_componentContainer._graphicsComponent != nullptr)
		{
			_graphicsSystem.draw(*entity->_componentContainer._graphicsComponent,
				*entity->_componentContainer._physicalComponent,
				*entity->_componentContainer._animationComponent);
		}
	}
	//DrawTextEx(GetFontDefault(), "hey", { 20,20 }, 14, 3, RED);
}
// adds some initial textures to graphics
void Game::LoadTextures()
{
	_graphicsContainer.emplace_back(std::make_unique<Graphic>("assets/FemaleSoldier.png", GraphicsTypes::FemaleSoldier, _characterSpriteSizeX, _characterSpriteSizeY));
	_graphicsContainer.emplace_back(std::make_unique<Graphic>("assets/MaleBarbarian.png", GraphicsTypes::MaleBarbarian, _characterSpriteSizeX, _characterSpriteSizeY));
	_graphicsContainer.emplace_back(std::make_unique<Graphic>("assets/MaleDarkKnight.png", GraphicsTypes::MaleDarkKnight, _characterSpriteSizeX, _characterSpriteSizeY));
	_graphicsContainer.emplace_back(std::make_unique<Graphic>("assets/MaleWarrior.png", GraphicsTypes::MaleWarrior, _characterSpriteSizeX, _characterSpriteSizeY));
	_graphicsContainer.emplace_back(std::make_unique<Graphic>("assets/BootsOfSpeed.png", GraphicsTypes::BootsOfSpeed, _itemSpriteSizeX, _itemSpriteSizeY));
	_graphicsContainer.emplace_back(std::make_unique<Graphic>("assets/ThunderSword.png", GraphicsTypes::ThunderSword, _itemSpriteSizeX, _itemSpriteSizeY));
}
