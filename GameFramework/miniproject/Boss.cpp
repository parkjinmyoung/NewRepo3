#include "Boss.h"
#include "InputHandler.h"
#include "PlayState.h"
#include "GameOverState.h"

Boss::Boss(const LoaderParams* pParams, int n) : SDLGameObject(pParams, n)
{
	Tag = "ENEMY";
}
void Boss::draw()
{
	SDLGameObject::draw();
}
void Boss::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 1 /*m_numFrames*/));
	


	SDLGameObject::update();
}

void Boss::clean()
{
	GameObjectDelete();
}

