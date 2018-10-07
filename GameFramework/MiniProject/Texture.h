#pragma once
#include "SDL.h"
#include <SDL_image.h>

class Texturemanager
{
public:
	Texturemanager() {};
	Texturemanager(int x, int y);
	~Texturemanager() {};

	int xsize;
	int ysize;
	int tik;

	int xpos = 0;
	int ypos = 0;



	Texturemanager * NEXT = NULL;



	virtual void TextureLoad() = 0;

	void Rendererin(SDL_Renderer * kkk);
	void RenderCopy();
	
	void setAnimation(int xsize, int tikc);
	void Animation();
	void move();
	
protected:

	
	SDL_Renderer * m_pRenderer;
	SDL_Surface* pTempSurface;
	SDL_Texture* m_pTexture;


	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;
};



