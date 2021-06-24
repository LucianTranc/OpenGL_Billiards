#include "Hole.h"
#include "AssetManager.h"
#include "TextureManager.h"
#include "Game.h"

Hole::Hole(float posx, float posy, float r) {

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

void Hole::printHole() {
    std::cout<<"Hole"<<std::endl;
    std::cout<<position.x<<std::endl;
    std::cout<<position.y<<std::endl;
}

void Hole::draw() {

    TextureManager::Draw(Game::assetManager->GetTexture("blackball"), srcRect, destRect, flip);
    
}

void Hole::update() {

    destRect.x = position.x - radius;
    destRect.y = position.y - radius;
    
}