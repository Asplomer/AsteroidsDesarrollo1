#ifndef BULLET_H
#define BULLET_H
#include <iostream>
#include "raylib.h"
#include "game.h"
namespace asteroids {
	
	const int BULLETSPEED = 1000;
	void BulletMovement(Rectangle ship, float rot);
	void BulletRestart(float rot);
	void SetShot(bool sho);
	bool GetShot();
	void DrawBullet();
	Rectangle GetRect();
	void UpdateBullet(Rectangle ship, float rot);
};
#endif 

