#pragma once
#include "Texture.h"
void Texturemanager::Rendererin(SDL_Renderer * kkk)
{
	m_pRenderer = kkk;
}

void Texturemanager::RenderCopy()
{
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
}


void Texturemanager::setAnimation(int xs, int tikc)
{
	xsize = xs;
	tik = tikc;
}

void Texturemanager::Animation()
{
	m_sourceRectangle.x = xsize * int(((SDL_GetTicks() / 100) % tik));
}

