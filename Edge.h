#pragma once
#include "AssetManager.h"
#include <SDL.h>

class Edge {

public:

    Edge(float pos1x, float pos1y, float pos2x, float pos2y, float r);

    void printID();
    void draw();
    void update();


    Vector2D texPos1;
    Vector2D texPos2;
    Vector2D position1;
    Vector2D position2;
    Texture * texture;
    float radius;

};