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
	collplayer(TheGame::Instance()->m_gameObjects[0]);

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

void Enemy::collplayer(SDLGameObject* player)
{
	if ((int)this->getX() + 40 > (int)player->getX() &&
		(int)this->getX() < (int)player->getX() + 40 &&
		(int)this->getY() + 41 > (int)player->getY() &&
		(int)this->getY() < (int)player->getY() + 41)
	{
		player->clean();
	}
}