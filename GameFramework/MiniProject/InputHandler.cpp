#include "Game.h"
#include "InputHandler.h"
#include <iostream>
#include <typeinfo>


InputHandler* InputHandler::s_pInstance = 0;
const Uint8* m_keystates;

InputHandler::InputHandler()
{
	// ������ 
	m_mousePosition = new Vector2D(0, 0);
	for (int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}
}

void InputHandler::Update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			onMouseMove(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown(event);
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
			break;
		case SDL_KEYDOWN:
			onKeyDown();
			break;
		case SDL_KEYUP:
			onKeyUp();
			break;
		default:
			break;
		}
	}

}
void InputHandler::onMouseMove(SDL_Event event)
{
	m_mousePosition->setX(event.motion.x);
	m_mousePosition->setY(event.motion.y);
}

void InputHandler::onMouseButtonDown(SDL_Event event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = true;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = true;
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = true;
	}
}

void InputHandler::onMouseButtonUp(SDL_Event event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = false;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = false;
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = false;
	}
}

void InputHandler::reset()
{
	
	m_mouseButtonStates[LEFT] = false;
	m_mouseButtonStates[MIDDLE] = false;
	m_mouseButtonStates[RIGHT] = false;
	
}

void InputHandler::onKeyDown()
{
	m_keystates = SDL_GetKeyboardState(0);
}

void InputHandler::onKeyUp()
{
	m_keystates = SDL_GetKeyboardState(0);
}




bool InputHandler::getMouseButtonState(int buttonNumber)
{
	return m_mouseButtonStates[buttonNumber];
}



Vector2D*  InputHandler::getMousePosition()
{
	return m_mousePosition;
}


void InputHandler::clean()
{
	/*
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(TheGame::Instance()->getWinodw());
	SDL_DestroyRenderer(TheGame::Instance()->getRenderer());
	SDL_Quit();
	*/
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (m_keystates != 0) {
		if (m_keystates[key] == 1)
		{
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}