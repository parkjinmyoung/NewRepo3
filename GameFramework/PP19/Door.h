#pragma once
#include "SDLGameObject.h"


class Door : public SDLGameObject
{
private:
	//void handleInput();

public:
	Door(const LoaderParams* pParams, int n);
	virtual void draw();
	virtual void update();
	//virtual void clean();
};