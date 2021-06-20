#include "Collision.h"

bool Collision::DetectCollision(Collider * c1, Collider * c2)
{
    
    float distancex = c1->position.x - c2->position.x;
    float distancey = c1->position.y - c2->position.y;
    float distance = sqrt(pow(distancex, 2) + pow(distancey, 2));
	float angle = std::atan2(c1->position.x - c2->position.x, c1->position.y - c2->position.y);
    float overlap = 0.5f * (-(distance - 100));
    std::cout<<"distancex: " + std::to_string(distancex)<<std::endl;
    std::cout<<"distancey: " + std::to_string(distancey)<<std::endl;
    std::cout<<"distance: " + std::to_string(distance)<<std::endl;
    std::cout<<"angle: " + std::to_string(angle)<<std::endl;
    std::cout<<"overlap: " + std::to_string(overlap)<<std::endl;

    

    if (abs(distance) < 100)
    {
        SDL_RenderDrawLine(Game::renderer, c1->position.x, c1->position.y, c2->position.x, c2->position.y);
        c1->parentBall->position.x += overlap * (distancex) / distance;
        c1->parentBall->position.y += overlap * (distancey) / distance;

        c2->parentBall->position.x -= overlap * (distancex) / distance;
        c2->parentBall->position.y -= overlap * (distancey) / distance;
        return true;
    }
    else 
        return false;

};