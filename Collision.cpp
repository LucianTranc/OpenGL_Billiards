#include "Collision.h"

void Collision::DynamicCollision(Ball * b1, Ball * b2) 
{
    //https://github.com/OneLoneCoder/videos/blob/master/OneLoneCoder_Balls1.cpp
    //https://en.wikipedia.org/wiki/Elastic_collision
    float distance = sqrtf((b1->position.x - b2->position.x)*(b1->position.x - b2->position.x) + (b1->position.y - b2->position.y)*(b1->position.y - b2->position.y));
    float nx = (b2->position.x - b1->position.x) / distance;
    float ny = (b2->position.y - b1->position.y) / distance;
    float kx = (b1->velocity.x - b2->velocity.x);
    float ky = (b1->velocity.y - b2->velocity.y);
    float p = 2.0 * (nx * kx + ny * ky) / (b1->mass + b2->mass);
    b1->velocity.x = b1->velocity.x - p * b2->mass * nx;
    b1->velocity.y = b1->velocity.y - p * b2->mass * ny;
    b2->velocity.x = b2->velocity.x + p * b1->mass * nx;
    b2->velocity.y = b2->velocity.y + p * b1->mass * ny;

};

bool Collision::DetectCollision(Ball * b1, Ball * b2) {
    
    float distancex = b1->position.x - b2->position.x;
    float distancey = b1->position.y - b2->position.y;
    float distance = sqrt(pow(distancex, 2) + pow(distancey, 2));
    float overlap = 0.5f * (-(distance - 100));


    if (abs(distance) < 100)
    {
        SDL_RenderDrawLine(Game::renderer, b1->position.x, b1->position.y, b2->position.x, b2->position.y);
        b1->position.x += overlap * (distancex) / distance;
        b1->position.y += overlap * (distancey) / distance;

        b2->position.x -= overlap * (distancex) / distance;
        b2->position.y -= overlap * (distancey) / distance;
        return true;
    }
    else 
        return false;

};