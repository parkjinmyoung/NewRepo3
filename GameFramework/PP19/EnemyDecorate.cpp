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
	if (!TheTextureManager::Instance()->load("assets/ghost.png",
		"ghost", TheGame::Instance()->getRenderer())) {
		return false;
	}


	

	SDLGameObject* enemy1 = new Enemy2(
		new LoaderParams(100, 100, 128, 82, "ghost"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(enemy1);
	SDLGameObject* enemy2 = new Enemy2(
		new LoaderParams(100, 572, 128, 82, "ghost"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(enemy2);
	SDLGameObject* enemy3 = new Enemy2(
		new LoaderParams(618, 100, 128, 82, "ghost"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(enemy3);
	SDLGameObject* enemy4 = new Enemy2(
		new LoaderParams(618, 572, 128, 82, "ghost"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(enemy4);


	return c;
}

bool EnemyDecorate::onExit()
{
	return super->onExit();
}
