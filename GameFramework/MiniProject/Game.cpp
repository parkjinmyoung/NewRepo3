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

		SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);

		back->Rendererin(m_pRenderer);
		textext->Rendererin(m_pRenderer);
		
		back->TextureLoad();
		textext->TextureLoad();

		back->setAnimation(640, 2);
		textext->setAnimation(128, 6);



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
	back->Animation();
	textext->Animation();
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	back->RenderCopy();
	textext->RenderCopy();
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
		case SDL_MOUSEBUTTONDOWN:
			back->imagechange();
			back->setAnimation(640, 1);
			textext->imagechange();
			textext->setAnimation(128, 6);
			break;
		default:
			break;
		}
	}
}

