#include "Ball.h"
#include "AssetManager.h"
#include "TextureManager.h"
#include "Game.h"

Ball::Ball(AssetManager * am, float posx, float posy, int ID)
{
    id = ID;
    assetManager = am;
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

    ballCollider = new Collider(this, 50, position);

}

void Ball::printID()
{
    std::cout<<id<<std::endl;
}

void Ball::draw()
{
    TextureManager::Draw(assetManager->GetTexture("ball"), srcRect, destRect, flip);
    if (selectedBall)
    {
        SDL_SetRenderDrawColor(Game::renderer, 0, 0, 255, 255);
        SDL_RenderDrawLine(Game::renderer, position.x, position.y, mousex, mousey);
        SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
    }
        

}

void Ball::update()
{
    if (Game::event.type == SDL_KEYDOWN && Game::event.key.keysym.sym == SDLK_SPACE)
    {   
        if (abs(mousex - position.x) < 50 && abs(mousey - position.y) < 50)
                    dragBall = true; 
    }

    if (Game::event.type == SDL_KEYUP && Game::event.key.keysym.sym == SDLK_SPACE)
    {
        dragBall = false;        
    }

    if (Game::event.type == SDL_MOUSEBUTTONDOWN)
    {
        //std::cout<<"CLICK\n"<<std::endl;
        if (abs(mousex - position.x) < 50 && abs(mousey - position.y) < 50)
            selectedBall = true;
    }
    if (Game::event.type == SDL_MOUSEBUTTONUP)
    {
        if (selectedBall)
        {
            velocity.x = 5.0f * ((position.x) - (mousex))/100;
            velocity.y = 5.0f * ((position.y) - (mousey))/100;
        }
        selectedBall = false;
    }

    SDL_GetMouseState(&mousex, &mousey);
    if (dragBall)
    {
        position.x = mousex;
        position.y = mousey;
        
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

    ballCollider->position = position;

    destRect.x = position.x - 50;
    destRect.y = position.y - 50;

    
}