#ifndef GAME_H
#define GAME_H
#include "raylib.h"
#include "Ship.h"
using namespace std;
namespace Asteroids {
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
	void PlayGame();
	static void UpdateGame();
	static void DrawGame();
	static void InitGame();
};
#endif 
