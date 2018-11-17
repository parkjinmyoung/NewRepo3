#include "Newbullet.h"


Newbullet::Newbullet(const LoaderParams* pParams, int n, int x, int y) : SDLGameObject(pParams , n)
{
	this->n = n;
	xvelo = x;
	yvelo = y;
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
	if ((int)this->getX() > 700 ||
		(int)this->getX() < -100 ||
		(int)this->getY() < -100 ||
		(int)this->getY() > 600)
	{
		GameObjectDelete();
	}
	m_velocity.setX(xvelo);
	m_velocity.setY(yvelo);

	for (std::vector<GameObject*>::size_type i = 0;
		i != TheGame::Instance()->m_gameObjects.size(); i++)
	{
		if (TheGame::Instance()->m_gameObjects[i]->Tag == "WALL")
		{
			collwall(TheGame::Instance()->m_gameObjects[i]);
		}
	}
	SDLGameObject::update();
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
