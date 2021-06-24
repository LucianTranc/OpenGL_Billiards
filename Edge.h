#pragma once
#include "AssetManager.h"
#include <SDL.h>

class Edge {

public:

    Edge(float pos1x, float pos1y, float pos2x, float pos2y, float r);

    void printID();
    void draw();
    void update();

    SDL_Rect srcRect;
    SDL_Rect destRect1;
    SDL_Rect destRect2;
    SDL_RendererFlip flip;
    Vector2D position1;
    Vector2D position2;
    float radius;

};