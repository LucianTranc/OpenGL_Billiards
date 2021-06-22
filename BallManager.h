#pragma once
#include "AssetManager.h"
#include "Ball.h"
#include <SDL.h>
#include <vector>

class Collider;

class Ball;

class BallManager {

public:

    void AddBall(float px, float py, int id);
    void drawGizmos();
    void drawBalls();
    void update();

    AssetManager *assetManager;
    Ball* selectedDragBall;
    Ball* selectedHitBall;
    std::vector<Ball*> balls;
	std::vector<std::pair<Ball*,Ball*>> collisions;
    int mousex = 0, mousey = 0;

};