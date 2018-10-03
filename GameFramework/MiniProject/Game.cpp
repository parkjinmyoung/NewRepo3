#include "Game.h"
#include <iostream>
#include <SDL_image.h>

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		
		
		Textureback();
		Texturetest();



		m_bRunning = true;
	
	
		
	}
	else
	{
		return false;
	}
	
	return true;
}


void Game::update()
{
	m_source.x = 128 * int(((SDL_GetTicks() / 100) % 6));
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_background, &m_destinback);
	SDL_RenderCopy(m_pRenderer, m_pTexture2, &m_source, &m_destin);
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvent()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::Textureback()
{
	pTempSurface = IMG_Load("assets/z.png");
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	m_background.w = 640;
	m_background.h = 480;

	m_destinback.x = m_background.x = 0;
	m_destinback.y = m_background.y = 0;
	m_destinback.w = m_background.w;
	m_destinback.h = m_background.h;
}

void Game::Texturetest()
{
	pTempSurface2 = IMG_Load("assets/animate-alpha.png");
	m_pTexture2 = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface2);
	SDL_FreeSurface(pTempSurface2);

	m_source.w = 128;
	m_source.h = 82;
	m_destin.x = m_source.x = 0;
	m_destin.y = m_source.y = 0;
	m_destin.w = m_source.w;
	m_destin.h = m_source.h;

}

/*
m_source.w = 128;
		m_source.h = 82;
		m_destin.x = m_source.x = 0;
		m_destin.y = m_source.y = 0;
		m_destin.w = m_source.w;
		m_destin.h = m_source.h;
		*/