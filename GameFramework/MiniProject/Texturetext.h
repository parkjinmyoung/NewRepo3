#pragma once
#include "Texture.h"

class TextureTest : public Texturemanager
{
public:
	TextureTest() {};

	TextureTest(int x, int y) { xpos = x; ypos = y; }
	void TextureLoad()
	{
		pTempSurface = IMG_Load("");

		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
		SDL_FreeSurface(pTempSurface);

		m_sourceRectangle.w = 128;
		m_sourceRectangle.h = 82;

		m_destinationRectangle.x = m_sourceRectangle.x = 0;
		m_destinationRectangle.y = m_sourceRectangle.y = 0;
		m_destinationRectangle.w = m_sourceRectangle.w;
		m_destinationRectangle.h = m_sourceRectangle.h;


		m_destinationRectangle.x = xpos;
		m_destinationRectangle.y = ypos;

	}
	void imagechange()
	{
		pTempSurface = IMG_Load("assets/animate-alpha.png");
		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
		SDL_FreeSurface(pTempSurface);
	}
};
