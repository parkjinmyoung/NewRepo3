#pragma once
#include "StateDecorate.h"


class EnemyDecorate :public StateDecorate
{
public:
	EnemyDecorate(SDLGameState* state);

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return super->getStateID(); }


private:
	SDLGameState * super;

};
