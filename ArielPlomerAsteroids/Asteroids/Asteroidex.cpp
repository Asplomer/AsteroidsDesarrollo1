#include "Asteroid.h"
#include "Game.h"
namespace asteroids {
	static Texture2D texture;
	
	/*static float rotation;
	static Rectangle origin = { 0.0f, 0.0f, 32.0f, 32.0f };
	static bool destroyed;
	static float aRotation;
	float aSpeed= 0.0f;*/

	/*
	static float x;
	static float y;
	static Rectangle origin = { 0.0f, 0.0f, 32.0f, 32.0f };
	static bool destroyed;
	static float aRotation;
	static float rotation;
	static float aSpeed;
	static Rectangle astRectangle;
	*/

	
	static Rectangle origin;
	/*Asteroid InitStruct(Asteroid a) {
		Asteroid structA;
		structA.x = 0.0f;
		structA.y = 0.0f;
		structA.destroyed = false;
		structA.aRotation = GetRandomValue(0, 360);
		structA.rotation = 0.0f;
		structA.aSpeed = 0.0f;
		structA.astRectangle = { a.x, a.y, 40, 40 };
		return structA;
	}*/

	void InitAsteroid(Asteroid a1, Asteroid a2, Asteroid a3) {
		/*
		float x;
		float y;
		Rectangle origin = { 0.0f, 0.0f, 32.0f, 32.0f };
		bool destroyed;
		float aRotation;
		float rotation;
		float aSpeed;
		Rectangle astRectangle;*/
		
		
		
		
		aArray[0]->x = 0.0f;
		aArray[0]->y = 0.0f;
		aArray[0]->destroyed = false;
		aArray[0]->aRotation = (float)GetRandomValue(0, 360);
		aArray[0]->rotation = 0.0f;
		aArray[0]->aSpeed = 0.0f;
		aArray[0]->astRectangle = { a1.x, a1.y, 40, 40 };
		aArray[1]->x = 0.0f;
		aArray[1]->y = 0.0f;
		aArray[1]->destroyed = false;
		aArray[1]->aRotation = (float)GetRandomValue(0, 360);
		aArray[1]->rotation = 0.0f;
		aArray[1]->aSpeed = 0.0f;
		aArray[1]->astRectangle = { a1.x, a1.y, 40, 40 };
		aArray[2]->x = 0.0f;
		aArray[2]->y = 0.0f;
		aArray[2]->destroyed = false;
		aArray[2]->aRotation = (float)GetRandomValue(0, 360);
		aArray[2]->rotation = 0.0f;
		aArray[2]->aSpeed = 0.0f;
		aArray[2]->astRectangle = { a1.x, a1.y, 40, 40 };


		Rectangle origin = { 0.0f, 0.0f, 32.0f, 32.0f };
		texture = LoadTexture("res/Asteroid.png");
		
	}
	
	
	
	/*
	Asteroid InitAsteroid(float posX, float posY, float speed) {
		Asteroid a;
		a.aSpeed = speed;
		a.aRotation = GetRandomValue(0, 360);
		a.destroyed = false;
		a.astRectangle = { posX, posY, 40, 40 };
		texture = LoadTexture("res/Asteroid.png");
		return a;
	}*/

	void UpdateAsteroid() {
		for (int i = 0; i < 3; i++)
		{
			if (!aArray[i]->destroyed) {
				aArray[i]->astRectangle.x += aArray[i]->aSpeed * sin(aArray[i]->aRotation*DEG2RAD) *GetFrameTime();
				aArray[i]->astRectangle.y -= aArray[i]->aSpeed * cos(aArray[i]->aRotation*DEG2RAD) *GetFrameTime();
				aArray[i]->rotation += 100 * GetFrameTime();
				
			}
			/*
			if (!aArray[i]->destroyed) {
				if (aArray[i]->astRectangle.x < 0.0f - aArray[i]->astRectangle.width) {
					aArray[i]->astRectangle.x = GetScreenWidth();
				}
				if (aArray[i]->astRectangle.y > GetScreenWidth() + aArray[i]->astRectangle.width) {
					aArray[i]->astRectangle.x = 0.0f;
				}
				if (aArray[i]->astRectangle.y < 0.0f - aArray[i]->astRectangle.width) {
					aArray[i]->astRectangle.x = GetScreenWidth();
				}
				if (aArray[i]->astRectangle.y > GetScreenHeight() + aArray[i]->astRectangle.height) {
					aArray[i]->astRectangle.y = 0.0f;
				}

				*/
				/*if (Asteroid.x < 0.0f - Asteroid.width ||
				Asteroid.x > GetScreenWidth() ||
				Asteroid.y < 0.0f - Asteroid.height ||
				Asteroid.y > GetScreenHeight())) {

				}*/
			}
		}
		
	}
	bool AsteroidColisionRec(Rectangle rec){

		return false;
	}


	void DrawAsteroid(){
		if (!AllDestroyed()) {
			Vector2 aux;
			for (int i = 0; i < 3; i++){
				aux = { aArray[i]->astRectangle.height / 2, aArray[i]->astRectangle.width / 2 };
				DrawTexturePro(texture, origin, aArray[i]->astRectangle, aux, aArray[i]->rotation, WHITE);

			}
			
			
			
		}
	}
	void DestroyAsteroid(int i){
		aArray[i]->destroyed = true;		
	}
	bool GetDestroyed(int i) {
		return aArray[i]->destroyed;
	}
	bool AllDestroyed() {

		if (GetDestroyed(0) && GetDestroyed(1)&& GetDestroyed(2)) {
			return true;
		}
		return false;
	}
}