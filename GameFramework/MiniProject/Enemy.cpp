#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(const LoaderParams* pParams , int n) : SDLGameObject(pParams, n)
{
	Tag = "GHOST";
}
void Enemy::draw()
{
	SDLGameObject::draw(); 
}
void Enemy::update()
{
	m_position.setY(m_position.getY() + speed);
	if (m_position.getY() <= 0 || m_position.getY() + 82 >= 480 )
	{
		speed *= -1;
	}
	m_currentFrame = int(((SDL_GetTicks() / 100) % 2));
}

void Enemy::clean()
{
	Tag = "";
	GameObjectDelete();
}

