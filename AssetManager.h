#pragma once
#include <map>
#include <string>
#include "Vector2D.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "TextureManager.h"

class AssetManager
{
public:
	AssetManager();
	~AssetManager();

	//texture management
	void AddTexture(std::string id, const char* path, float w, float h, float iw, float ih);
	void SetActiveTexture(std::string id);
	Texture* GetTexture(std::string id);

	void AddFont(std::string id, std::string path, int fontSize);
	TTF_Font* GetFont(std::string id);

private:

	std::map<std::string, Texture*> textures;
	std::map<std::string, TTF_Font*> fonts;

};