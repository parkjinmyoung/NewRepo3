#include "Wall.h"

Wall::Wall(const LoaderParams* pParams, int n) : SDLGameObject(pParams, n)
{
	Tag = "WALL";
}
void Wall::draw()
{
	SDLGameObject::draw();
}
void Wall::update()
{
	SDLGameObject::update();
}