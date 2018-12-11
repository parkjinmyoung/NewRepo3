#include "Enemy2.h"
#include "InputHandler.h"
#include "PlayState.h"

Enemy2::Enemy2(const LoaderParams* pParams, int n) : SDLGameObject(pParams, n)
{
	Tag = "ENEMY";
}
void Enemy2::draw()
{
	SDLGameObject::draw();
}
void Enemy2::update()
{

	gotoplayer();



	SDLGameObject::update();
}

void Enemy2::clean()
{
	GameObjectDelete();
}

void Enemy2::gotoplayer()
{
	if (S_Play::Instance()->m_gameObjects[1]->getPosition().getX() > this->getPosition().getX())
	{
		//go
	}
	else
	{
		//0go
	}
}