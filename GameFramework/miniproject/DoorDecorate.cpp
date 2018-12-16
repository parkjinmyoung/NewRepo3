#include "DoorDecorate.h"
#include "PlayState.h"

DoorDecorate::DoorDecorate(SDLGameState* state) : StateDecorate(state)
{
	super = state;
}

void DoorDecorate::update()
{
	super->update();
}

void DoorDecorate::render()
{
	super->render();
}

bool DoorDecorate::onEnter()
{
	bool c = super->onEnter();

	if (!TheTextureManager::Instance()->load("assets/door.png",
		"door", TheGame::Instance()->getRenderer()))
	{
		return false;
	}if (!TheTextureManager::Instance()->load("assets/door2.png",
		"door2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}if (!TheTextureManager::Instance()->load("assets/door3.png",
		"door3", TheGame::Instance()->getRenderer()))
	{
		return false;
	}if (!TheTextureManager::Instance()->load("assets/door4.png",
		"door4", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	SDLGameObject* door = new Door(
		new LoaderParams(380, 0, 40, 50, "door"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(door);
	SDLGameObject* door4 = new Door(
		new LoaderParams(380, 750, 40, 50, "door4"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(door4);
	SDLGameObject* door2 = new Door(
		new LoaderParams(0, 380, 50, 40, "door2"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(door2);
	SDLGameObject* door3 = new Door(
		new LoaderParams(750, 380, 50, 40, "door3"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(door3);

	return c;
}

bool DoorDecorate::onExit()
{
	return super->onExit();
}