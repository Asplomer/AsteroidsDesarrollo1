#include "ship.h"

namespace asteroids {
	static Rectangle _ship = { 400,225, SQUARE, SQUARE };
	static Texture2D texture;
	static float _x = -100;
	static float _y = -100;
	static Vector2 originVec = { 32,32};
	static float accelSpeed = 0.0f;
	static Vector2 vecSpeed = { 0.0f,0.0f };
	static float rotation = 0.0f;
	static Rectangle origin = { 0.0f, 0.0f, 32.0f, 32.0f};

	void InitShip() {
		 texture = LoadTexture("res/Ship.png");
	}
	float GetRotation(){
		return rotation;
	}

	void DrawShip(float rot) {
		Rectangle aux= {_ship.x, _ship.y ,originVec.x, originVec.y };
		Vector2 aux2 = { 16, 16 };
		DrawTexturePro(texture,origin, aux, aux2, rotation, WHITE);
	}

	void InputShip() {

		
		Vector2 mousePos = GetMousePosition();
		Vector2 dir = { _ship.x - mousePos.x, _ship.y - mousePos.y };

		float moduloDir = sqrt(pow(dir.x, 2) + pow(dir.y, 2));
		
		if (moduloDir > 0.0f){
			rotation = acos((_ship.y - mousePos.y) / moduloDir) / DEG2RAD;
		}

		if (_ship.x > mousePos.x) {
			rotation = 360 - rotation;
		}

		vecSpeed.x = sin(rotation*DEG2RAD) *GetFrameTime();
		vecSpeed.y = cos(rotation*DEG2RAD) *GetFrameTime();

		if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
			if (accelSpeed < 2) accelSpeed += 0.04f;
		}
		//else if (accelSpeed > 0)accelSpeed -= 0.0004f;
		else if (accelSpeed < 0) accelSpeed = 0;


		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			SetShot(true);
		}
		_ship.x += vecSpeed.x * accelSpeed* BASESPEED;
		_ship.y -= vecSpeed.y * accelSpeed* BASESPEED;

		
		if (_ship.x > screenWidth-5.0f) {
			_ship.x -= screenWidth+5.1f; 
		}
		else if (_ship.x +5.0f < 0.0f) {
			_ship.x += screenWidth+5.1f;
		}
		if (_ship.y > screenHeight- 5.0f) {
			_ship.y -= screenHeight + 5.1f;
		}
		else if (_ship.y + 5.0f < 0.0f) {
			_ship.y += screenHeight + 5.1f;
		}
	}
	void UnloadShip() {
		UnloadTexture(texture);
	}
	Rectangle GetShip() {
		return _ship;
	}
}