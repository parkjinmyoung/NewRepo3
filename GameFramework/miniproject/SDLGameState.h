#pragma once
#include "GameState.h"

class SDLGameState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter() = 0;
	virtual bool onExit();
	virtual std::string getStateID() const = 0;
};