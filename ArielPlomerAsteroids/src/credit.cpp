#include "credit.h"
#include "game.h"
#include "raylib.h"
namespace asteroids {
	static int verMajor = 1;

	static int verMinor = 1;

	void UpdateCredit() {
	
		Vector2 aux = { GetMousePosition().x, GetMousePosition().y };
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			if (aux.x > 55 && aux.x < 255 && aux.y >280 && aux.y < 320) {
			gameState = Start;
			}
		
		}
	}
	void DrawCredit(){
		DrawText(FormatText("Made by: Ariel Plomer"), 75, 75, 32, WHITE);
		DrawText(FormatText("version: v%i.%i", verMajor, verMinor), 75, 120, 32, WHITE);
		DrawRectangle(55, screenHeight - 130, 110, 50, WHITE);
		DrawText(FormatText("Start"), 75, 280, 32, DARKGRAY);
	
	}



}