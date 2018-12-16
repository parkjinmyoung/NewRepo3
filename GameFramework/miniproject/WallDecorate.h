#pragma once
#include "StateDecorate.h"
#include "SDLGameState.h"
#include "GameState.h"


class WallDecorate :public StateDecorate
{
public:
	WallDecorate(SDLGameState* state);

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return super->getStateID(); }


private:
	SDLGameState * super;

};
