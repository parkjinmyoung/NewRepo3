#pragma once
#include "SDLGameObject.h"


class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams, int n);
	~Enemy() {}
	int speed =1 ;
	virtual void draw();
	virtual void update();
	virtual void clean();
};