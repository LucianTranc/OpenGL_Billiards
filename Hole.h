#pragma once
#include "AssetManager.h"
#include <SDL.h>


class Hole {

public:

    Hole(float posx, float posy, float r);
    void printHole();
    void draw();
    void update();

    SDL_Rect srcRect;
    SDL_Rect destRect;
    SDL_RendererFlip flip;
    Vector2D position;
    float radius;

};