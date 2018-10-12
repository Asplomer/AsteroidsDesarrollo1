#include "start.h"
#include "game.h"
#include "raylib.h"
namespace asteroids {

	void UpdateStart() {
		Vector2 aux = { GetMousePosition().x, GetMousePosition().y };
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			if (aux.x > 55 && aux.x < 255 && aux.y >200 && aux.y < 250) {
				gameState = Play;
			}
			if (aux.x > 55 && aux.x < 255 && aux.y >280 && aux.y < 320) {
				gameState = End;
			}
			if (aux.x > 55 && aux.x < 255 && aux.y >360 && aux.y < 400) {
				gameState = Credit;
			}
		}
	}
	void DrawStart() {
		DrawText(FormatText("Asteroids"), 75, 10, 40, DARKGRAY);
		
		DrawRectangle(55, screenHeight - 210, 110, 50, WHITE);
		DrawText(FormatText("Play"), 75, 200, 28, DARKGRAY);

		DrawRectangle(55, screenHeight - 130, 110, 50, WHITE);
		DrawText(FormatText("Exit"), 75, 280, 28, DARKGRAY);

		DrawRectangle(55, screenHeight - 50, 110, 50, WHITE);
		DrawText(FormatText("Credit"), 75, 360, 28, DARKGRAY);

	}
}