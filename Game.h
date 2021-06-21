#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <vector>
#include <cmath>
#include "AssetManager.h"
#include "TextureManager.h"
#include "Ball.h"
#include "Collider.h"
#include "Collision.h"

class Game

{

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void loadAssets();
	void loadMap();
	void createPlayer();
	void setCamera();
	void handleEvents();
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();

	static SDL_Renderer *renderer;
	static SDL_Event event;
	static bool isRunning;
	static SDL_Rect camera;
	static AssetManager *assetManager;
	static TextureManager *textureManager;
	std::vector<Ball*> balls;
	std::vector<std::pair<Ball*,Ball*>> collisions;
	Ball* tempBallA;
	Ball* tempBallB;
	Ball* tempBallC;
	//static UIStatistics *statManager;
	enum groupLabels : std::size_t
	{
		groupMap,
		groupPlayers,
		groupColliders,
		groupProjectiles,
		groupUILables
	};
private:
	//int cnt;
	SDL_Window* window;

};

