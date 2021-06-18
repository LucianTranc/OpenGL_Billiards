#pragma once
#include "Ball.h"
#include "Vector2D.h"

class Ball;

class Collider 
{
public:
    Collider(Ball * pb, float r, Vector2D pos);

    Ball * parentBall;
    float radius;
    Vector2D position;

private:

};