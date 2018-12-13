#include "BossDecorate.h"
#include "PlayState.h"

BossDecorate::BossDecorate(SDLGameState* state) : StateDecorate(state)
{
	super = state;
}

void BossDecorate::update()
{
	super->update();
}

void BossDecorate::render()
{
	super->render();
}

bool BossDecorate::onEnter()
{
	bool c = super->onEnter();

	if (!TheTextureManager::Instance()->load("assets/ghostking.png",
		"ghostking", TheGame::Instance()->getRenderer())) {
		return false;
	}

	SDLGameObject* boss = new Boss(
		new LoaderParams(250, 250, 300, 300, "ghostking"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(boss);




	return c;
}

bool BossDecorate::onExit()
{
	return super->onExit();
}
