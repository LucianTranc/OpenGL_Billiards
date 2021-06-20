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
}

void Ball::update()
{
    

    if (Game::event.type == SDL_MOUSEBUTTONDOWN)
    {
        //std::cout<<"CLICK\n"<<std::endl;
        if (abs(mousex - position.x) < 50 && abs(mousey - position.y) < 50)
            mousedown = true;
    }
    if (Game::event.type == SDL_MOUSEBUTTONUP)
    {
        mousedown = false;
    }

    SDL_GetMouseState(&mousex, &mousey);
    //std::cout<<std::to_string(abs(mousex - position.x)) + ", " + std::to_string(abs(mousey - position.y))<<std::endl;
    //std::cout<<mousedown<<std::endl;
    if (mousedown)
    {
        //std::cout<<"GOTCHA\n"<<std::endl;
        position.x = mousex;
        position.y = mousey;
        
    }


    /*if (Game::event.type == SDL_KEYDOWN)
    {

        switch (Game::event.key.keysym.sym)
        {
            case SDLK_UP:
                velocity.y = velocity.y - 0.1;
                break;
            case SDLK_LEFT:
                velocity.x = velocity.x - 0.1;
                break;
            case SDLK_DOWN:
                velocity.y = velocity.y + 0.1;
                break;
            case SDLK_RIGHT:
                velocity.x = velocity.x + 0.1;
                break;
            default:
                break;
        }
        
    }*/

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
    
    //velocity = velocity * 0.01f;

    ballCollider->position = position;

    destRect.x = position.x - 50;
    destRect.y = position.y - 50;

    
}