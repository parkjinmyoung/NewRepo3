#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include <vector>
#include "InputHandler.h"
#include "Newbullet.h"
#include "Wall.h"
#include "Nullobject.h"
#include "Enemy.h"
#include "EnemyCtrl.h"
class Game
{
public:
	
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit();

	std::vector<SDLGameObject*> m_gameObjects;

	std::vector<SDLGameObject*> m_WallObjects;
	int GameObjectsOrder = 0;

	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	SDL_Window* getWinodw() const { return m_pWindow; }


	bool m_bRunning;

	
	bool running() { return m_bRunning; }

private:
	static Game* s_pInstance;

	

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	


};

typedef Game TheGame;