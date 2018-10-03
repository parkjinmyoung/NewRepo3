#pragma once
#include "SDL.h"
#include "texture.cpp"

class Game
{
public:
	
	Game() {};
	~Game() {};
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvent();
	void clean();
	bool running() { return  m_bRunning; }


	void Textureback();
	void Texturetest();

	Background* back = new Background();
	
private:

	SDL_Renderer * m_pRenderer;
	SDL_Window * m_pWindow;
	
	SDL_Surface* pTempSurface;
	SDL_Surface* pTempSurface2;
	
	bool m_bRunning;

	SDL_Texture* m_pTexture;
	SDL_Texture* m_pTexture2;
	SDL_Rect m_background;
	SDL_Rect m_destinback;
	

	SDL_Rect m_source;
	SDL_Rect m_destin;


};
