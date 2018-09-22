#include "stdafx.h"

#include "Creature.h"
#include "Graphic.h"

// wrap up all the texture loading and crap as an object.
// render background grass as tiles.


int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1000;
	int screenHeight = 800;
	InitWindow(screenWidth, screenHeight, "raylib [textures] examples - texture source and destination rectangles");
	SetTargetFPS(60);
	// NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)

	// Texture loading
	int characterSpritesCol = 18;
	int characterSpritesRow = 8;
	Graphic characterSprites("assets/charsprites.png", characterSpritesCol, characterSpritesRow);
	Graphic grassTile("assets/singleTile.png", 1, 1);

	//--------------------------------------------------------------------------------------

	// variables
	int rotation = 0;
	std::vector<Creature> creatures;
	float dt = 0.f;
	Vector2 targPos = {0,0};
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Input
		//----------------------------------------------------------------------------------

		if (IsMouseButtonPressed(1))
		{
			creatures.emplace_back(GetMousePosition());
		}
		if (IsMouseButtonPressed(0))
		{
			targPos = GetMousePosition();
		}
		// Update
		//----------------------------------------------------------------------------------

		dt += GetFrameTime();
		

		for (auto & creature : creatures)
		{

			creature.UpdateAnimation();
			creature.Update(targPos);
			int typeOffset = (characterSprites.m_frameWidth * 3 * (int)CreatureGraphicsTypes::Druid);
			int frameOffset = ((creature.currentFrame - 1) * characterSprites.m_frameWidth);
			characterSprites.m_sourceRec.x = typeOffset + frameOffset;
			characterSprites.m_sourceRec.y = creature.currentFrameRow * 18;
			characterSprites.destRec.x = creature.m_pos.x;
			characterSprites.destRec.y = creature.m_pos.y;
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
		for (auto const & creature : creatures)
		{
			grassTile.destRec.x * x;
			DrawTexturePro(characterSprites.m_texture, characterSprites.m_sourceRec, characterSprites.destRec, characterSprites.origin, (float)rotation, WHITE);
			DrawTexturePro(grassTile.m_texture, grassTile.m_sourceRec, grassTile.destRec, grassTile.origin, (float)rotation, WHITE);
			x++;
		}



		//
		char buffer[64];
		MyHelperLib::floatToString(buffer, dt);
		//

		DrawText(buffer, screenWidth - 200, screenHeight - 20, 10, GRAY);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
      // Texture unloading

	CloseWindow();                // Close window and OpenGL context
								  //--------------------------------------------------------------------------------------

	return 0;
}