#ifndef PLAY_H
#define PLAY_H
#include "raylib.h"
#include "Game.h"
#include "Ship.h"
#include "Bullet.h"
#include "Asteroid.h"
namespace asteroids {
	const int WIDTH = 20;
	const int HEIGHT = 70;
	extern int BASESPEED;
	extern bool paused;

	void InitPlay();
	void UpdatePlay();
	void DrawPlay();
};
#endif