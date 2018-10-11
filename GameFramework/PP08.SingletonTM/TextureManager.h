#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <map>
using namespace std;

class TextureManager
{
public:

	TextureManager() {}
	~TextureManager() {}

	map<string, SDL_Texture*>m_textureMap;

	bool load(string fileName, string id, SDL_Renderer* pRenderer);

	void draw(string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void DrawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
};