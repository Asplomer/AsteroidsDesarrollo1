#include "Play.h"
#include <math.h>
namespace Asteroids {
	//static Rectangle ship = { (float)GetScreenHeight()/2,(float)GetScreenWidth()/2, SQUARE, SQUARE };
	static Rectangle ship = { 400,225, SQUARE, SQUARE };
	static Rectangle BigAsteroid1 = {400, 55, SQUARE*2, SQUARE*2};
	static Rectangle BigAsteroid2 = { 400, 110, SQUARE * 2, SQUARE * 2 };
	
	static float rotation = 0.0f;
	static Vector2 origin = { 10, 10 };
	static Rectangle Bullet = { -100, -100, SQUARE / 4, SQUARE / 4 };
	static bool shoot = false;
	static bool a1= true;
	static bool a2 = true;
	void UpdatePlay() {
		if (IsKeyDown(KEY_LEFT)) { rotation -= 20 * GetFrameTime(); }
		if (IsKeyDown(KEY_RIGHT)) { rotation += 20 * GetFrameTime(); }
		if (IsKeyDown(KEY_SPACE) && !shoot) { 
			shoot = true; 
			Bullet.x = ship.x - Bullet.width/2;
			Bullet.y = ship.y - ship.height/2 -10;
		}
		
		if (IsKeyDown(KEY_UP)) { 

			
			ship.x += BASESPEED*sin(rotation *0.5f) *GetFrameTime();
			ship.y -= BASESPEED*cos(rotation * 0.5f) *GetFrameTime();
		}

		
			if (CheckCollisionRecs(BigAsteroid1, Bullet)) {
				a1 = false;
				shoot = false;
				Bullet.x = -20;
				Bullet.y = -20;
				BigAsteroid1.x = -50;
				BigAsteroid1.y = -50;
			}
			if (CheckCollisionRecs(BigAsteroid2, Bullet)) {
				a2 = false;
				shoot = false;
				Bullet.x = -20;
				Bullet.y = -20;
				BigAsteroid2.x = -50;
				BigAsteroid2.y = -50;
			}
			if (shoot) {
				Bullet.y -= BASESPEED * 1*GetFrameTime();

			}

		if (IsKeyDown(KEY_BACKSPACE) || (!a1 && !a2 )) {
			gameState = End;
		}
	}
	void DrawPlay() {
		DrawRectangleRec(Bullet, WHITE);
	if(a1)DrawRectangleRec(BigAsteroid1, BROWN);
	if (a2)DrawRectangleRec(BigAsteroid2, BROWN);
		DrawRectanglePro(ship, origin,rotation * 30, WHITE);
	}

}