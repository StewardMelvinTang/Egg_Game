#include <iostream>
#include <string>
#include "raylib.h"

//global variables
bool isGameRunning = true;
bool showMainMenu = true;

struct egg
{
	int size = 5;
	float speed = 10.0f;
	bool canMove = true;
	Color color = WHITE;
	Texture2D image;
	    
	void Draw() {

	}
};

int main() {
	//Initialize Game using Raylib
	InitWindow(500, 900, "Crazy Egg");
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(60);
	InitAudioDevice();
	double gameTime = 0.0f;

	//Init Images
	Texture2D score_background = LoadTexture("resources/score_bg.png");
	int score_background_width = 200;
	int score_background_height = 100;
	Rectangle score_background_sourcerec = { 0.0f, 0.0f, (float)score_background_width, (float)score_background_height };

	while (isGameRunning && !WindowShouldClose())
	{
		BeginDrawing();
		gameTime += GetFrameTime();
		//Draw Background
		DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLUE);

		// (IMG) draw Score Background with animation and resized size
		Rectangle score_background_destRec = { (float)GetScreenWidth() / 2 - score_background_width / 2,
			(float)15 - 7.5f * sin(1.5f * gameTime),
			(float)score_background_width, (float)score_background_height };
		DrawTexturePro(score_background, score_background_sourcerec, score_background_destRec, Vector2{ 0,0 }, 0.0f, WHITE);

		//(TXT) draw Score Text
		
		//end draw
		EndDrawing();
	}
	CloseAudioDevice();
	CloseWindow();

	return 0;
}