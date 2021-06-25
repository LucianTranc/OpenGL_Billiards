#include "Ball.h"
#include "AssetManager.h"
#include "TextureManager.h"
#include "Game.h"

Ball::Ball(float posx, float posy, float r, int ID) {

    id = ID;
    position.x = posx;
    position.y = posy;
    radius = r;

    destRect.h = r*2;
	destRect.w = r*2;
	destRect.x = position.x - radius;
	destRect.y = position.y - radius;

	srcRect.h = 900;
	srcRect.w = 900;
	srcRect.x = 0;
	srcRect.y = 0;

}

void Ball::printBall() {
    std::cout<<"Ball"<<std::endl;
    std::cout<<id<<std::endl;
    std::cout<<position.x<<std::endl;
    std::cout<<position.y<<std::endl;
    std::cout<<velocity.x<<std::endl;
    std::cout<<velocity.y<<std::endl;
    std::cout<<mass<<std::endl;

}

void Ball::printID() {

    std::cout<<id<<std::endl;

}

void Ball::draw() {

    TextureManager::Draw(Game::assetManager->GetTexture("pinkball"), srcRect, destRect, flip);
    
}

void Ball::updatePhysics() {
    
    velocity.x = velocity.x * 0.997;
    velocity.y = velocity.y * 0.997;

    if (abs(velocity.x*velocity.x + velocity.y*velocity.y) < 0.0001)
    {
        velocity.x = 0;
        velocity.y = 0;
    }

    position.x += velocity.x;
    position.y += velocity.y;
    
}

void Ball::update() {

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