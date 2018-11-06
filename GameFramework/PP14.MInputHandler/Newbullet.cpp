#include "Newbullet.h"
#include "Game.h"

Newbullet::Newbullet(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Newbullet::draw()
{
	TextureManager::Instance()->draw(m_textureID,
		(int)m_position.getX(), (int)m_position.getY(),
		m_width, m_height,
		TheGame::Instance()->getRenderer());
}
void Newbullet::update()
{
	m_position.setX(m_position.getX() + 1);
}
void Newbullet::clean()
{

}