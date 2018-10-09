#include "Play.h"
//#include <math.h>
namespace asteroids {
	//static Rectangle ship = { (float)GetScreenHeight()/2,(float)GetScreenWidth()/2, SQUARE, SQUARE };
	static Rectangle ship = { 400,225, SQUARE, SQUARE };
	//static Rectangle BigAsteroid1 = {400, 55, SQUARE*2, SQUARE*2};
	static Rectangle BigAsteroid2 = { 400, 110, SQUARE * 2, SQUARE * 2 };
	int BASESPEED = 80;
	static float rotation = 0.0f;
	//static Vector2 origin = { 10, 10 };
	//static Rectangle Bullet = { -100, -100, SQUARE / 4, SQUARE / 4 };
	//static bool shoot = false;

	static Asteroid a1;
	static int pause = 0;
	static bool a2 = true;
	//static float bulletRotation = 0.0f;
	//static float asteroidRotation = GetRandomValue(0,360);
	static float asteroidRotation2 = GetRandomValue(0, 360);
	//static Ship actualShip = new Ship();
	//static actualShip.InitShip();
	
	void UpdatePlay() {
		if (IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON)) {
			if (pause = 0)
				pause = 1;
			else pause = 0;
		}
		/*
		if (IsKeyDown(KEY_LEFT)) { rotation -= BASESPEED* GetFrameTime(); }
		if (IsKeyDown(KEY_RIGHT)) { rotation += BASESPEED * GetFrameTime(); }
		*/
		InputShip();
		/*if (IsKeyDown(KEY_SPACE) && !shoot) { 
			shoot = true; 
			Bullet.x = ship.x + SQUARE / 4 - 5;
			Bullet.y = ship.y + SQUARE / 4 -5;
			bulletRotation = rotation;
		}
		*/
/*		if (IsKeyDown(KEY_UP)) {


			ship.x += BASESPEED * sin(rotation*DEG2RAD) *GetFrameTime();
			ship.y -= BASESPEED * cos(rotation*DEG2RAD) *GetFrameTime();
		}
		*/
		/*
			if (CheckCollisionRecs(BigAsteroid1, Bullet) && a1) {
				a1 = false;
				shoot = false;
				Bullet.x = -20;
				Bullet.y = -20;
			}
			if (CheckCollisionRecs(BigAsteroid2, Bullet) && a2) {
				a2 = false;
				shoot = false;
				Bullet.x = -20;
				Bullet.y = -20;
				igAsteroid2.x = -50;
				BigAsteroid2.y = -50;
			}*/
			/*if (a1) {
				BigAsteroid1.x +=BASESPEED * sin(asteroidRotation*DEG2RAD) *GetFrameTime();
				BigAsteroid1.y -= BASESPEED * cos(asteroidRotation*DEG2RAD) *GetFrameTime();
			}*/
		UpdateAsteroid(a1);
			if (a2) {
				BigAsteroid2.x += BASESPEED * sin(asteroidRotation2*DEG2RAD) *GetFrameTime();
				BigAsteroid2.y -= BASESPEED * cos(asteroidRotation2*DEG2RAD) *GetFrameTime();
			}
			/*if (a1&&(BigAsteroid1.x < 0.0f - BigAsteroid1.width ||
				BigAsteroid1.x > screenWidth ||
				BigAsteroid1.y < 0.0f - BigAsteroid1.height ||
				BigAsteroid1.y > screenHeight)) {
				

			}*/
			UpdateBullet(GetShip(),GetRotation());
			
			/*
			if (shoot) {
				//Bullet.y -= BASESPEED * 1*GetFrameTime();

				Bullet.x += BULLETSPEED * sin(bulletRotation*DEG2RAD) *GetFrameTime();
				Bullet.y -= BULLETSPEED * cos(bulletRotation*DEG2RAD) *GetFrameTime();
				if (Bullet.x < 0.0f-Bullet.width || Bullet.x > screenWidth || Bullet.y < 0.0f - Bullet.height || Bullet.y > screenHeight) {
					shoot = false;
					}
			}if (!shoot) {
				Bullet.x = ship.x + SQUARE/4 -5;
				Bullet.y = ship.y + SQUARE/4 -5;
			}*/
			

		if (IsKeyDown(KEY_BACKSPACE) || (GetDestroyed(a1) && !a2 )) {
			gameState = End;
			UnloadShip();
		}
	}
	void DrawPlay() {

		DrawBullet();
		
	/*if(a1)DrawRectangleRec(BigAsteroid1, BROWN);*/
	if (a2)DrawRectangleRec(BigAsteroid2, BROWN);
		//DrawRectanglePro(ship, origin,rotation, WHITE);
	
		DrawShip(ship, 0.0f);
		DrawAsteroid(a1);
	}
	void InitPlay(){
		a1 = InitAsteroid(400, 55, 100);
	}
}