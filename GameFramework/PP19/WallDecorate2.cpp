#include "WallDecorate2.h"
#include "PlayState.h"

WallDecorate2::WallDecorate2(SDLGameState* state) : StateDecorate(state)
{
	super = state;

}

void WallDecorate2::update()
{
	super->update();
}

void WallDecorate2::render()
{
	super->render();
}

bool WallDecorate2::onEnter()
{
	bool c = super->onEnter();


	if (!TheTextureManager::Instance()->load("assets/block.png",
		"block", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/block2.png",
		"block2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/rock.png",
		"rock", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/rock2.png",
		"rock2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	SDLGameObject* wall = new Wall(
		new LoaderParams(0, 0, 800, 40, "block"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(wall);
	SDLGameObject* wall3 = new Wall(
		new LoaderParams(0, 760, 800, 40, "block"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(wall3);
	SDLGameObject* wall2 = new Wall(
		new LoaderParams(0, 0, 40, 800, "block2"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(wall2);
	SDLGameObject* wall4 = new Wall(
		new LoaderParams(760, 0, 40, 800, "block2"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(wall4);

	SDLGameObject* rock1 = new Wall(
		new LoaderParams(300, 300, 200, 200, "rock"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(rock1);


	return c;
}

bool WallDecorate2::onExit()
{
	return super->onExit();
}
