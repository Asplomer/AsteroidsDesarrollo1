#ifndef PLAY_H
#define PLAY_H
#include "raylib.h"
#include "Game.h"
namespace Asteroids {
	const int POSX = 20;
	const float POSY = screenHeight / 2;
	const int WIDTH = 20;
	const int HEIGHT = 70;
	const int SQUARE = 20;
	const int BASESPEED = 80;

	void UpdatePlay();
	void DrawPlay();
};
#endif