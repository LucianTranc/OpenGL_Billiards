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
#include "BallManager.h"
#include "Collision.h"
#include "Edge.h"
#include "Table.h"

class Game

{

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void loadAssets();
	void loadMap();
	void createBalls();
	void handleEvents();
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();

	static SDL_Renderer *renderer;
	static SDL_Event event;
	static bool isRunning;
	static AssetManager *assetManager;
	static TextureManager *textureManager;
	static BallManager *ballManager;
	static Vector2D *screenSize;
	static Table *table;

private:

	SDL_Window* window;

};

