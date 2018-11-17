#pragma once
#include "GameObject.h"


class Nullobject : public SDLGameObject
{
public:	
	Nullobject(const LoaderParams* pParams ,int n) :SDLGameObject(pParams , n) {};
	 ~Nullobject() {}
	virtual void draw() {}
	virtual void update() {}
	virtual void clean() {}
	virtual float getX() { return NULL; }
	virtual float getY() { return NULL; }
};