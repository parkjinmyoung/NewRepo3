#include "background.h"

BackGround::BackGround(const LoaderParams* pParams, int n) : SDLGameObject(pParams, n)
{

}
void BackGround::draw()
{
	SDLGameObject::draw();
}
void BackGround::update()
{

	SDLGameObject::update();
}

void BackGround::clean()
{
	GameObjectDelete();
}