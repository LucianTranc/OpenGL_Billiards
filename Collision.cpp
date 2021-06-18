#include "Collision.h"

bool Collision::DetectCollision(Collider * c1, Collider * c2)
{
    
    float distancex = c1->position.x - c2->position.x;
    float distancey = c1->position.y - c2->position.y;
    float distance = sqrt(pow(distancex, 2) + pow(distancey, 2));

    std::cout<<"distancex: " + std::to_string(distancex)<<std::endl;
    std::cout<<"distancey: " + std::to_string(distancey)<<std::endl;
    std::cout<<"distance: " + std::to_string(distance)<<std::endl;


    if (abs(distance) < 100)
        return true;
    else 
        return false;

};