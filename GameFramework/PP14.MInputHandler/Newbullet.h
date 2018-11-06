#pragma once
#include "SDLGameObject.h"


class Newbullet : public SDLGameObject
{
public:
	Newbullet(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};