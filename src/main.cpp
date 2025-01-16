
#include <raylib.h>

#include <stdio.h>
#include <iostream>
#include "pillars.h"
#include <cstdlib>
#include <vector>

#define CANVAS_WIDHT 1280
#define CANVAS_HEIGHT 800

using std::vector;
static Texture2D car_straith = {0};

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	// Create the window and OpenGL context
	InitWindow(CANVAS_WIDHT, CANVAS_HEIGHT, "Hello Raylib");
	car_straith  = LoadTexture("/home/lucasdamo/flappy/SPORT_TOPDOWN/Black/SEPARATED/Black_SPORT_CLEAN_All_047.png");
	int x = 300;
	int box_position = 450;
	int is_pressed = 0;
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
			DrawTexture(car_straith, 250, (box_position-50), WHITE);
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
