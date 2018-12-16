#include "PauseState.h"

const std::string PauseState::s_pauseID = "PAUSE";

PauseState*PauseState::s_pInstance = 0;

void PauseState::s_pauseToMain()
{
	MY_GAMEMACHINE::Instance()->changeState(
		S_Menu::Instance());
}

void PauseState::s_resumePlay()
{
	MY_GAMEMACHINE::Instance()->popState();
}

void PauseState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PauseState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PauseState::onEnter()
{

	if (!TheTextureManager::Instance()->load("assets/resume.png",
		"resumebutton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/main.png",
		"mainbutton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	SDLGameObject* button1 = new MenuButton(new
		LoaderParams(300, 100, 200, 80, "mainbutton"), s_pauseToMain);
	SDLGameObject* button2 = new MenuButton(new
		LoaderParams(300, 300, 200, 80, "resumebutton"), s_resumePlay);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering PauseState\n";
	return true;
}

bool PauseState::onExit()
{
	SDLGameState::onExit();


	TheTextureManager::Instance()
		->clearFromTextureMap("resumebutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("mainbutton");

	// reset the mouse button states to false
	TheInputHandler::Instance()->reset();
	std::cout << "exiting PauseState\n";
	return true;
}