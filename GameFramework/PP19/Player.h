#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
private:
	void handleInput();

	float waitshoot;
	float shoottime = 600.0f;

public:
	Player(const LoaderParams* pParams, int n);

	bool checkCollision(SDLGameObject* wall);
	virtual void draw();
	virtual void update();
	//virtual void clean();
};