#include "StateFactory.h"

StateFactory*StateFactory::s_pInstance = 0;;


void StateFactory::Run()
{
	MY_GAMEMACHINE::Instance()->changeState(S_Menu::Instance());
}