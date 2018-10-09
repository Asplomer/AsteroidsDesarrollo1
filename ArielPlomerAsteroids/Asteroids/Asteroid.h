#ifndef ASTEROID_H
#define ASTEROID_H
#include <iostream>
#include "Game.h"
#include "Bullet.h"
#include "Play.h"
#include <math.h>
#include "raylib.h"

using namespace std;
namespace asteroids {
#define ARRAYSIZE 3	
	


	//extern Asteroide aArray[ARRAYSIZE];


	
	void InitAsteroid(Vector2 a1, Vector2 a2, Vector2 a3);
	void UpdateAsteroid();
	bool AsteroidColisionRec(Rectangle r);
	void DrawAsteroid();
	void DestroyAsteroid(int i);
	bool GetDestroyed(int i);
	bool AllDestroyed();
};
#endif