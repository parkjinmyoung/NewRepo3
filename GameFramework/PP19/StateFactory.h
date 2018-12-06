#pragma once
#include "GameStateMachine.h"
#include "GameState.h"
#include "MenuState.h"
#include "PauseState.h"
#include "PlayState.h"

class StateFactory
{
public:
	static StateFactory* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new StateFactory();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void Run();

private:
	static StateFactory* s_pInstance;

};