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
};

class Background : public Texturemanager
{
public:
	void TextureLoad()
	{
		pTempSurface = IMG_Load("assets/z.png");
		SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
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