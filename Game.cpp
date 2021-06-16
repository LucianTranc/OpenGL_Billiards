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
	circleText = textureManager->LoadTexture("assets/rainbowCircle.jpg");
	assetManager->AddFont("arial", "assets/arial.ttf", 16);
}

void Game::loadMap()
{
}

void Game::createPlayer()
{
	circleDest.x = 0;
	circleDest.y = 0;
	circleDest.h = 100;
	circleDest.w = 100;
	
	circleSrc.x = 0;
	circleSrc.y = 0;
	circleSrc.h = 900;
	circleSrc.w = 900;
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
	
}


void Game::render() 
{
	SDL_RenderClear(renderer);
	SDL_RendererFlip *tempflip = new SDL_RendererFlip();
	textureManager->Draw(circleText, circleSrc, circleDest, *tempflip);
	SDL_RenderPresent(renderer);
}

void Game::clean() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned\n";
}

