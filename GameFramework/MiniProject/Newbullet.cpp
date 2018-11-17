#include "Newbullet.h"


Newbullet::Newbullet(const LoaderParams* pParams, int n) : SDLGameObject(pParams , n)
{
	this->n = n;
}
Newbullet::~Newbullet()
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

	
	for (std::vector<GameObject*>::size_type i = 0;
		i != TheGame::Instance()->m_WallObjects.size(); i++)
	{
		collwall(TheGame::Instance()->m_WallObjects[i]);
	}
}

void Newbullet::clean()
{

}

void Newbullet::collwall(SDLGameObject* wall)
{
	if ((int)this->getX() + 64 > (int)wall->getX() &&
		(int)this->getX() < (int)wall->getX() + 130 &&
		(int)this->getY() + 64 > (int)wall->getY() &&
		(int)this->getY() < (int)wall->getY() + 130)
	{
		GameObjectDelete();
		wall->clean();
	}
}
