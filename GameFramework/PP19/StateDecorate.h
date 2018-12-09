#pragma once
#include "SDLGameState.h"
#include "SDLGameObject.h"
#include "PlayState.h"

class StateDecorate : public SDLGameState
{
public: 
	StateDecorate(SDLGameState* state);

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();

	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);


private:
	SDLGameState * super;

};