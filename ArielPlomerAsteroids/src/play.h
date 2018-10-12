#ifndef PLAY_H
#define PLAY_H
#include "raylib.h"
#include "game.h"
#include "ship.h"
#include "bullet.h"
#include "asteroid.h"
namespace asteroids {
	const int WIDTH = 20;
	const int HEIGHT = 70;
	extern Music music;
	extern int BASESPEED;
	extern bool paused;

	void InitPlay();
	void UpdatePlay();
	void DrawPlay();
};
#endif