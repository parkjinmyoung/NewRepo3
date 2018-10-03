#pragma once
#include "SDL.h"
#include <SDL_image.h>

class Texturemanager
{
public:
	Texturemanager() {};
	~Texturemanager() {};

	
	virtual void TextureLoad() = 0;
	SDL_Renderer * m_pRenderer;


	SDL_Surface* surface() { return pTempSurface; }
	SDL_Texture* texture() { return m_pTexture; }


	SDL_Surface* pTempSurface;
	SDL_Texture* m_pTexture;


	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;

	void Rendererin(SDL_Renderer * kkk)
	{
		m_pRenderer = kkk;
	}
	void RenderCopy()
	{
		SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
	}
	int  xs;
	int tik;
	void setAnimation(int xsize , int tikc)
	{
		xs = xsize;
		tik = tikc;
	}
	void Animation()
	{
		m_sourceRectangle.x = xs * int(((SDL_GetTicks() / 100) % tik));
	}
};

class Background : public Texturemanager
{
public:
	void TextureLoad()
	{
		pTempSurface = IMG_Load("Assets/king.png");
		
		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
		SDL_FreeSurface(pTempSurface);

		m_sourceRectangle.w = 640;
		m_sourceRectangle.h = 480;

		m_destinationRectangle.x = m_sourceRectangle.x = 0;
		m_destinationRectangle.y = m_sourceRectangle.y = 0;
		m_destinationRectangle.w = m_sourceRectangle.w;
		m_destinationRectangle.h = m_sourceRectangle.h;
	}

	
};

class TextureTest : public Texturemanager
{
public:
	void TextureLoad()
	{
		pTempSurface = IMG_Load("Assets/animate-alpha.png");

		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
		SDL_FreeSurface(pTempSurface);

		m_sourceRectangle.w = 128;
		m_sourceRectangle.h = 82;

		m_destinationRectangle.x = m_sourceRectangle.x = 0;
		m_destinationRectangle.y = m_sourceRectangle.y = 0;
		m_destinationRectangle.w = m_sourceRectangle.w;
		m_destinationRectangle.h = m_sourceRectangle.h;
	}
};