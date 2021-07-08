#include "Ball.h"
#include "BallManager.h"
//#include "AssetManager.h"
//#include "TextureManager.h"
#include "Game.h"

void BallManager::drawGizmos() {

    /* SDL_SetRenderDrawColor(Game::renderer, 0, 0, 255, 255);
	for (auto& c : ballCollisions) {
        SDL_RenderDrawLine(Game::renderer, c.first->position.x, c.first->position.y, c.second->position.x, c.second->position.y);
	}
    if (selectedHitBall) {
        SDL_RenderDrawLine(Game::renderer, selectedHitBall->position.x, selectedHitBall->position.y, mousex, mousey);
    }
    SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255); */

}

void BallManager::drawBalls() {

    for (auto & b : balls) {
    	b->draw();
	}

}

void BallManager::drawHoles() {

    for (auto & h : holes) {
    	h->draw();
	}

}

void BallManager::drawEdges() {

    for (auto & e : edges) {
    	e->draw();
	}

}

void BallManager::drawCue() {

    cue->draw();

}

void BallManager::CreateCue() {
    
    cue = new Cue();

}

void BallManager::AddBall(float px, float py, float r, int id, bool isCue) {

    if (isCue) {
        cueBall = new Ball(px, py, r, id);
        balls.push_back(cueBall);
    }
    else 
        balls.push_back(new Ball(px, py, r, id));

}

void BallManager::AddEdge(float px1, float py1, float px2, float py2, float r) {

    edges.push_back(new Edge(px1, py1, px2, py2, r));

}

void BallManager::AddHole(float px, float py, float r) {

    holes.push_back(new Hole(px, py, r));

} 

void BallManager::updatePhysics() {

    ballCollisions.clear();
    edgeCollisions.clear();

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
				for (auto& c : ballCollisions) {
					if (c == tempPair)
						duplicate = true;
				}
				if (!duplicate)
					ballCollisions.push_back({a,b});
			}
		}
	}

    for (auto& c : ballCollisions) {
        Collision::DynamicCollision(c.first, c.second);
	}

    for (auto & b : balls) {
		//b->printID();
    	for (auto & e : edges) {
			//e->printID();
            Vector2D* collisionPoint = Collision::DetectCollisionEdge(b, e);
			if (collisionPoint) {
                Ball* fakeBall = new Ball(collisionPoint->x, collisionPoint->y, e->radius, -1);
                fakeBall->velocity.x = -b->velocity.x;
                fakeBall->velocity.y = -b->velocity.y;
                //fakeBall->mass = 1000000;
				edgeCollisions.push_back({b,fakeBall});
			}
		}
	} 

    for (auto& c : edgeCollisions) {
        Collision::DynamicCollision(c.first, c.second);
	}

    int ballindex = 0;
    for (auto & b : balls) {
		//a->printID();
    	for (auto & h : holes) {
			//b->printID();
			if (Collision::DetectCollisionHole(b, h)) {
                if (b == cueBall)
                    b->resetCue();
                else
                    balls.erase(balls.begin() + ballindex);
                break;
			}
            
		}
        ballindex++;
	} 

    for (auto& b : balls) {
        b->updatePhysics();
    }

}

void BallManager::update() {

    SDL_GetMouseState(&mousex, &mousey);
	mouseangle = std::atan2(mousex - cueBall->position.x, mousey - cueBall->position.y);


    for (auto& b : balls) {
        b->update();
    }

    if (Game::event.type == SDL_KEYDOWN && Game::event.key.keysym.sym == SDLK_SPACE) {   
        for (auto& b : balls) {
            if (abs(mousex - b->position.x) < b->radius && abs(mousey - b->position.y) < b->radius) {
                selectedDragBall = b;
                break;
            }
        }
    }

    if (Game::event.type == SDL_KEYUP && Game::event.key.keysym.sym == SDLK_SPACE) {
        selectedDragBall = nullptr; 
    }

    if (Game::event.type == SDL_MOUSEBUTTONDOWN && selectedHitBall == nullptr) {
        //std::cout<<"alo"<<std::endl;
        mousedown = true;
        selectedHitBall = cueBall;
        clickPos.x = mousex;
        clickPos.y = mousey;
    }
    else if (mousedown && selectedHitBall) {

        clickDistance =  sqrt((clickPos.x - mousex) * (clickPos.x - mousex)
                         + (clickPos.y - mousey) * (clickPos.y - mousey));

        //std::cout<<dist<<std::endl;
        std::cout<<glm::sin(mouseangle)<<std::endl;
        std::cout<<glm::cos(mouseangle)<<std::endl;

        cue->ballSeparation = clickDistance + 5;

    }
    if (Game::event.type == SDL_MOUSEBUTTONUP) {
        cue->ballSeparation = 5;
        if (selectedHitBall) {
            selectedHitBall->velocity.x = -glm::sin(mouseangle) * clickDistance / 50;
            selectedHitBall->velocity.y = -glm::cos(mouseangle) * clickDistance / 50;
        }
        selectedHitBall = nullptr;
        mousedown = false;
    }


    if (selectedDragBall) {
        selectedDragBall->position.x = mousex;
        selectedDragBall->position.y = mousey;
        
    }
    
}