#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Game.h"

class Player : public SDLGameObject
{
private:
	void handleInput();

	int n = 2;
public:
	Player(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	//virtual void clean();
	
};