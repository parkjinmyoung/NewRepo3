#pragma once
#include "StateDecorate.h"

#include "SDLGameState.h"
#include "GameState.h"
#include "Boss.h"

class BossDecorate :public StateDecorate
{
public:
	BossDecorate(SDLGameState* state);

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return super->getStateID(); }


private:
	SDLGameState * super;

};
