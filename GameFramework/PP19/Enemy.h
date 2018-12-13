#pragma once
#include "SDLGameObject.h"
#include "Enemy2.h"
#include "PlayState.h"

class Enemy : public SDLGameObject
{
private:
	//void handleInput();
	float waitshoot;
	float shoottime = 1800.0f;

public:
	Enemy(const LoaderParams* pParams,int n);
	virtual void draw();
	virtual void update();
	virtual void clean();
};