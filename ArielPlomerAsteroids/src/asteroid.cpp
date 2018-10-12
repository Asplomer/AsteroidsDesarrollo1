#include "Asteroid.h"

namespace asteroids {
	static Texture2D texture;


	static Asteroide aArray[ARRAYSIZE];




	static Rectangle origin;


	void InitAsteroid(Vector2 a1, Vector2 a2, Vector2 a3) {
		for (int i = 0; i < ARRAYSIZE; i++){
			aArray[i].x = a1.x;
			aArray[i].destroyed = false;
			aArray[i].aRotation = (float)GetRandomValue(0, 360);
			aArray[i].rotation = 0.0f;
			aArray[i].aSpeed = 80.0f;
		}
		aArray[0].x = a1.x;
		aArray[0].y = a1.y;
		aArray[1].x = a2.x;
		aArray[1].y = a2.y;
		aArray[2].x = a3.x;
		aArray[2].y = a3.y;
		
		aArray[0].astRectangle = { 0, 0, 40, 40 };
		aArray[1].astRectangle = { 0, 0, 40, 40 };
		aArray[2].astRectangle = { 0, 0, 40, 40 };
		

		Rectangle origin = { 0.0f, 0.0f, 32.0f, 32.0f };
		texture = LoadTexture("res/Asteroid.png");

	}

	void UpdateAsteroid() {
		for (int i = 0; i < ARRAYSIZE; i++){
			if (!aArray[i].destroyed) {
				
				aArray[i].x += aArray[i].aSpeed * sin(aArray[i].aRotation*DEG2RAD) *GetFrameTime();
				aArray[i].y -= aArray[i].aSpeed * cos(aArray[i].aRotation*DEG2RAD) *GetFrameTime();
				aArray[i].rotation += 100 * GetFrameTime();

			}
			


			if (aArray[i].x > screenWidth - 5.0f) {
				aArray[i].x -= screenWidth + 5.1f;
			}
			else if (aArray[i].x + 5.0f < 0.0f) {
				aArray[i].x += screenWidth + 5.1f;
			}
			if (aArray[i].y > screenHeight - 5.0f) {
				aArray[i].y -= screenHeight + 5.1f;
			}
			else if (aArray[i].y + 5.0f < 0.0f) {
				aArray[i].y += screenHeight + 5.1f;
			}

			
		}
	}


	bool AsteroidColisionRec(Rectangle r) {
		for (int i = 0; i < ARRAYSIZE; i++){
			Rectangle aux = { aArray[i].x, aArray[i].y, aArray[i].astRectangle.width , aArray[i].astRectangle.height };
			if (CheckCollisionRecs(r, aux) && !aArray[i].destroyed) {

				DestroyAsteroid(i);
				
				return true;
			}
		}
		return false;
	}


	void DrawAsteroid() {
		
			Vector2 aux = { 0.0f, 0.0f };
			for (int i = 0; i < ARRAYSIZE; i++) {
				if (!aArray[i].destroyed) {
					aux = { aArray[i].astRectangle.width / 2, aArray[i].astRectangle.height / 2 };
					Rectangle aux2 = { aArray[i].x, aArray[i].y, aArray[i].astRectangle.width , aArray[i].astRectangle.height };
					//DrawTexturePro(texture, origin, aux2, aux, aArray[i].rotation, WHITE);
					DrawTexture(texture, aArray[i].x, aArray[i].y, WHITE);
				}
			}
	}
	void DestroyAsteroid(int i) {
		aArray[i].destroyed = true;
	}
	bool GetDestroyed(int i) {
		return aArray[i].destroyed;
	}
	bool AllDestroyed() {

		if (GetDestroyed(0) && GetDestroyed(1) && GetDestroyed(2)) {
			return true;

		}
		return false;
	}
}