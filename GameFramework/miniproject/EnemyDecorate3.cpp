#include "EnemyDecorate3.h"
#include "PlayState.h"

EnemyDecorate3::EnemyDecorate3(SDLGameState* state) : StateDecorate(state)
{
	super = state;
}

void EnemyDecorate3::update()
{
	super->update();
}

void EnemyDecorate3::render()
{
	super->render();
}

bool EnemyDecorate3::onEnter()
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
		new LoaderParams(336, 359, 128, 82, "potal"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(enemy1);


	return c;
}

bool EnemyDecorate3::onExit()
{
	return super->onExit();
}
