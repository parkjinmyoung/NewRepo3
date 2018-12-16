#pragma once
#include "SDLGameObject.h"


class Boss : public SDLGameObject
{
private:
	//void handleInput();

public:
	Boss(const LoaderParams* pParams, int n);
	virtual void draw();
	virtual void update();
	virtual void clean();
	
};