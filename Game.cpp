#include "Game.h"
#include "Vector2D.h"
#include <sstream>
#include <cmath>

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
AssetManager* Game::assetManager = new AssetManager();
TextureManager* Game::textureManager = new TextureManager();
BallManager* Game::ballManager = new BallManager();
bool Game::isRunning = false;
Vector2D *Game::screenSize = new Vector2D();

Game::Game() {

}
Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	int flags = 0;

	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems initialized!...\n";
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
			std::cout << "Window Created\n";
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created\n";
		}
		isRunning = true;
	}
	else
		isRunning = false;

	if (TTF_Init() == -1)
		std::cout << "Error : SDL_TTF" << std::endl;

	screenSize->x = width;
	screenSize->y = height;

	loadAssets();
	
	//loadMap();
	
	createBalls();

}

void Game::loadAssets() {

	assetManager->AddTexture("pinkball", "assets/projectile2.png", renderer);
	assetManager->AddTexture("blackball", "assets/blackcircle.png", renderer);
	assetManager->AddFont("arial", "assets/arial.ttf", 16);

}

void Game::loadMap() {

}

void Game::createBalls() {

	ballManager->AddBall(100.0, 100.0, 15.0, 1);
	ballManager->AddBall(200.0, 100.0, 15.0, 2);
	ballManager->AddBall(300.0, 100.0, 15.0, 3);
	ballManager->AddBall(400.0, 100.0, 15.0, 4);
	ballManager->AddBall(500.0, 100.0, 15.0, 5);
	ballManager->AddBall(600.0, 100.0, 15.0, 6);
	ballManager->AddBall(100.0, 300.0, 15.0, 7);
	ballManager->AddBall(200.0, 300.0, 15.0, 8);
	ballManager->AddBall(300.0, 300.0, 15.0, 9);
	ballManager->AddBall(400.0, 300.0, 15.0, 10);
	ballManager->AddBall(500.0, 300.0, 15.0, 11);
	ballManager->AddBall(600.0, 300.0, 15.0, 12);
	ballManager->AddBall(100.0, 500.0, 15.0, 13);

	ballManager->AddEdge(50.0, 0.0, 510.0, 0.0, 10.0);
	ballManager->AddEdge(600.0, 0.0, 1160.0, 0.0, 10.0);
	ballManager->AddEdge(50.0, 610.0, 510.0, 610.0, 10.0);
	ballManager->AddEdge(600.0, 610.0, 1160.0, 610.0, 10.0);
	ballManager->AddEdge(0.0, 50.0, 0.0, 560.0, 10.0);
	ballManager->AddEdge(1210.0, 50.0, 1210.0, 560.0, 10.0);

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

void Game::update() {

	ballManager->update();

}


void Game::render() {

	SDL_RenderClear(renderer);

	ballManager->drawBalls();
	ballManager->drawEdges();
	ballManager->drawGizmos();

	SDL_RenderPresent(renderer);

}

void Game::clean() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned\n";

}

