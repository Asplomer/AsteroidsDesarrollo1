#include <iostream>
#include "Game.h"
#include "Start.h"
#include "Play.h"
namespace asteroids {

	int screenWidth = GetScreenWidth();
	int screenHeight = GetScreenHeight();
	int score1 = 0;
	int gameState = Start;
	
	void PlayGame() {

		InitGame();
		InitShip();
		InitPlay();
		while (!WindowShouldClose() && gameState != End) {
			UpdateGame();
			DrawGame();
		}
	}
	static void UpdateGame() {
		
		switch (gameState) {
		case Start: {
			UpdateStart();
		}break;
		case Play: {
			
			UpdatePlay();

		}break;
		case GameOver: {

		}break;
		case Credit: {


		}break;
		case End: {


		}break;
		}
	}
	static void DrawGame() {
		BeginDrawing();
		ClearBackground(BLACK);
		switch (gameState) {
		case Start: {
			DrawStart();
		}break;
		case Play: {
			
			DrawPlay();

		}break;
		case GameOver: {

		}break;
		case Credit: {


		}break;
		case End: {


		}break;
		}


		EndDrawing();
	}
	static void InitGame() {
		int screenWidth = 800;
		int screenHeight = 450;
		InitWindow(screenWidth, screenHeight, "Asteroids");
		SetExitKey(0);
		int gameState = Start;

		int score = 0;

	}
}