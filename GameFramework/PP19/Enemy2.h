#pragma once
#include "SDLGameObject.h"


class Enemy2 : public SDLGameObject
{
private:
	//void handleInput();

public:
	Enemy2(const LoaderParams* pParams, int n);
	virtual void draw();
	virtual void update();
	virtual void clean();
	void gotoplayer();
};