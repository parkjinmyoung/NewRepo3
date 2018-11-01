#include "Game.h"
#include "InputHandler.h"
#include <iostream>
#include <typeinfo>


InputHandler* InputHandler::s_pInstance = 0;

void InputHandler::Update()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->m_bRunning = false;
			break;
		default:
			break;
		}

	}
}

void InputHandler::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(TheGame::Instance()->getWinodw());
	SDL_DestroyRenderer(TheGame::Instance()->getRenderer());
	SDL_Quit();
}


void InputHandler::instaliseJoystick()
{

}