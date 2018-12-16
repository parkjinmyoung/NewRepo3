#include "MenuState.h"
#include "MenuButton.h"
#include "Game.h"
#include <iostream>
#include "WallDecorate.h"
#include "EnemyDecorate.h"

const std::string MenuState::s_menuID = "MENU";

MenuState*MenuState::s_pInstance = 0;


void MenuState::update()
{
	SDLGameState::update();
}

void MenuState::render()
{
	SDLGameState::render();
}

bool MenuState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/button.png",
		"playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/exit.png",
		"exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/mainBack.png",
		"mainBack", TheGame::Instance()->getRenderer()))
	{

		return false;
	}
	SDLGameObject* mainBack = new AnimatedGraphic(
		new LoaderParams(0, 0, 800, 800, "mainBack"),
		1);

	SDLGameObject* button1 = new MenuButton(
		new LoaderParams(200, 100, 400, 100, "playbutton"),
		s_menuToPlay);

	SDLGameObject* button2 = new MenuButton(
		new LoaderParams(200, 300, 400, 100, "exitbutton"),
		s_exitFromMenu);

	m_gameObjects.push_back(mainBack);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	SDLGameState::onExit();


	TheTextureManager::Instance()
		->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("exitbutton");
	std::cout << "exiting MenuState\n";
	return true;
}


void MenuState::s_menuToPlay()
{
	S_MANAGER::Instance()->GameStart();
}


void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}