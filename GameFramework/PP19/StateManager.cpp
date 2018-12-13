#include "StateManager.h"


StateManager*StateManager::s_pInstance = 0;;


void StateManager::Run()
{
	MY_GAMEMACHINE::Instance()->changeState(S_Menu::Instance());
}


void StateManager::GameStart()
{
	GameState* temp = new DoorDecorate(new WallDecorate(S_Play::Instance()));
	States.push_back(temp);
	Curmap++;
	MY_GAMEMACHINE::Instance()->changeState(temp);
	cout << Curmap << endl;
}
void StateManager::ChangeMap()
{
	MY_GAMEMACHINE::Instance()->changeState(NextMap());
}

GameState* StateManager::NextMap()
{

	
	
	
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
		N_Map = Choicedoor(ChoiceEnemy(ChoiceWall(S_Play::Instance())));
		
	}
	
		
		
	States.push_back(N_Map);
	return N_Map;
}

SDLGameState* StateManager::ChoiceEnemy(SDLGameState* S)
{
	SDLGameState* temp;
	int i = 0;
	i = rand() % 4;
	if (i == 0)
	{
		temp = new EnemyDecorate(S);
	}
	else if (i == 1)
	{
		temp = new EnemyDecorate2(S);
	}
	else if (i == 2)
	{
		temp = new EnemyDecorate3(S);
	}
	else
	{
		temp = S;
	}

		
	return temp;
}

SDLGameState* StateManager::ChoiceWall(SDLGameState* S)
{
	return new WallDecorate(S);
}

SDLGameState* StateManager::Choicedoor(SDLGameState* S)
{
	return new DoorDecorate(S);
}
