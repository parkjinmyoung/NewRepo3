#pragma once
#include "SDLGameObject.h"
#include "Game.h"

class Newbullet : public SDLGameObject
{
public:
	Newbullet(const LoaderParams* pParams);
	~Newbullet();
	virtual void draw();
	virtual void update();
	virtual void clean();
	void collwall(GameObject* wall);
};