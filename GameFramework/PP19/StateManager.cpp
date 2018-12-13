#include "StateManager.h"


StateManager*StateManager::s_pInstance = 0;;


void StateManager::Run()
{
	MY_GAMEMACHINE::Instance()->changeState(S_Menu::Instance());
}


void StateManager::GameStart()
{
	GameState* temp = new EnemyDecorate(new WallDecorate(S_Play::Instance()));
	States.push_back(temp);
	Curmap++;
	MY_GAMEMACHINE::Instance()->changeState(temp);
	
}
void StateManager::ChangeMap()
{
	MY_GAMEMACHINE::Instance()->changeState(NextMap());
}

GameState* StateManager::NextMap()
{

	
	if (States[Curmap+1] != NULL )
	{
		return States[++Curmap];
	}
	else
	{
		return InstanceMap();
	}
	
}


/*
GameState* StateManager::PreviousMap()
{
	if (States[Curmap - 1] != NULL)
	{
		return States[--Curmap];
	}
	else
	{
		return InstanceMap();
	}
}
*/

GameState* StateManager::InstanceMap()
{
	GameState* N_Map;

	if (1)
	{
		// ~~~~
	}
	
		
		
	States.push_back(N_Map);
	return N_Map;
}