#pragma once
#include "SDLGameObject.h"


class BackGround : public SDLGameObject
{
private:
	//void handleInput();

public:
	BackGround(const LoaderParams* pParams, int n);
	virtual void draw();
	virtual void update();
	virtual void clean();
};