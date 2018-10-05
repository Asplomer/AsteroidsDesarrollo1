#ifndef SHIP_H
#define SHIP_H
#include <iostream>
#include <math.h>
#include <raylib.h>
#include "Game.h"
#include "Bullet.h"
using namespace std;
namespace Asteroids{
	const int BASESPEED = 80;
	const int SQUARE = 20;
	//const int BULLETSPEED = 1000;
	//extern Texture2D texture;
	/*
	struct Ship
	{
		Texture2D texture;
		float _x = -100;
		float _y = -100;
		Vector2 origin = { 16, 16 };
		bool shoot;
		float rotation;
	};*/
	void InitShip();
	void Colision();
	float GetRotation();
	float SetRotation(float rot);
	void DrawShip(Rectangle rec, float rot);
	void InputShip();
	void Shoot();
	void UnloadShip();
	Rectangle GetShip();
};
#endif