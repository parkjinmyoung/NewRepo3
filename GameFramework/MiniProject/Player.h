#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Game.h"

class Player : public SDLGameObject
{
private:
	void handleInput();

	float waitshoot = 300000.0f;
	float timer = 0; 

public:
	Player(const LoaderParams* pParams, int n);
	virtual void draw();
	virtual void update();
	//virtual void clean();

};