#include "Game.h"
#include <SDL_image.h>



Game* Game::s_pInstance = 0;



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

		MY_GAMEMACHINE::Instance()->changeState(S_Menu::Instance());

		m_bRunning = true;
	}
	else
	{
		return false;
	}


	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	MY_GAMEMACHINE::Instance()->render();

	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	MY_GAMEMACHINE::Instance()->update();
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
	TheInputHandler::Instance()->Update();
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		MY_GAMEMACHINE::Instance()->changeState(PlayState::Instance());
	}

}

void Game::quit()
{
	m_bRunning = false;
}