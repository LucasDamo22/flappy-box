/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include <stdio.h>
#include <iostream>

#include <cstdlib>
#include <vector>


#define CANVAS_WIDHT 1280
#define CANVAS_HEIGHT 800

class Pillar {
	public:
		int upperline;
		int lowerline;
		int lifetime;
		int getUpperLine() const { return upperline; }
		int getLowerLine() const { return lowerline; }
		Pillar(int iteration) {
			int gap_size = 60; //pode depender da iteration
			int gap_ini = rand() % (281 - gap_size);
			upperline = 310 + gap_ini;
			lowerline = 310 + gap_ini + gap_size;
			lifetime = 0;
		}
};

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(CANVAS_WIDHT, CANVAS_HEIGHT, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory
	Texture wabbit = LoadTexture("wabbit_alpha.png");

	int iteration = 0;
	int x = 300;
	int pillar_ini = CANVAS_WIDHT - 10;
	int box_position = 450;
	int is_pressed = 0;
	std::vector<Pillar> pillars;

	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		iteration += 1;
		if (iteration % 300 == 0|| iteration == 1) {
			pillars.push_back(Pillar(iteration));
		}
		if (box_position < 580) box_position += 1;
		// binds
		if (IsKeyDown(KEY_UP) && box_position > 340 && is_pressed == 0) box_position -= 20;
		if (IsKeyDown(KEY_UP) && box_position < 341 && is_pressed == 0) box_position = 320;
		if (IsKeyDown(KEY_UP)) is_pressed = 1;
		if (!IsKeyDown(KEY_UP)) is_pressed = 0;

		// drawing
		BeginDrawing();
			for (int i = 0; i < pillars.size(); i += 1) {
				DrawLine(pillar_ini - pillars[i].lifetime, 300, pillar_ini - pillars[i].lifetime, pillars[i].getUpperLine(), BLUE);
				DrawLine(pillar_ini - pillars[i].lifetime, pillars[i].getLowerLine(), pillar_ini - pillars[i].lifetime, 600, BLUE);
				pillars[i].lifetime += 1;
				if (pillars[i].lifetime > 1270) pillars.erase(pillars.begin() + i);
				}
			DrawLine(0, 600, 1280, 600, RED);
			DrawLine(0, 300, 1280, 300, RED);
			DrawEllipse(300, box_position, 20, 20, RED);
			// Setup the back buffer for drawing (clear color and depth buffers)
			ClearBackground(BLACK);

			// draw some text using the default font
			DrawText("Hello Raylib dh872391hudisajn", 200,200,20,WHITE);

			// draw our texture to the screen
			DrawTexture(wabbit, 400, 200, WHITE);
		
			// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();

	}

	// cleanup
	// unload our texture so it can be cleaned up
	UnloadTexture(wabbit);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
