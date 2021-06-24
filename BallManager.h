#pragma once
#include "AssetManager.h"
#include "Ball.h"
#include "Edge.h"
#include <SDL.h>
#include <vector>

class Ball;
class Edge;

class BallManager {

public:

    void AddBall(float px, float py, float r, int id);
    void AddEdge(float px1, float py1, float px2, float py2, float r, int id);
    void drawGizmos();
    void drawBalls();
    void drawEdges();
    void update();

    AssetManager *assetManager;
    Ball* selectedDragBall;
    Ball* selectedHitBall;
    std::vector<Ball*> balls;
    std::vector<Edge*> edges;
	std::vector<std::pair<Ball*,Ball*>> ballCollisions;
	std::vector<std::pair<Ball*,Edge*>> edgeCollisions;
    int mousex = 0, mousey = 0;

};