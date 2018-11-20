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


private:
	GameState* m_currentState;
	GameState* m_prevState;

	std::vector<GameState*> m_gameStates;
};