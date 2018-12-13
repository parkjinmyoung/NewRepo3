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
	m_currentFrame = int(((SDL_GetTicks() / 100) % 2 /*m_numFrames*/));
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
		m_velocity.setX(1);
	}
	else
	{
		m_velocity.setX(-1);
	}

	if (S_Play::Instance()->m_gameObjects[1]->getPosition().getY() > this->getPosition().getY())
	{
		m_velocity.setY(1);
	}
	else
	{
		m_velocity.setY(-1);
	}
}