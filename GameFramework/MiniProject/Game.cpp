#include "Game.h"
#include <iostream>
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
		//SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
		
#pragma region Textureload



		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png",
			"animate", m_pRenderer))
		{
			return false;
		}
		if (!TheTextureManager::Instance()->load("assets/front.png",
			"player", m_pRenderer))
		{
			return false;
		}
		if (!TheTextureManager::Instance()->load("assets/go front.png",
			"playerfront", m_pRenderer))
		{
			return false;
		}
		if (!TheTextureManager::Instance()->load("assets/go right.png",
			"playerright", m_pRenderer))
		{
			return false;
		}
		if (!TheTextureManager::Instance()->load("assets/go left.png",
			"playerleft", m_pRenderer))
		{
			return false;
		}
		if (!TheTextureManager::Instance()->load("assets/go back.png",
			"playerback", m_pRenderer))
		{
			return false;
		}
		if (!TheTextureManager::Instance()->load("assets/Tree.png",
			"tree", m_pRenderer))
		{
			return false;
		}
		if (!TheTextureManager::Instance()->load("assets/bullet1.png",
			"bullet", m_pRenderer))
		{
			return false;
		}if (!TheTextureManager::Instance()->load("assets/nemo.png",
			"nemo", m_pRenderer))
		{
			return false;
		}if (!TheTextureManager::Instance()->load("assets/creck.png",
			"creck", m_pRenderer))
		{
			return false;
		}if (!TheTextureManager::Instance()->load("assets/ghost.png",
			"ghost", m_pRenderer))
		{
			return false;
		}
		
#pragma endregion

		m_gameObjects.push_back
		(new Player(new LoaderParams(100, 100, 128, 82, "player") , GameObjectsOrder++));
		
		cout << TheGame::Instance()->m_gameObjects.size() << endl;
		

		m_gameObjects.push_back
		(new Wall(new LoaderParams(500, 100, 130, 130, "nemo") , GameObjectsOrder));
		m_WallObjects.push_back(TheGame::Instance()->m_gameObjects[GameObjectsOrder++]);


		m_gameObjects.push_back
		(new Enemy(new LoaderParams(300, 200, 128, 82, "ghost"), GameObjectsOrder));
		m_WallObjects.push_back(TheGame::Instance()->m_gameObjects[GameObjectsOrder++]);



		cout << TheGame::Instance()->m_gameObjects.size() << endl;


		std::cout << "init init success!\n";
		
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
	for (std::vector<GameObject*>::size_type i = 0;
	i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

}



void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

	SDL_RenderPresent(m_pRenderer);

}


void Game::clean()
{
	TheInputHandler::Instance()->clean();
}


void Game::handleEvents()
{
	TheInputHandler::Instance()->Update();
}

void Game::quit()
{
	m_bRunning = false;
}