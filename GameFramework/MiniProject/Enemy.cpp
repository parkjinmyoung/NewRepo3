#include "Enemy.h"
#include "InputHandler.h"

Enemy::Enemy(const LoaderParams* pParams, int n) : SDLGameObject(pParams , n)
{
	
	Tag = "ENEMY";
}
void Enemy::draw()
{
	SDLGameObject::draw();
}
void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 2 /*m_numFrames*/));

	if (SDL_GetTicks() > waitshoot)
	{
		

			S_Play::Instance()->m_gameObjects.push_back
			(new Enemy2(new LoaderParams(m_position.getX(), m_position.getY(), 128, 82, "ghost"), S_Play::Instance()->GameObjectsOrder++));


			waitshoot = SDL_GetTicks() + 1800.0f;
	}

		SDLGameObject::update();
}

	


void Enemy::clean()
{
	GameObjectDelete();
}