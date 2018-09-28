#include "Start.h"
#include "Game.h"
#include "raylib.h"
namespace Asteroids {

	void UpdateStart() {
		if (IsKeyPressed(KEY_ENTER)) gameState = Play;
		if (IsKeyPressed(KEY_BACKSPACE)) gameState = End;
		//if (IsKeyPressed(KEY_SPACE)) gameState = Credit;
	}

	void DrawStart() {
		DrawText(FormatText("Asteroids"), screenWidth / 2 - 75, 10, 40, DARKGRAY);
		DrawText(FormatText("Press Start to play, press Backspace to exit"), 75, screenHeight / 2, 18, DARKGRAY);
	}
}