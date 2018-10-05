#ifndef BULLET_H
#define BULLET_H
#include <iostream>
#include "raylib.h"
#include "Game.h"
namespace asteroids {
	
	const int BULLETSPEED = 1000;
	void BulletMovement(Rectangle ship, float rot);
	void BulletRestart(float rot);
	void SetShot(bool sho);
	bool GetShot();
	void DrawBullet();
	void UpdateBullet(Rectangle ship, float rot);
};
#endif 

