#ifndef GAME_H
#define GAME_H
#include "raylib.h"
#include "Ship.h"
#include "Asteroid.h"
using namespace std;
namespace asteroids {
#define WHITE  CLITERAL{ 255, 255, 255, 255 }
	extern int screenWidth;
	extern int screenHeight;
	extern int score;
	extern int gameState;
	enum PlayState
	{
		Start,
		Play,
		GameOver,
		Credit,
		End
	};
	struct Asteroide {
		float x;
		float y;
		bool destroyed;
		float aRotation;
		float rotation;
		float aSpeed;
		Rectangle astRectangle;

	};
	void PlayGame();
	static void UpdateGame();
	static void DrawGame();
	static void InitGame();
};
#endif 
