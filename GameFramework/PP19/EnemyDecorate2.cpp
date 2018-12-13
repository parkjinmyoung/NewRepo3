#include "EnemyDecorate2.h"
#include "PlayState.h"

EnemyDecorate2::EnemyDecorate2(SDLGameState* state) : StateDecorate(state)
{
	super = state;
}

void EnemyDecorate2::update()
{
	super->update();
}

void EnemyDecorate2::render()
{
	super->render();
}

bool EnemyDecorate2::onEnter()
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
	if (!TheTextureManager::Instance()->load("assets/potal.png",
		"potal", TheGame::Instance()->getRenderer())) {
		return false;
	}





	SDLGameObject* enemy1 = new Enemy(
		new LoaderParams(100, 100, 128, 82, "potal"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(enemy1);
	SDLGameObject* enemy2 = new Enemy(
		new LoaderParams(100, 572, 128, 82, "potal"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(enemy2);
	SDLGameObject* enemy3 = new Enemy(
		new LoaderParams(618, 100, 128, 82, "potal"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(enemy3);
	SDLGameObject* enemy4 = new Enemy(
		new LoaderParams(618, 572, 128, 82, "potal"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(enemy4);


	return c;
}

bool EnemyDecorate2::onExit()
{
	return super->onExit();
}
