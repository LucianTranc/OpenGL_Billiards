#pragma once
#include "AssetManager.h"
#include <SDL.h>

class Table {

public:

    Table(int posx, int posy, int w, int h);
    void draw();
    SDL_Rect srcRect;
    SDL_Rect destRect;
    SDL_RendererFlip flip;

};