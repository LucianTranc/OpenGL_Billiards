#include "Game.h"
#include "Vector2D.h"
#include <sstream>
#include <cmath>

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

SDL_Rect Game::camera = { 0, 0, 800*2, 640*2 };
AssetManager* Game::assetManager = new AssetManager();
TextureManager* Game::textureManager = new TextureManager();
	
bool Game::isRunning = false;

Game::Game() {

}
Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		std::cout << "Subsystems initialized!...\n";
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window Created\n";
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created\n";
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	if (TTF_Init() == -1)
	{
		std::cout << "Error : SDL_TTF" << std::endl;
	}

	loadAssets();
	
	loadMap();
	
	createPlayer();

	setCamera();
	

	//SDL_Color white = {0, 0, 0, 0};
}

void Game::loadAssets()
{
	assetManager->AddTexture("ball", "assets/projectile2.png", renderer);
	assetManager->AddFont("arial", "assets/arial.ttf", 16);
}

void Game::loadMap()
{
}

void Game::createPlayer()
{
	balls.push_back(new Ball(assetManager, 100.0, 100.0, 1));
	balls.push_back(new Ball(assetManager, 200.0, 200.0, 2));
	balls.push_back(new Ball(assetManager, 300.0, 300.0, 3));
	balls.push_back(new Ball(assetManager, 400.0, 400.0, 4));
	balls.push_back(new Ball(assetManager, 500.0, 500.0, 5));
}

void Game::setCamera()
{
}


void Game::handleEvents() {

	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}

}

void Game::update()
{


	for (auto & a : balls) {
		a->printID();
    	for (auto & b : balls) {
			if (a->id == b->id)
				continue;
			b->printID();
			Collision::DetectCollision(a->ballCollider, b->ballCollider);
		}
	}

	for (auto & b : balls) {
    	b->update();
	}

	

}


void Game::render() 
{
	SDL_RenderClear(renderer);

	for (auto & b : balls) {
    	b->draw();
	}

	SDL_RenderPresent(renderer);
}

void Game::clean() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned\n";
}

