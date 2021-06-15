#pragma once
#include <SDL.h>
//#include <SDL_image.h>
//#include <SDL_ttf.h>
#include <iostream>
#include <vector>

class ColliderComponent;
class AssetManager;
//class UIStatistics;

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
	static AssetManager *assets;
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

