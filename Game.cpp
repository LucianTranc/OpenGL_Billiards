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
Vector2D* Game::screenSize = new Vector2D();
Table* Game::table = new Table(0,0,1270,670);

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
	
	loadMap();
	
	createBalls();

}

void Game::loadAssets() {

	assetManager->AddTexture("pinkball", "assets/projectile2.png", renderer);
	assetManager->AddTexture("blackball", "assets/projectile3.png", renderer);
	assetManager->AddTexture("pooltable", "assets/PoolTable.png", renderer);
	assetManager->AddFont("arial", "assets/arial.ttf", 16);

}

void Game::loadMap() {

	

}

void Game::createBalls() {

	ballManager->AddBall(935.0, 335.0, 13.0, 1);

	ballManager->AddBall(935.0 + 24.0*1.0, 335.0 + 15.0*1.0, 13.0, 2);
	ballManager->AddBall(935.0 + 24.0*1.0, 335.0 - 15.0*1.0, 13.0, 3);

	ballManager->AddBall(935.0 + 24.0*2.0, 335.0 - 15.0*2.0, 13.0, 4);
	ballManager->AddBall(935.0 + 24.0*2.0, 335.0 - 15.0*0.0, 13.0, 5);
	ballManager->AddBall(935.0 + 24.0*2.0, 335.0 + 15.0*2.0, 13.0, 6);

	ballManager->AddBall(935.0 + 24.0*3.0, 335.0 - 15.0*3.0, 13.0, 7);
	ballManager->AddBall(935.0 + 24.0*3.0, 335.0 - 15.0*1.0, 13.0, 8);
	ballManager->AddBall(935.0 + 24.0*3.0, 335.0 + 15.0*1.0, 13.0, 9);
	ballManager->AddBall(935.0 + 24.0*3.0, 335.0 + 15.0*3.0, 13.0, 10);

	ballManager->AddBall(935.0 + 24.0*4.0, 335.0 - 15.0*4.0, 13.0, 11);
	ballManager->AddBall(935.0 + 24.0*4.0, 335.0 - 15.0*2.0, 13.0, 12);
	ballManager->AddBall(935.0 + 24.0*4.0, 335.0 + 15.0*0.0, 13.0, 13);
	ballManager->AddBall(935.0 + 24.0*4.0, 335.0 + 15.0*2.0, 13.0, 14);
	ballManager->AddBall(935.0 + 24.0*4.0, 335.0 + 15.0*4.0, 13.0, 15);

	ballManager->AddBall(350.0, 335.0, 13.0, 16);



	ballManager->AddEdge(112.0, 42.0, 593.0, 42.0, 25.0);
	ballManager->AddEdge(678.0, 42.0, 1155.0, 42.0, 25.0);
	
	ballManager->AddEdge(1222.0, 110.0, 1222.0, 560.0, 25.0);

	ballManager->AddEdge(678.0, 625.0, 1155.0, 625.0, 25.0);
	ballManager->AddEdge(112.0, 625.0, 593.0, 625.0, 25.0);

	ballManager->AddEdge(45.0, 110.0, 45.0, 560.0, 25.0);


	
	
	ballManager->AddHole(635.0, 42.0, 15);
	ballManager->AddHole(59.0, 56.0, 15);
	ballManager->AddHole(61.0, 614.0, 15);
	ballManager->AddHole(635.0, 626.0, 15);
	ballManager->AddHole(1207.0, 614.0, 15);
	ballManager->AddHole(1207.0, 58.0, 15);

	/* ballManager->AddEdge(630.0, 30.0, 1190.0, 30.0, 10.0);
	ballManager->AddEdge(80.0, 640.0, 540.0, 640.0, 10.0);
	ballManager->AddEdge(630.0, 640.0, 1190.0, 640.0, 10.0);
	ballManager->AddEdge(30.0, 80.0, 30.0, 590.0, 10.0);
	ballManager->AddEdge(1240.0, 80.0, 1240.0, 590.0, 10.0); */

	/* ballManager->AddEdge(50.0, 0.0, 80.0, 30.0, 10.0);
	ballManager->AddEdge(0.0, 50.0, 30.0, 80.0, 10.0);
	ballManager->AddEdge(540.0, 30.0, 550.0, 0.0, 10.0);
	ballManager->AddEdge(630.0, 30.0, 620.0, 0.0, 10.0);
	ballManager->AddEdge(1190.0, 30.0, 1220.0, 0.0, 10.0);
	ballManager->AddEdge(1240.0, 80.0, 1270.0, 50.0, 10.0);
	ballManager->AddEdge(1240.0, 590.0, 1270.0, 620.0, 10.0);
	ballManager->AddEdge(1190.0, 640.0, 1220.0, 670.0, 10.0);
	ballManager->AddEdge(630.0, 640.0, 620.0, 670.0, 10.0);
	ballManager->AddEdge(540.0, 640.0, 550.0, 670.0, 10.0);
	ballManager->AddEdge(80.0, 640.0, 50.0, 670.0, 10.0);
	ballManager->AddEdge(30.0, 590.0, 0.0, 620.0, 10.0); */


	/* ballManager->AddHole(35.0, 35.0, 22);
	ballManager->AddHole(35.0, 635.0, 22);
	ballManager->AddHole(1235.0, 635.0, 22);
	ballManager->AddHole(1235.0, 35.0, 22);
	ballManager->AddHole(585.0, 18.0, 22);
	ballManager->AddHole(585.0, 653.0, 22); */


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

	for (int i = 0; i < 10; i++)
	{
		ballManager->updatePhysics();
	}
	ballManager->update();

}


void Game::render() {

	SDL_RenderClear(renderer);

	table->draw();
	//ballManager->drawHoles();
	ballManager->drawBalls();
	//ballManager->drawEdges();
	ballManager->drawGizmos();

	SDL_RenderPresent(renderer);

}

void Game::clean() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned\n";

}

