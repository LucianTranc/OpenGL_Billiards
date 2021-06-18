#pragma once
#include "Collider.h"

class Collision
{
public:
    static bool DetectCollision(Collider * c1, Collider * c2);
};