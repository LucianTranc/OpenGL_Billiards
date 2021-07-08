#include "Ball.h"
//#include "AssetManager.h"
//#include "TextureManager.h"
#include "Game.h"

Ball::Ball(float posx, float posy, float r, int ID) {

    id = ID;
    position.x = posx;
    position.y = posy;
    radius = r;

    texPos.x = position.x - radius;
	texPos.y = position.y - radius;

    texture = Game::assetManager->GetTexture("ball1");

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

void Ball::resetCue() {

    position.x = 350.f;
    position.y = 335.f;

    velocity.x = 0.f;
    velocity.y = 0.f;

}

void Ball::draw() {

    //Game::assetManager->SetActiveTexture("ball1");
    texture->Bind();
    glm::vec3 translation(texPos.x, texPos.y, 0);
    glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);
    model = glm::scale(model, glm::vec3(1.0f));
    glm::mat4 projection = glm::ortho(0.0, 1270.0, 670.0, 0.0);
    glm::mat4 mvp = projection * model;
    texture->shader->Bind();
    texture->shader->SetUniformMat4f("u_MVP", mvp);
    Game::renderer->Draw(*(texture->va), *(texture->ib), *(texture->shader));
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

    texPos.x = position.x - radius;
    texPos.y = position.y - radius;
    
}