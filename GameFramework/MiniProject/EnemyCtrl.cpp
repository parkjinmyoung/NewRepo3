#include "EnemyCtrl.h"
#include "Game.h"

EnemyCtrl::EnemyCtrl(const LoaderParams* pParams, int n) : SDLGameObject(pParams, n)
{
	
}
void EnemyCtrl::draw()
{
	SDLGameObject::draw();
}
void EnemyCtrl::update()
{
	if (SDL_GetTicks() > waitshoot)
	{
		cout << TheGame::Instance()->m_gameObjects.size() << endl;

		TheGame::Instance()->m_gameObjects.push_back
		(new Enemy(new LoaderParams(m_position.getX(), m_position.getY(),128, 82, "ghost"), TheGame::Instance()->GameObjectsOrder));
		TheGame::Instance()->m_WallObjects.push_back(TheGame::Instance()->m_gameObjects[TheGame::Instance()->GameObjectsOrder++]);


		waitshoot = SDL_GetTicks() + 3000.0f;

	}
}

void EnemyCtrl::clean()
{
	GameObjectDelete();
}

