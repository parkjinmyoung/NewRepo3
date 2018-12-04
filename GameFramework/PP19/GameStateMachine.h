#pragma once
#include "GameState.h"
#include <vector>

class GameStateMachine
{
public:
	void changeState(GameState* pState);
	void popState();
	void pushState(GameState *pState);

	void update();
	void render();

	static GameStateMachine* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new GameStateMachine();
			return s_pInstance;
		}
		return s_pInstance;
	}

	

private:
	GameState* m_currentState;
	GameState* m_prevState;

	GameStateMachine() {};

	static GameStateMachine* s_pInstance;
	

	std::vector<GameState*> m_gameStates;
};

typedef GameStateMachine MY_GAMEMACHINE;