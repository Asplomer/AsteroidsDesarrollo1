#include "Bullet.h"
namespace asteroids {
	static float bulletRotation = 0.0f;
	static bool Shot = false;
	static Rectangle Bullet = { -100, -100, SQUARE / 4, SQUARE / 4 };
	void BulletMovement(Rectangle ship, float rot) {
		if (Shot) {
			//Bullet.y -= BASESPEED * 1*GetFrameTime();

			Bullet.x += BULLETSPEED * sin(bulletRotation*DEG2RAD) *GetFrameTime();
			Bullet.y -= BULLETSPEED * cos(bulletRotation*DEG2RAD) *GetFrameTime();
			if (Bullet.x < 0.0f - Bullet.width || Bullet.x > GetScreenWidth() || Bullet.y < 0.0f - Bullet.height || Bullet.y  >GetScreenHeight()) {
				SetShot(false);
			}

		}if (!Shot) {
			Bullet.x = ship.x + SQUARE / 4 - 5;
			Bullet.y = ship.y + SQUARE / 4 - 5;
			BulletRestart(rot);
		}
	}
	void BulletRestart(float rot) {
		bulletRotation = rot;
	}
	void UpdateBullet(Rectangle ship, float rot) {
		BulletMovement(ship, rot);
		
	}
	void SetShot(bool sho){
		Shot = sho;
	}
	bool GetShot() {
		return Shot;
	}
	void DrawBullet() {
		DrawRectangleRec(Bullet, WHITE);
	}
}