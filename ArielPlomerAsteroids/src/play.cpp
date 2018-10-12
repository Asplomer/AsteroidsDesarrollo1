#include "play.h"
namespace asteroids {


	static Vector2 a1 = { 380, 50};
	static Vector2 a2 = { 550, 300 };
	static Vector2 a3 = { 200, 300 };
	
	
	int BASESPEED = 80;

	static float rotation = 0.0f;


	
	static bool paused = false;

	void InitPlay() {

		InitAsteroid(a1, a2, a3);
	}
	void UpdatePlay() {
		if (IsKeyPressed(KEY_SPACE)) {
			if (paused == false)paused = true;
			else paused = false;
		}
		if (!paused){
			InputShip();
			AsteroidColisionRec(GetRect());
			UpdateAsteroid();
			UpdateBullet(GetShip(), GetRotation());
		}
		else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			Vector2 aux = { GetMousePosition().x, GetMousePosition().y };
			if (aux.x > 250 && aux.x < 360 && aux.y >200 && aux.y < 250) {
				paused = false;
			}
			if (aux.x > 250 && aux.x < 360 && aux.y >230 && aux.y < 280) {
				gameState = Start;
				
			}
		
		}



		if (AsteroidColisionRec(GetShip()) || (AllDestroyed())) {
			gameState = End;
			UnloadShip();
		}

		

	}
	void DrawPlay() {

		DrawBullet();
		DrawShip(0.0f);
		DrawAsteroid();
		if (paused) {
			DrawText(FormatText("Paused"), 250, 200, 32, DARKGRAY);
			DrawText(FormatText("Menu"), 250, 230, 32, DARKGRAY);
		}
	}

}