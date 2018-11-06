#include "Newbullet.h"

Newbullet::Newbullet(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Newbullet::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Newbullet::update()
{
	m_position.setX(m_position.getX() + 1);
}
void Newbullet::clean()
{

}