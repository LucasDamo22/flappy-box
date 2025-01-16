/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include <raylib.h>



#include <stdio.h>
#include <iostream>
#include "pillars.h"
#include <cstdlib>
#include <vector>


#define CANVAS_WIDHT 1280
#define CANVAS_HEIGHT 800

using std::vector;

void generate_pillar(int iteration) {
	int gap_ini = rand() % 101;
	//int gap_size = x;
	DrawLine(CANVAS_WIDHT - 10, 300, CANVAS_WIDHT - 10, 400, BLUE);
	DrawLine(CANVAS_WIDHT - 10, 500, CANVAS_WIDHT - 10, 600, BLUE);
}

class Pillar {
	public:
		int upperline;
		int lowerline;
};

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(CANVAS_WIDHT, CANVAS_HEIGHT, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	

	// Load a texture from the resources directory
	

	int x = 300;
	int box_position = 450;
	int is_pressed = 0;
	vector<Pillar> list;

	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		if (box_position < 580) box_position += 1;
		// binds
		if (IsKeyDown(KEY_UP) && box_position > 340 && is_pressed == 0) box_position -= 30;
		if (IsKeyDown(KEY_UP) && box_position < 341 && is_pressed == 0) box_position = 320;
		if (IsKeyDown(KEY_UP)) is_pressed = 1;
		if (!IsKeyDown(KEY_UP)) is_pressed = 0;
		// drawing
		BeginDrawing();
		
			DrawLine(x,300,x,400,BLUE);
			DrawLine(x,500,x,600,BLUE);
			DrawLine(0, 600, 1280, 600, RED);
			DrawLine(0, 300, 1280, 300, RED);
			DrawEllipse(300, box_position, 20, 20, RED);
            draw_max();
			// Setup the back buffer for drawing (clear color and depth buffers)
			ClearBackground(BLACK);

			// draw some text using the default font
			DrawText("Hello Raylib dh872391hudisajn", 200,200,20,WHITE);

			// draw our texture to the screen
			
		
			// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();

	}

	// cleanup
	// unload our texture so it can be cleaned up
	

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
