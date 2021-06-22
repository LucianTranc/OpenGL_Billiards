#include "Ball.h"
#include "BallManager.h"
#include "AssetManager.h"
#include "TextureManager.h"
#include "Game.h"

void BallManager::drawGizmos() {

    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 255, 255);
	for (auto& c : collisions) {
        SDL_RenderDrawLine(Game::renderer, c.first->position.x, c.first->position.y, c.second->position.x, c.second->position.y);
	}
    if (selectedHitBall) {
        SDL_RenderDrawLine(Game::renderer, selectedHitBall->position.x, selectedHitBall->position.y, mousex, mousey);
    }
    SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);

}

void BallManager::drawBalls() {

    for (auto & b : balls) {
    	b->draw();
	}

}

void BallManager::AddBall(float px, float py, int id) {

    balls.push_back(new Ball(px, py, id));

}

void BallManager::update() {

    collisions.clear();
	for (auto & a : balls) {
		//a->printID();
    	for (auto & b : balls) {
			if (a->id == b->id)
				continue;
			//b->printID();
			if (Collision::DetectCollision(a, b)) {
				bool duplicate = false;
				std::pair<Ball*, Ball*> tempPair;
				tempPair = {b,a};
				for (auto& c : collisions) {
					if (c == tempPair)
						duplicate = true;
				}
				if (!duplicate)
					collisions.push_back({a,b});
			}
		}
	}

    for (auto& c : collisions) {
        Collision::DynamicCollision(c.first, c.second);
	}

    for (auto& b : balls) {
        b->update();
    }

    if (Game::event.type == SDL_KEYDOWN && Game::event.key.keysym.sym == SDLK_SPACE) {   
        for (auto& b : balls) {
            if (abs(mousex - b->position.x) < 50 && abs(mousey - b->position.y) < 50) {
                selectedDragBall = b;
                break;
            }
        }
    }

    if (Game::event.type == SDL_KEYUP && Game::event.key.keysym.sym == SDLK_SPACE) {
        selectedDragBall = nullptr; 
    }

    if (Game::event.type == SDL_MOUSEBUTTONDOWN) {
        for (auto& b : balls) {
            if (abs(mousex - b->position.x) < 50 && abs(mousey - b->position.y) < 50) {
                selectedHitBall = b;
                break;
            }
        }
        //std::cout<<"CLICK\n"<<std::endl;
    }
    if (Game::event.type == SDL_MOUSEBUTTONUP) {
        if (selectedHitBall) {
            selectedHitBall->velocity.x = 5.0f * ((selectedHitBall->position.x) - (mousex))/100;
            selectedHitBall->velocity.y = 5.0f * ((selectedHitBall->position.y) - (mousey))/100;
        }
        selectedHitBall = nullptr;
    }

    SDL_GetMouseState(&mousex, &mousey);

    if (selectedDragBall) {
        selectedDragBall->position.x = mousex;
        selectedDragBall->position.y = mousey;
        
    }
    
}