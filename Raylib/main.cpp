#include "stdafx.h"

#include "Creature.h"

// wrap up all the texture loading and crap as an object.
// render background grass as tiles.


int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1000;
	int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "raylib [textures] examples - texture source and destination rectangles");

	// NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)

	// Texture loading
	Texture2D charsprites = LoadTexture("assets/charsprites.png");
	Texture2D groundTiles = LoadTexture("assets/ground_tiles.png");

	int frameWidth = charsprites.width / 18;
	int frameHeight = charsprites.height / 8;

	// NOTE: Source rectangle (part of the texture to use for drawing)
	Rectangle sourceRec = { 0, 0, (float)frameWidth, (float)frameHeight };

	// NOTE: Destination rectangle (screen rectangle where drawing part of texture)
	Rectangle destRec = { (float)screenWidth / 2, (float)screenHeight / 2, (float)frameWidth * 2, (float)frameHeight * 2 };

	// NOTE: Origin of the texture (rotation/scale point), it's relative to destination rectangle size
	Vector2 origin = { (float)frameWidth, (float)frameHeight };

	SetTargetFPS(60);
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
			int typeOffset = (frameWidth * 3 * (int)CreatureGraphicsTypes::Druid);
			int frameOffset = ((creature.currentFrame - 1) * frameWidth);
			sourceRec.x = typeOffset + frameOffset, 0;
			sourceRec.y = creature.currentFrameRow * 18;
			creature.UpdateAnimation();
			creature.Update(targPos);
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
		for (auto const & creature : creatures)
		{
			destRec.x = creature.m_pos.x;
			destRec.y = creature.m_pos.y;
			DrawTexturePro(charsprites, sourceRec, destRec, origin, (float)rotation, WHITE);
		}


		DrawLine((int)destRec.x, 0, (int)destRec.x, screenHeight, GRAY);
		DrawLine(0, (int)destRec.y, screenWidth, (int)destRec.y, GRAY);

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
	UnloadTexture(charsprites);        // Texture unloading

	CloseWindow();                // Close window and OpenGL context
								  //--------------------------------------------------------------------------------------

	return 0;
}