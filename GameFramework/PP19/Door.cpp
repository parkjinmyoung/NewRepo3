#include "Door.h"

Door::Door(const LoaderParams* pParams, int n) : SDLGameObject(pParams, n)
{
	Tag = "DOOR";
}
void Door::draw()
{
	SDLGameObject::draw();
}
void Door::update()
{
	SDLGameObject::update();
}