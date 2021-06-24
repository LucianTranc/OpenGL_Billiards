#include <SDL.h>
#include "Game.h"
#include <iostream>
using namespace std;

Game* game = nullptr;

int main(int argc, char* argv[]) {


	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	
	Uint32 frameStart;
	int frameTime;


	game = new Game();

	game->init("Billiards", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1210, 610, false);

	while (game->running()) {

		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		//frameTime is the time it takes for one iteration of the game loop to complete
		//if frameTime is less than the frameDekay that we specified then we must delay the game loop by the difference
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}

	}

	game->clean();
	
	return 0;

}