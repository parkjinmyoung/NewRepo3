#include "EnemyDecorate.h"
#include "PlayState.h"

EnemyDecorate::EnemyDecorate(SDLGameState* state) : StateDecorate(state)
{
	super = state;
}

void EnemyDecorate::update()
{
	super->update();
}

void EnemyDecorate::render()
{
	super->render();
}

bool EnemyDecorate::onEnter()
{
	bool c = super->onEnter();

	if (!TheTextureManager::Instance()->load("assets/helicopter.png",
		"helicopter", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/helicopter2.png",
		"helicopter2", TheGame::Instance()->getRenderer())) {
		return false;
	}


	SDLGameObject* enemy = new Enemy(
		new LoaderParams(100, 100, 128, 55, "helicopter2"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(enemy);

	SDLGameObject* enemy2 = new Enemy2(
		new LoaderParams(200, 100, 128, 55, "helicopter2"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(enemy2);


	return c;
}

bool EnemyDecorate::onExit()
{
	return super->onExit();
}
