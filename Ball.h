#pragma once
#include "AssetManager.h"
#include <SDL.h>

class Collider;

class Ball {

public:

    Ball(float posx, float posy, int ID);

    void printID();
    void draw();
    void update();

    SDL_Rect srcRect;
    SDL_Rect destRect;
    SDL_RendererFlip flip;
    Vector2D position;
    Vector2D velocity;
    int id;
    float mass = 100;

};