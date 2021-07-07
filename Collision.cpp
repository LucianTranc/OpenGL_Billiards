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
    float overlap = 0.5f * (-(distance - b1->radius - b2->radius));


    if (abs(distance) < b1->radius + b2->radius)
    {
        //SDL_RenderDrawLine(Game::renderer, b1->position.x, b1->position.y, b2->position.x, b2->position.y);
        b1->position.x += overlap * (distancex) / distance;
        b1->position.y += overlap * (distancey) / distance;

        b2->position.x -= overlap * (distancex) / distance;
        b2->position.y -= overlap * (distancey) / distance;
        return true;
    }
    else 
        return false;

};

bool Collision::DetectCollisionHole(Ball * b, Hole * h) {
    
    float distancex = b->position.x - h->position.x;
    float distancey = b->position.y - h->position.y;
    float distance = sqrt(pow(distancex, 2) + pow(distancey, 2));

    if (abs(distance) < b->radius + h->radius)
        return true;
    else 
        return false;

};

Vector2D* Collision::DetectCollisionEdge(Ball * b, Edge * e) {

    Vector2D A;
    A.x = e->position1.x;
    A.y = e->position1.y;
    Vector2D B;
    B.x = e->position2.x;
    B.y = e->position2.y;
    Vector2D C;
    C.x = b->position.x;
    C.y = b->position.y;
    Vector2D v1;
    v1.x = C.x - A.x;
    v1.y = C.y - A.y;
    Vector2D v2;
    v2.x = B.x - A.x;
    v2.y = B.y - A.y;

    float distanceSq = ((B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y));
    float t = (v1.x * v2.x + v1.y * v2.y)/distanceSq;

    if (0 < t && t <=1) {
        float denominator = sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));
        float normal = abs((B.x-A.x)*(A.y-C.y) - (A.x-C.x)*(B.y-A.y))/denominator;
        if (normal < b->radius + e->radius) {
            Vector2D closePoint;
            closePoint.x = A.x + t*(B.x - A.x);
            closePoint.y = A.y + t*(B.y - A.y);
            float overlap = (-(normal - b->radius - e->radius));
            float distancex = b->position.x - closePoint.x;
            float distancey = b->position.y - closePoint.y;
            b->position.x += 1.0f * overlap * (distancex) / normal;
            b->position.y += 1.0f * overlap * (distancey) / normal;
            return new Vector2D(closePoint.x, closePoint.y);
        }
    }
    else if (t < 0) {
        float distance1x = e->position1.x - b->position.x;
        float distance1y = e->position1.y - b->position.y;
        float distance1 = sqrt(pow(distance1x, 2) + pow(distance1y, 2));
        if (distance1 < b->radius + e->radius) {
            float distancex = b->position.x - e->position1.x;
            float distancey = b->position.y - e->position1.y;
            float distance = sqrt(pow(distancex, 2) + pow(distancey, 2));
            float overlap = (-(distance - b->radius - e->radius));
            b->position.x += 1.0f * overlap * (distancex) / distance;
            b->position.y += 1.0f * overlap * (distancey) / distance;
            return new Vector2D(e->position1.x, e->position1.y);
        }

    }
    else {

        float distance2x = e->position2.x - b->position.x;
        float distance2y = e->position2.y - b->position.y;
        float distance2 = sqrt(pow(distance2x, 2) + pow(distance2y, 2));
        if (distance2 < b->radius + e->radius) {
            float distancex = b->position.x - e->position2.x;
            float distancey = b->position.y - e->position2.y;
            float distance = sqrt(pow(distancex, 2) + pow(distancey, 2));
            float overlap = (-(distance - b->radius - e->radius));
            b->position.x += 1.0f * overlap * (distancex) / distance;
            b->position.y += 1.0f * overlap * (distancey) / distance;
            return new Vector2D(e->position2.x, e->position2.y);
        }

    }


    return nullptr;

};