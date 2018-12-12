#include "WallDecorate.h"
#include "PlayState.h"

WallDecorate::WallDecorate(SDLGameState* state) : StateDecorate(state)
{
	super = state;
	
}

void WallDecorate::update()
{
	super->update();
}

void WallDecorate::render()
{
	super->render();
}

bool WallDecorate::onEnter()
{
	bool c = super->onEnter();

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

	SDLGameObject* wall5 = new Wall(
		new LoaderParams(300, 300, 200, 200, "wall"), S_Play::Instance()->GameObjectsOrder++);
	S_Play::Instance()->m_gameObjects.push_back(wall5);


	return c;
}

bool WallDecorate::onExit()
{
	return super->onExit();
}
