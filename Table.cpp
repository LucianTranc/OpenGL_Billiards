#include "Table.h"
#include "AssetManager.h"
#include "TextureManager.h"
#include "Game.h"

Table::Table(int posx, int posy, int w, int h) {

    destRect.x = posx;
    destRect.y = posy;
    destRect.w = w;
    destRect.h = h;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = 1656;
    srcRect.h = 928;

}

void Table::draw() {

    TextureManager::Draw(Game::assetManager->GetTexture("pooltable"), srcRect, destRect, flip);
    
}