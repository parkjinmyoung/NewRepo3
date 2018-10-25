#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <map>
using namespace std;



class TextureManager
{
private:


	TextureManager() {}
	~TextureManager() {}
	static TextureManager* s_pInstance;
public:


	map<string, SDL_Texture*>m_textureMap;



	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}


	bool load(string fileName, string id, SDL_Renderer* pRenderer);

	void draw(string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void DrawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
};



typedef TextureManager TheTextureManager;
