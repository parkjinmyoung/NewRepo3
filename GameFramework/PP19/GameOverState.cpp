#include "GameOverState.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

GameOverState*GameOverState::s_pInstance = 0;


void GameOverState::s_gameOverToMain()
{
	MY_GAMEMACHINE::Instance()->changeState(
		S_Menu::Instance());
}
void GameOverState::s_restartPlay()
{
	MY_GAMEMACHINE::Instance()->changeState(
		S_Play::Instance());
}

bool GameOverState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/gameover.png",
		"gameovertext", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/main.png",
		"mainbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/restart.png",
		"restartbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	SDLGameObject* gameOverText = new AnimatedGraphic(
		new LoaderParams(200, 100, 190, 30, "gameovertext"), 2);

	SDLGameObject* button1 = new MenuButton(
		new LoaderParams(200, 200, 200, 80, "mainbutton"),
		s_gameOverToMain);

	SDLGameObject* button2 = new MenuButton(
		new LoaderParams(200, 300, 200, 80, "restartbutton"),
		s_restartPlay);

	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering PauseState\n";
	return true;
}



void GameOverState::update()
{
	SDLGameState::update();
}

void GameOverState::render()
{
	SDLGameState::render();
}

bool GameOverState::onExit()
{
	SDLGameState::onExit();
	

	TheTextureManager::Instance()
		->clearFromTextureMap("gameovertext");
	TheTextureManager::Instance()
		->clearFromTextureMap("restartbutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("mainbutton");
	// reset the mouse button states to false

	TheInputHandler::Instance()->reset();
	std::cout << "exiting PauseState\n";
	return true;
}

