#include "Asteroid.h"
#include "Game.h"
namespace asteroids {
	static Texture2D texture;
	
	/*static float rotation;
	static Rectangle origin = { 0.0f, 0.0f, 32.0f, 32.0f };
	static bool destroyed;
	static float aRotation;
	float aSpeed= 0.0f;*/

	Asteroid InitAsteroid(float posX, float posY, float speed) {
		Asteroid a;
		a.aSpeed = speed;
		a.aRotation = GetRandomValue(0, 360);
		a.destroyed = false;
		a.astRectangle = { posX, posY, 40, 40 };
		texture = LoadTexture("res/Asteroid.png");
		return a;
	}

	void UpdateAsteroid(Asteroid a) {
		if (!a.destroyed) {
			a.astRectangle.x += a.aSpeed * sin(a.aRotation*DEG2RAD) *GetFrameTime();
			a.astRectangle.y -= a.aSpeed * cos(a.aRotation*DEG2RAD) *GetFrameTime();
			a.rotation+= 100 * GetFrameTime();
		}
		if (!a.destroyed){
			if (a.astRectangle.x < 0.0f - a.astRectangle.width) {
				a.astRectangle.x = GetScreenWidth();
			}
			if (a.astRectangle.y > GetScreenWidth() + a.astRectangle.width) {
				a.astRectangle.x = 0.0f;
			}
			if (a.astRectangle.y < 0.0f - a.astRectangle.width) {
				a.astRectangle.x = GetScreenWidth();
			}
			if (a.astRectangle.y > GetScreenHeight() + a.astRectangle.height) {
				a.astRectangle.y = 0.0f;
			}
			/*if (Asteroid.x < 0.0f - Asteroid.width ||
				Asteroid.x > GetScreenWidth() ||
				Asteroid.y < 0.0f - Asteroid.height ||
				Asteroid.y > GetScreenHeight())) {

			}*/
		}
	}
	bool AsteroidColisionRec(Rectangle rec, Asteroid a){
		if (!a.destroyed) {
			


		}
		return false;
	}


	void DrawAsteroid(Asteroid a){
		if (!a.destroyed) {
			Vector2 aux = { a.origin.height / 2, a.origin.width / 2 };
			DrawTexturePro(texture, a.origin, a.astRectangle, aux, a.rotation, WHITE);
		}
	}
	void DestroyAsteroid(Asteroid a){
		a.destroyed = true;		
	}
	bool GetDestroyed(Asteroid a) {
		return a.destroyed;
	}
}