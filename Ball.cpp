#include "Ball.h"
#include "AssetManager.h"
#include "TextureManager.h"
#include "Game.h"

Ball::Ball(float posx, float posy, int ID) {

    id = ID;
    position.x = posx;
    position.y = posy;
    destRect.h = 100;
	destRect.w = 100;
	destRect.x = position.x;
	destRect.y = position.y;
	srcRect.h = 900;
	srcRect.w = 900;
	srcRect.x = 0;
	srcRect.y = 0;

}

void Ball::printID() {

    std::cout<<id<<std::endl;

}

void Ball::draw() {

    TextureManager::Draw(Game::assetManager->GetTexture("ball"), srcRect, destRect, flip);
    
}

void Ball::update() {
    
    velocity.x = velocity.x * 0.99;
    velocity.y = velocity.y * 0.99;

    if (abs(velocity.x*velocity.x + velocity.y*velocity.y) < 0.01)
    {
        velocity.x = 0;
        velocity.y = 0;
    }

    position.x += velocity.x;
    position.y += velocity.y;

    if (position.x < 0)
        position.x = 800;
    
    if (position.x > 800)
        position.x = 0;

    if (position.y < 0)
        position.y = 800;
    
    if (position.y > 800)
        position.y = 0;

    destRect.x = position.x - 50;
    destRect.y = position.y - 50;
    
}