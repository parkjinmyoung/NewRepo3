#pragma once
#include "SDLGameObject.h"


class Enemy : public SDLGameObject
{
private:
	//void handleInput();

public:
	Enemy(const LoaderParams* pParams,int n);
	virtual void draw();
	virtual void update();
	//virtual void clean();
};