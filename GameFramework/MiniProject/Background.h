#pragma once
#include "Texture.h"

class Background : public Texturemanager
{
public:

	void TextureLoad()
	{
		pTempSurface = IMG_Load("assets/king.png");

		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
		SDL_FreeSurface(pTempSurface);

		m_sourceRectangle.w = 640;
		m_sourceRectangle.h = 480;

		m_destinationRectangle.x = m_sourceRectangle.x = 0;
		m_destinationRectangle.y = m_sourceRectangle.y = 0;
		m_destinationRectangle.w = m_sourceRectangle.w;
		m_destinationRectangle.h = m_sourceRectangle.h;
	}
	void imagechange()
	{
		pTempSurface = IMG_Load("assets/z.png");
		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
		SDL_FreeSurface(pTempSurface);
	}

};