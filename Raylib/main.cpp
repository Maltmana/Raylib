#include "stdafx.h"
#include "Creature.h"
#include "Graphic.h"
#include "Clock.h"

#include "Window.h"
#include "Game.h"

/* LAYOUT

We want everything to be organized as simple objects interacting.
nothing should be outside of objects.
It should be exactly like a circuit board.

Set Up System

*/

/* TODO

	really need a proper print at
	need a print per second too.

*/

int main()
{
	// create window from file
	Window window;

	// create game from file
	Game game;

	// enter loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		game.Update();
	}

	return 0;
}

