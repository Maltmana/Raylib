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
	CloseWindow();
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

			if (clock.returnTrueEvery(1.f))
			{
				std::cout << &selected;
				puts("");
			}

		}
	}




	for (auto & creature : creatures)
	{

		creature.UpdateAnimation();
		creature.Update(creatures);
		int typeOffset = (characterSprites.m_frameWidth * 3 * (int)CreatureGraphicsTypes::Druid);
		int frameOffset = ((creature.currentFrame - 1) * characterSprites.m_frameWidth);
		characterSprites.m_sourceRec.x = typeOffset + frameOffset;
		characterSprites.m_sourceRec.y = creature.currentFrameRow * 18;
		characterSprites.destRec.x = creature.m_pos.x;
		characterSprites.destRec.y = creature.m_pos.y;

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

	// Draw
	//----------------------------------------------------------------------------------

	BeginDrawing();

	ClearBackground(RAYWHITE);

	// NOTE: Using DrawTexturePro() we can easily rotate and scale the part of the texture we draw
	// sourceRec defines the part of the texture we use for drawing
	// destRec defines the rectangle where our texture part will fit (scaling it to fit)
	// origin defines the point of the texture used as reference for rotation and scaling
	// rotation defines the texture rotation (using origin as rotation point)

	// draw selection rect
	DrawRectangleLinesEx(selectionRect, 2, GREEN);

	// draw creatures
	int x = 0;
	int rotation = 0;
	for (auto const & creature : creatures)
	{
		Rectangle destRec = { creature.m_pos.x, creature.m_pos.y,characterSprites.m_frameWidth, characterSprites.m_frameHeight };
		grassTile.destRec.x * x;
		DrawTexturePro(characterSprites.m_texture, characterSprites.m_sourceRec, destRec, characterSprites.origin, (float)rotation, WHITE);
		DrawTexturePro(grassTile.m_texture, grassTile.m_sourceRec, grassTile.destRec, grassTile.origin, (float)rotation, WHITE);
		x++;

		// draw collision box
		DrawRectangleLinesEx(creature.m_collision, 1, RED);
	}



	EndDrawing();

}