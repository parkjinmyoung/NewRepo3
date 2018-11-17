#pragma once
#include "SDLGameObject.h"
#include "Game.h"

class Newbullet : public SDLGameObject
{
private:
	int n;
	int xvelo;
	int yvelo;
public:
	
	Newbullet(const LoaderParams* pParams, int n,int x ,int y);
	~Newbullet();
	virtual void draw();
	virtual void update();
	virtual void clean();
	void collwall(SDLGameObject* wall);
};