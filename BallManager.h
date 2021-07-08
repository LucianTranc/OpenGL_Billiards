#pragma once
//#include "AssetManager.h"
#include "Ball.h"
#include "Edge.h"
#include "Cue.h"
#include "Hole.h"
#include <SDL.h>
#include <vector>

class Ball;
class Hole;
class Edge;

class BallManager {

public:

    void AddBall(float px, float py, float r, int id, bool isCue, const char * texturePath);
    void AddHole(float px, float py, float r);
    void AddEdge(float px1, float py1, float px2, float py2, float r);
    void CreateCue();
    void drawGizmos();
    void drawBalls();
    void drawHoles();
    void drawCue();
    void drawEdges();
    void updatePhysics();
    void update();
    bool BallsAreMoving();
    void RespawnCue();

    //AssetManager *assetManager;
    Ball* selectedDragBall;
    Ball* selectedHitBall;
    Ball* cueBall;

    Cue* cue;

    std::vector<Ball*> balls;
    std::vector<Edge*> edges;
    std::vector<Hole*> holes;
	std::vector<std::pair<Ball*,Ball*>> ballCollisions;
	std::vector<std::pair<Ball*,Ball*>> edgeCollisions;
    int mousex = 0, mousey = 0;
    float mouseangle = 0.f;
    float clickDistance = 0.f;
    bool mousedown = false;
    bool queueRespawn = false;
    float hitPower = 0.f;
    Vector2D clickPos;

};