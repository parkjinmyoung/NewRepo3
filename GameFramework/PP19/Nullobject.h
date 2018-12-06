#pragma once
#include "SDLGameObject.h"


class Nullobject : public SDLGameObject
{
private:
	//void handleInput();

public:
	Nullobject(const LoaderParams* pParams, int n) :SDLGameObject(pParams, n) {};
	virtual void draw() {};
	virtual void update() {};
	//virtual void clean();
};