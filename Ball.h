#pragma once
#include "Collider.h"
#include "AssetManager.h"
#include <SDL.h>

class Collider;

class Ball {

public:

    Ball(AssetManager * am, float posx, float posy, int ID);

    void printID();

    SDL_Rect srcRect;
    SDL_Rect destRect;
    AssetManager *assetManager;
    SDL_RendererFlip flip;

    Vector2D position;
    Vector2D velocity;

    Collider *ballCollider;

    bool dragBall;
    bool selectedBall = false;
    int mousex = 0, mousey = 0;
    int id;

    void draw();
    void update();

};