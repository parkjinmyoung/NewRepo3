#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include "InputHandler.h"
#include "Newbullet.h"
#include "Wall.h"
#include "Nullobject.h"
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

	std::vector<GameObject*> m_gameObjects;


	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	SDL_Window* getWinodw() const { return m_pWindow; }



	
	bool running() { return m_bRunning; }

private:
	static Game* s_pInstance;

	

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;


	

	//SDL_Texture* m_pTexture;
	//SDL_Rect m_sourceRectangle;
	//SDL_Rect m_destinationRectangle;
};

typedef Game TheGame;