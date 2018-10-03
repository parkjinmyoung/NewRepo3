#pragma once
#include "Texture.h"

class Dog : public Texturemanager
{
public:
	Texturemanager *  NEXT = NULL;
	void TextureLoad()
	{
		pTempSurface = IMG_Load("assets/animate-alpha.png");

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