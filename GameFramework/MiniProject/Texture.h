#pragma once
#include "SDL.h"
#include <SDL_image.h>

class Texturemanager
{
public:
	Texturemanager() {};
	~Texturemanager() {};

	int xsize;
	int ysize;
	int tik;

	char route;


	Texturemanager * NEXT = NULL;



	virtual void TextureLoad() = 0;

	void Rendererin(SDL_Renderer * kkk);
	void RenderCopy();
	
	void setAnimation(int xsize, int tikc);
	void Animation();
	
protected:

	
	SDL_Renderer * m_pRenderer;
	SDL_Surface* pTempSurface;
	SDL_Texture* m_pTexture;


	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;
};



