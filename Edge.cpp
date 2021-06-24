#include "Edge.h"
#include "AssetManager.h"
#include "TextureManager.h"
#include "Game.h"

Edge::Edge(float pos1x, float pos1y, float pos2x, float pos2y, float r) {

    position1.x = pos1x;
    position1.y = pos1y;
    position2.x = pos2x;
    position2.y = pos2y;
    radius = r;

    destRect1.h = r*2;
	destRect1.w = r*2;
    destRect1.x = position1.x - radius;
    destRect1.y = position1.y - radius;
    destRect2.h = r*2;
	destRect2.w = r*2;
    destRect2.x = position2.x - radius;
    destRect2.y = position2.y - radius;

	srcRect.h = 900;
	srcRect.w = 900;
	srcRect.x = 0;
	srcRect.y = 0;



}


void Edge::draw() {

    TextureManager::Draw(Game::assetManager->GetTexture("pinkball"), srcRect, destRect1, flip);
    TextureManager::Draw(Game::assetManager->GetTexture("pinkball"), srcRect, destRect2, flip);

    float nx = -(position1.y - position2.y);
	float ny = (position1.x - position2.x);
	float d = sqrt(nx*nx + ny * ny);
	nx /= d;
	ny /= d;
    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 255, 255);
    SDL_RenderDrawLine(Game::renderer, position1.x + nx * radius, position1.y + ny * radius, position2.x + nx * radius, position2.y + ny * radius);
    SDL_RenderDrawLine(Game::renderer, position1.x - nx * radius, position1.y - ny * radius, position2.x - nx * radius, position2.y - ny * radius);
    SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);

}

void Edge::update() {
    
    
}