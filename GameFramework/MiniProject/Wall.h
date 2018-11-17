#pragma once
#include "SDLGameObject.h"
#include "Game.h"


class Wall : public SDLGameObject
{
public:
	Wall(const LoaderParams* pParams ,int n);
	virtual void draw();
	virtual void update();
	virtual void clean();
};