#pragma once
#include "SDLGameState.h"
#include "Game.h"
#include "GameOverState.h"

class StateDecorate : public SDLGameState
{
public: 
	StateDecorate(SDLGameState* decstate)
	{
		decoratedstate = decstate;

	}


private:

	SDLGameState * decoratedstate;

	virtual void update()
	{
		decoratedstate->update();
	}
	virtual void render()
	{
		decoratedstate->render();
	}
	virtual bool onEnter()
	{
		return decoratedstate->onEnter();
	}

	virtual bool onExit()
	{
		return decoratedstate->onExit();
	}


	
};