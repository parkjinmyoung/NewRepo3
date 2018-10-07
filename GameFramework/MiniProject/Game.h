#pragma once
#include "SDL.h"
#include "Texture.h"
#include "Texturetext.h"
#include "Background.h"
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



	Background* back = new Background();
	TextureTest* textext = new TextureTest();
	TextureTest* textext2 = new TextureTest(0 ,50);


private:

	SDL_Renderer * m_pRenderer;
	SDL_Window * m_pWindow;
	
	bool m_bRunning;

	

};


/*SDL_Surface* pTempSurface;
	SDL_Surface* pTempSurface2;
	
	SDL_Texture* m_pTexture;
	SDL_Texture* m_pTexture2;

	SDL_Rect m_background;
	SDL_Rect m_destinback;
	

	SDL_Rect m_source;
	SDL_Rect m_destin;
	*/