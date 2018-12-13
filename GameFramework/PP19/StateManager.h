#pragma once
#include "GameStateMachine.h"
#include "GameState.h"
#include "MenuState.h"
#include "PauseState.h"
#include "PlayState.h"
#include <vector>
#include "WallDecorate.h"
#include "WallDecorate2.h"
#include "WallDecorate3.h"
#include "DoorDecorate.h"
#include "EnemyDecorate.h"
#include "EnemyDecorate2.h"
#include "EnemyDecorate3.h"

class StateManager
{
public:

	int Curmap = 0;
	
	std::vector<GameState*> States;

	static StateManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new StateManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
	GameState* InstanceMap();
	void Run();
	void GameStart();
	void ChangeMap();
	SDLGameState* ChoiceEnemy(SDLGameState* S);
	SDLGameState* ChoiceWall(SDLGameState* S);
	SDLGameState* Choicedoor(SDLGameState* S);
	GameState* NextMap();
	//GameState* PreviousMap();
private:
	static StateManager* s_pInstance;

};

typedef StateManager S_MANAGER;