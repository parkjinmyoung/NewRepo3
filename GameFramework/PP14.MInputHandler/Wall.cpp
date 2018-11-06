#include "Wall.h"

Wall::Wall(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	

}
void Wall::draw()
{
	TextureManager::Instance()->draw(m_textureID,
		(int)m_position.getX(), (int)m_position.getY(),
		m_width, m_height,
		TheGame::Instance()->getRenderer());
}
void Wall::update()
{

}
void Wall::clean()
{
	m_textureID = "creck";
}

void Wall::Crack()
{
	
}