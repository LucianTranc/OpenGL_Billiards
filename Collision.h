#pragma once
#include "Collider.h"
#include <SDL.h>
#include "Game.h"

class Collision
{
public:
    static bool DetectCollision(Collider * c1, Collider * c2);
};