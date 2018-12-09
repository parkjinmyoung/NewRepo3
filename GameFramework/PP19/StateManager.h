#pragma once
#include "GameStateMachine.h"
#include "GameState.h"
#include "MenuState.h"
#include "PauseState.h"
#include "PlayState.h"

class StateManager
{
public:
	static StateManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new StateManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void Run();

private:
	static StateManager* s_pInstance;

};