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

	// Basic Input
	//----------------------------------------------------------------------------------

	if (IsKeyReleased(284))
	{
		if (paused == false)
		{
			paused = true;
		}
		else
		{
			paused = false;
		}
	}

	if (!paused)
	{
		if (IsKeyReleased(KEY_SPACE))
		{
			creatures.emplace_back(GetMousePosition());
		}

		if (IsMouseButtonPressed(0))
		{
			mouseDownPosition = GetMousePosition();
		}

	}

	// if button is pressed mess with selection rect.
	if (IsMouseButtonDown(0))
	{
		int mouseY = (int)GetMouseY();

		if ((float)GetMouseX() - mouseDownPosition.x <= 0 && (float)GetMouseY() - mouseDownPosition.y <= 0)
		{
			selectionRect = { (float)GetMouseX(), (float)GetMouseY(), mouseDownPosition.x - (float)GetMouseX(),mouseDownPosition.y - (float)GetMouseY() };
		}
		else if ((float)GetMouseY() - mouseDownPosition.y <= 0)
		{
			selectionRect = { mouseDownPosition.x, (float)GetMouseY(), (float)GetMouseX() - mouseDownPosition.x, mouseDownPosition.y - (float)GetMouseY() };
		}
		else if ((float)GetMouseX() - mouseDownPosition.x <= 0)
		{
			selectionRect = { (float)GetMouseX(), mouseDownPosition.y, mouseDownPosition.x - (float)GetMouseX(),(float)GetMouseY() - mouseDownPosition.y };
		}
		else
		{
			selectionRect = { mouseDownPosition.x, mouseDownPosition.y,(float)GetMouseX() - mouseDownPosition.x,(float)GetMouseY() - mouseDownPosition.y };
		}
	}

	if (IsMouseButtonReleased(0) && !paused)
	{
		mouseDownPosition = { 0,0 };
	}


	// Update
	//----------------------------------------------------------------------------------

	if (!paused)
	{
		for (Creature & selected : selectedCreatures)
		{
			Rectangle destRec = { selected.m_pos.x, selected.m_pos.y,characterSprites.m_frameWidth, characterSprites.m_frameHeight };
			DrawRectangleLinesEx(destRec, 2, GREEN);
			if (IsMouseButtonReleased(1))
			{
				selected.change_targ(GetMousePosition());
			}
			if (IsMouseButtonReleased(1) && IsKeyDown(KEY_LEFT_SHIFT))
			{
				selected.m_wayPoints.push_back(GetMousePosition());
			}


		}
	}




	for (auto & creature : creatures)
	{

		creature.Update(creatures);
	}

	if (IsMouseButtonReleased(0))
	{
		selectedCreatures.clear();
		for (auto & creature : creatures)
		{
			if (IsMouseButtonReleased(0) && CheckCollisionRecs(creature.m_collision, selectionRect))
			{
				// dont add them until you release the box.
				selectedCreatures.push_back(creature);
			}
		}
	}

	if (!IsMouseButtonDown(0))
	{
		selectionRect = { 0,0,0,0 };
	}
}

void Game::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	// draw selection rect
	DrawRectangleLinesEx(selectionRect, 2, GREEN);

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
