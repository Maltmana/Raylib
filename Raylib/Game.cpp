#include "Game.h"

bool Game::paused = false;

// load sprites, reserve room for creatures.
Game::Game()
	:
	_graphicsSystem(_graphicsContainer)
{
	LoadTextures();
	MakeTestEntities();
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
	for (auto entity : _entityContainer)
	{
		if (entity->_physicalComponent != nullptr && entity->_animationComponent != nullptr)
		{
			_animationSystem.UpdateAnimation(*entity->_animationComponent.get(), entity->_physicalComponent->_facing);
		}
	}

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
		if (entity->_graphicsComponent != nullptr && entity->_physicalComponent != nullptr && entity->_animationComponent != nullptr)
		{
			_graphicsSystem.draw(*entity->_graphicsComponent,
				*entity->_physicalComponent,
				*entity->_animationComponent);
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
	_graphicsContainer.emplace_back(std::make_unique<Graphic>("assets/FemaleCaveman.png", GraphicsTypes::FemaleCaveman, _characterSpriteSizeX, _characterSpriteSizeY));
	_graphicsContainer.emplace_back(std::make_unique<Graphic>("assets/FemaleNoble.png", GraphicsTypes::FemaleNoble, _characterSpriteSizeX, _characterSpriteSizeY));
	_graphicsContainer.emplace_back(std::make_unique<Graphic>("assets/MaleNoble.png", GraphicsTypes::MaleNoble, _characterSpriteSizeX, _characterSpriteSizeY));
	_graphicsContainer.emplace_back(std::make_unique<Graphic>("assets/BootsOfSpeed.png", GraphicsTypes::BootsOfSpeed, _itemSpriteSizeX, _itemSpriteSizeY));
	_graphicsContainer.emplace_back(std::make_unique<Graphic>("assets/ThunderSword.png", GraphicsTypes::ThunderSword, _itemSpriteSizeX, _itemSpriteSizeY));
}

void Game::MakeTestEntities()
{
	_entityContainer.emplace_back(std::make_unique<Entity>());
	std::cout << "making test entity #: " << _entityContainer.back()->_id << '\n';
	_entityContainer.emplace_back(std::make_unique<Entity>(std::make_unique<PhysicalComponent>(Vector2{ 200.f,500.f }), std::make_unique<GraphicsComponent>(GraphicsTypes::MaleDarkKnight), std::make_unique<AnimationComponent>()));
	std::cout << "making test entity #: " << _entityContainer.back()->_id << '\n';
	_entityContainer.emplace_back(std::make_unique<Entity>(std::make_unique<PhysicalComponent>(Vector2{ 300.f,400.f }), std::make_unique<GraphicsComponent>(GraphicsTypes::FemaleSoldier), std::make_unique<AnimationComponent>()));
	std::cout << "making test entity #: " << _entityContainer.back()->_id << '\n';
	_entityContainer.emplace_back(std::make_unique<Entity>(std::make_unique<PhysicalComponent>(Vector2{ 400.f,300.f }), std::make_unique<GraphicsComponent>(GraphicsTypes::MaleBarbarian), std::make_unique<AnimationComponent>()));
	std::cout << "making test entity #: " << _entityContainer.back()->_id << '\n';
	_entityContainer.emplace_back(std::make_unique<Entity>(std::make_unique<PhysicalComponent>(Vector2{ 500.f,200.f }), std::make_unique<GraphicsComponent>(GraphicsTypes::MaleNoble), std::make_unique<AnimationComponent>()));
	std::cout << "making test entity #: " << _entityContainer.back()->_id << '\n';
	_entityContainer.emplace_back(std::make_unique<Entity>(std::make_unique<PhysicalComponent>(Vector2{ 600.f,200.f }), std::make_unique<GraphicsComponent>(GraphicsTypes::FemaleCaveman), std::make_unique<AnimationComponent>()));
	std::cout << "making test entity #: " << _entityContainer.back()->_id << '\n';
	_entityContainer.emplace_back(std::make_unique<Entity>(std::make_unique<PhysicalComponent>(Vector2{ 100.f,100.f }), std::make_unique<GraphicsComponent>(GraphicsTypes::FemaleNoble), std::make_unique<AnimationComponent>()));
	std::cout << "making test entity #: " << _entityContainer.back()->_id << '\n';
}
