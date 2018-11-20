#pragma once
#include "GameObject.h"


class Nullobject : public GameObject
{
public:	
	Nullobject(const LoaderParams* pParams) :GameObject(pParams) {};
	 ~Nullobject() {}
	virtual void draw() {}
	virtual void update() {}
	virtual void clean() {}
	virtual float getX() { return NULL; }
	virtual float getY() { return NULL; }
};