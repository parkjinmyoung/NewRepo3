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
		SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png",
			"animate", m_pRenderer))
		{
			return false;
		}
		if (!TheTextureManager::Instance()->load("assets/Tree.png",
			"tree", m_pRenderer))
		{
			return false;
		}
		/*SDL_Surface* pTempSurface = IMG_Load("assets/animate-alpha.png");


		


		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

		SDL_FreeSurface(pTempSurface);

		m_sourceRectangle.w = 128;
		m_sourceRectangle.h = 82;

		m_destinationRectangle.x = m_sourceRectangle.x = 0;
		m_destinationRectangle.y = m_sourceRectangle.y = 0;
		m_destinationRectangle.w = m_sourceRectangle.w;
		m_destinationRectangle.h = m_sourceRectangle.h;

		*/

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
	//m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	m2_currentFrame = int(((SDL_GetTicks()*2 / 100) % 6));
}



void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	
	TheTextureManager::Instance()->DrawFrame("animate", 0, 0, 128, 82,
		1, m2_currentFrame ,m_pRenderer);
	TheTextureManager::Instance()->DrawFrame("animate", 100, 100,
		128, 82, 1, m_currentFrame, m_pRenderer);
	TheTextureManager::Instance()->draw("tree", 100, 100, 180, 180, m_pRenderer);
	SDL_RenderPresent(m_pRenderer);

}


void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}


void Game::handleEvents()
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
