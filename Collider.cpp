#include "Collider.h"

Collider::Collider(Ball * pb, float r, Vector2D pos) {
    parentBall = pb;
    radius = r;
    position = pos;
};