#include "WallDecorate3.h"
#include "PlayState.h"

WallDecorate3::WallDecorate3(SDLGameState* state) : StateDecorate(state)
{
	super = state;

}

void WallDecorate3::update()
{
	super->update();
}

void WallDecorate3::render()
{
	super->render();
}

bool WallDecorate3::onEnter()
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
		new LoaderParams(100, 100, 100, 100, "rock2"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(rock1);
	SDLGameObject* rock2 = new Wall(
		new LoaderParams(600, 100, 100, 100, "rock2"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(rock2);
	SDLGameObject* rock3 = new Wall(
		new LoaderParams(100, 600, 100, 100, "rock2"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(rock3);
	SDLGameObject* rock4 = new Wall(
		new LoaderParams(600, 600, 100, 100, "rock2"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(rock4);

	return c;
}

bool WallDecorate3::onExit()
{
	return super->onExit();
}
