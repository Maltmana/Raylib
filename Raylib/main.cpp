#include "stdafx.h"
#include "Creature.h"
#include "Graphic.h"

// really need a proper print at
// need a print per second too.

void init_window(int p_screenWidth, int p_screenHeight)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	InitWindow(p_screenWidth, p_screenHeight, "ARENA");
	SetTargetFPS(60);
	// NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
}



int main()
{
	//-----------------------------------------------------
	// Pre Crap
	//-----------------------------------------------------

	// window init
	int screenWidth = 1000;
	int screenHeight = 800;
	init_window(screenWidth, screenHeight);

	// Texture loading
	int characterSpritesCol = 18;
	int characterSpritesRow = 8;
	Graphic characterSprites("assets/charsprites.png", characterSpritesCol, characterSpritesRow);
	Graphic grassTile("assets/singleTile.png", 1, 1);

	//-----------------------------------------------------
	// Vars for the Loop
	//-----------------------------------------------------

	// creature container
	std::vector<Creature> creatures;


	// selection system
	std::vector<std::reference_wrapper<Creature>> selectedCreatures;

	Vector2 mouseDownPosition = { 0,0 };

	Rectangle selectionRect = { 0,0,0,0 };


	//-----------------------------------------------------
	// Main Loop
	//-----------------------------------------------------

	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Basic Input
		//----------------------------------------------------------------------------------

		if (IsMouseButtonPressed(1))
		{
			creatures.emplace_back(GetMousePosition());
		}

		if (IsMouseButtonPressed(0))
		{
			mouseDownPosition = GetMousePosition();
		}
		if (IsMouseButtonDown(0))
		{
			int mouseY = (int)GetMouseY();

			if ((float)GetMouseX() - mouseDownPosition.x <= 0 && (float)GetMouseY() - mouseDownPosition.y <= 0)
			{
				selectionRect = { (float)GetMouseX(), (float)GetMouseY(), mouseDownPosition.x - (float)GetMouseX(),mouseDownPosition.y - (float)GetMouseY() };
			}
			else if ((float)GetMouseY() - mouseDownPosition.y <= 0)
			{
				selectionRect = { mouseDownPosition.x, (float)GetMouseY(), (float)GetMouseX() -mouseDownPosition.x, mouseDownPosition.y -(float)GetMouseY()};
			}
			else if ((float)GetMouseX() - mouseDownPosition.x <= 0)
			{
				selectionRect = { (float)GetMouseX(), mouseDownPosition.y, mouseDownPosition.x - (float)GetMouseX(),(float)GetMouseY() - mouseDownPosition.y };
			}
			else
			{
				selectionRect = { mouseDownPosition.x, mouseDownPosition.y,(float)GetMouseX() - mouseDownPosition.x,(float)GetMouseY() - mouseDownPosition.y };
			}
			

			DrawRectangleLinesEx(selectionRect, 2, GREEN);
		}

		if (IsMouseButtonReleased(0))
		{
			mouseDownPosition = { 0,0 };
		}


		// Update
		//----------------------------------------------------------------------------------


		for (auto & selected : selectedCreatures)
		{
			Rectangle destRec = { selected.get().m_pos.x - 16, selected.get().m_pos.y - 18,characterSprites.m_frameWidth, characterSprites.m_frameHeight };
			DrawRectangleLinesEx(destRec, 2, GREEN);
			if (IsMouseButtonReleased(0))
			{
				selected.get().change_targ(GetMousePosition()); // TODO this throws read access violation
			}
		}
		

		for (auto & creature : creatures)
		{

			creature.UpdateAnimation();
			creature.Update();
			int typeOffset = (characterSprites.m_frameWidth * 3 * (int)CreatureGraphicsTypes::Druid);
			int frameOffset = ((creature.currentFrame - 1) * characterSprites.m_frameWidth);
			characterSprites.m_sourceRec.x = typeOffset + frameOffset;
			characterSprites.m_sourceRec.y = creature.currentFrameRow * 18;
			characterSprites.destRec.x = creature.m_pos.x;
			characterSprites.destRec.y = creature.m_pos.y;

		}

		if (IsMouseButtonReleased(0))
		{
			bool first = true;
			for (auto & creature : creatures)
			{
				if (IsMouseButtonReleased(0) && CheckCollisionRecs(creature.m_collision, selectionRect))
				{
					if (first)
					{
						selectedCreatures.empty();
						first = false;
					}
					// dont add them until you release the box.
					selectedCreatures.push_back(creature);
				}
			}
		}

		if(!IsMouseButtonDown(0))
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
			DrawRectangleLinesEx(creature.m_collision,1,RED);
		}
		EndDrawing();
	}

	//-----------------------------------------------------
	// De-Init
	//-----------------------------------------------------

	CloseWindow();

	return 0;
}

