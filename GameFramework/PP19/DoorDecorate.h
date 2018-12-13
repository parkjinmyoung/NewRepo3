#pragma once
#include "StateDecorate.h"
#include "Door.h"

class DoorDecorate :public StateDecorate
{
public:
	DoorDecorate(SDLGameState* state);

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return super->getStateID(); }


private:
	SDLGameState * super;

};