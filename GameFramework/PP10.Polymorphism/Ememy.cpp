#include "Enemy.h"

Enemy::Enemy(int s)
{
	speed = s;
}

void Enemy::update()
{
	m_x += speed;
	temp += speed;
	if (temp >= 100 || temp <= -100)
	{
		speed *= -1;
		temp = 0;
	}
	m_currentFrame = int(((SDL_GetTicks()*speed / 100) % 2));
}

