#include "Cue.h"
//#include "AssetManager.h"
//#include "TextureManager.h"
#include "Game.h"

Cue::Cue() {

    texture = Game::assetManager->GetTexture("cue");

}

void Cue::draw() {

    if (!Game::ballManager->BallsAreMoving()) {

        mouseangle = Game::ballManager->mouseangle;
        texPos = Game::ballManager->cueBall->position;
    }
    else {
        ballSeparation = 5;
    }

    texture->Bind();
    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(texPos.x, texPos.y, 0));
    model = glm::translate(model, glm::vec3(glm::cos(mouseangle)*82, -glm::sin(mouseangle)*82, 0));
    model = glm::translate(model, glm::vec3(glm::sin(mouseangle)*ballSeparation, glm::cos(mouseangle)*ballSeparation, 0));
    model = glm::rotate(model, -(mouseangle) + glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, glm::vec3(1.0f));
    glm::mat4 projection = glm::ortho(0.0, 1270.0, 670.0, 0.0);
    glm::mat4 mvp = projection * model;
    texture->shader->Bind();
    texture->shader->SetUniformMat4f("u_MVP", mvp);
    Game::renderer->Draw(*(texture->va), *(texture->ib), *(texture->shader));

    
}
