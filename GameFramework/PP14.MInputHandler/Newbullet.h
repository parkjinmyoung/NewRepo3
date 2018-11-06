#pragma once
#include "SDLGameObject.h"
#include "Game.h"

class Newbullet : public SDLGameObject
{
private:
	int n;
public:
	
	Newbullet(const LoaderParams* pParams, int n);
	~Newbullet();
	virtual void draw();
	virtual void update();
	virtual void clean();
	void collwall(GameObject* wall);
};