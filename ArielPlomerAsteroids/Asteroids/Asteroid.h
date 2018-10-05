#ifndef ASTEROID_H
#define ASTEROID_H
#include <iostream>

#include "Bullet.h"
#include "Play.h"
#include <math.h>
#include "raylib.h"
using namespace std;
namespace asteroids {
	struct Asteroid
	{
		float x;
		float y;
		Rectangle origin = { 0.0f, 0.0f, 32.0f, 32.0f };
		bool destroyed;
		float aRotation;
		float rotation;
		float aSpeed;
		Rectangle astRectangle;
	};
	
	
	Asteroid InitAsteroid(float x, float y, float speed);
	void UpdateAsteroid(Asteroid a);
	void AsteroidColision(Asteroid a);
	void DrawAsteroid(Asteroid a);
	void DestroyAsteroid(Asteroid a);
	bool GetDestroyed(Asteroid a);
};
#endif