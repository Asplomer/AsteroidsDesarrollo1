#include "Ship.h"

namespace asteroids {
	static Rectangle _ship = { 400,225, SQUARE, SQUARE };
	static Texture2D texture;
	static float _x = -100;
	static float _y = -100;
	static Vector2 originVec = { 32,32};
	//static bool shoot;
	static float rotation = 0.0f;
	static Rectangle origin = { 0.0f, 0.0f, 32.0f, 32.0f};

	//static float bulletRotation = 0.0f;
	//static Rectangle Bullet = { -100, -100, SQUARE / 4, SQUARE / 4 };

	void InitShip() {
		 texture = LoadTexture("res/Ship.png");
	}
	float GetRotation(/*float rot*/){
		//rotation = rot;
		return rotation;
	}
	Rectangle GetShip() {
		return _ship;
	}
	void DrawShip(Rectangle rec, float rot) {
		Rectangle aux= {_ship.x, _ship.y ,originVec.x, originVec.y };
		Vector2 aux2 = { 16, 16 };
		DrawTexturePro(texture,origin, aux, aux2, rotation, WHITE);
	}
	void UnloadShip(){
		UnloadTexture(texture);
	}
	void InputShip() {
		if (IsKeyDown(KEY_LEFT)) { rotation -= BASESPEED * GetFrameTime(); }
		if (IsKeyDown(KEY_RIGHT)) { rotation += BASESPEED * GetFrameTime(); }
		if (IsKeyDown(KEY_UP)) {
			_ship.x+= BASESPEED * sin(rotation*DEG2RAD) *GetFrameTime();
			_ship.y -= BASESPEED * cos(rotation*DEG2RAD) *GetFrameTime();
		}
		if (IsKeyDown(KEY_SPACE) && !GetShot()/*!shoot*/) {
			SetShot(true);
			//BulletRestart(rotation);
			/*Bullet.x = _ship.x + SQUARE / 4 - 5;
			Bullet.y = _ship.y + SQUARE / 4 - 5;
			bulletRotation = rotation;*/
		}
		


	}
	void Shoot() {
		/*if (shoot) {
			//Bullet.y -= BASESPEED * 1*GetFrameTime();

			Bullet.x += BULLETSPEED * sin(bulletRotation*DEG2RAD) *GetFrameTime();
			Bullet.y -= BULLETSPEED * cos(bulletRotation*DEG2RAD) *GetFrameTime();
			if (Bullet.x < 0.0f - Bullet.width || Bullet.x > screenWidth || Bullet.y < 0.0f - Bullet.height || Bullet.y > screenHeight) {
				shoot = false;
			}

		}if (!shoot) {
			Bullet.x = _ship.x + SQUARE / 4 - 5;
			Bullet.y = _ship.y + SQUARE / 4 - 5;
		}*/
	}
}