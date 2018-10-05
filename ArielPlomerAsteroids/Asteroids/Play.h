#ifndef PLAY_H
#define PLAY_H
#include "raylib.h"
#include "Game.h"
#include "Ship.h"
#include "Bullet.h"
#include "Asteroid.h"
namespace asteroids {
	//const int POSX = 20;
	//const float POSY = GetScreenHeight / 2;
	const int WIDTH = 20;
	const int HEIGHT = 70;
	extern int BASESPEED;
	//const int SQUARE = 20;
	//const int BASESPEED = 80;
	//const int BULLETSPEED = 1000;
	void InitPlay();
	void UpdatePlay();
	void DrawPlay();
};
#endif