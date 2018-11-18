#pragma once
#include "SDLGameObject.h"


class EnemyCtrl : public SDLGameObject
{
private:

	float waitshoot;
	float shoottime = 600.0f;

public:
	EnemyCtrl(const LoaderParams* pParams, int n);
	~EnemyCtrl() {}
	virtual void draw();
	virtual void update();
	virtual void clean();
};