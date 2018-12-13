#pragma once
#include "StateDecorate.h"
#include "SDLGameState.h"
#include "GameState.h"


class WallDecorate2 :public StateDecorate
{
public:
	WallDecorate2(SDLGameState* state);

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return super->getStateID(); }


private:
	SDLGameState * super;

};
