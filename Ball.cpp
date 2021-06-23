#include "Ball.h"
#include "AssetManager.h"
#include "TextureManager.h"
#include "Game.h"

Ball::Ball(float posx, float posy, float r, int ID) {

    id = ID;
    destRect.h = r*2;
	destRect.w = r*2;
	destRect.x = position.x;
	destRect.y = position.y;
	srcRect.h = 900;
	srcRect.w = 900;
	srcRect.x = 0;
	srcRect.y = 0;
    position.x = posx;
    position.y = posy;
    radius = r;

}

void Ball::printID() {

    std::cout<<id<<std::endl;

}

void Ball::draw() {

    TextureManager::Draw(Game::assetManager->GetTexture("pinkball"), srcRect, destRect, flip);
    
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
        position.x = Game::screenSize->x;
    
    if (position.x > Game::screenSize->x)
        position.x = 0;

    if (position.y < 0)
        position.y = Game::screenSize->y;
    
    if (position.y > Game::screenSize->y)
        position.y = 0;

    destRect.x = position.x - radius;
    destRect.y = position.y - radius;
    
}