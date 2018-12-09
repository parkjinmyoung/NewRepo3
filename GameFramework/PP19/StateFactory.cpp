#include "StateManager.h"

StateManager*StateManager::s_pInstance = 0;;


void StateManager::Run()
{
	MY_GAMEMACHINE::Instance()->changeState(S_Menu::Instance());
}