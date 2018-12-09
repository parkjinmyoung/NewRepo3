#include "Newbullet.h"


Newbullet::Newbullet(const LoaderParams* pParams, int n, int x, int y) : SDLGameObject(pParams, n)
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
	if ((int)this->getPosition().getX() > 700 ||
		(int)this->getPosition().getX() < -100 ||
		(int)this->getPosition().getY() < -100 ||
		(int)this->getPosition().getY() > 600)
	{
		GameObjectDelete();
	}
	m_velocity.setX(xvelo);
	m_velocity.setY(yvelo);

	for (std::vector<SDLGameObject*>::size_type i = 0;
		i != S_Play::Instance()->m_gameObjects.size(); i++)
	{
		if (S_Play::Instance()->m_gameObjects[i]->Tag == "WALL")
		{
			if (checkCollision(S_Play::Instance()->m_gameObjects[i]))
			{
				GameObjectDelete();
			}
		}
		else if (S_Play::Instance()->m_gameObjects[i]->Tag == "ENEMY")
		{
			if (checkCollision(S_Play::Instance()->m_gameObjects[i]))
			{
				damage(S_Play::Instance()->m_gameObjects[i]);
				GameObjectDelete();
			}
		}
	}
	SDLGameObject::update();
}

void Newbullet::clean()
{

}

void Newbullet::damage(SDLGameObject* wall)
{
	wall->clean();
}
//void Newbullet::collwall(SDLGameObject* wall)
//{
//	if ((int)this->getPosition().getX() + 64 > (int)wall->getPosition().getX() &&
//		(int)this->getPosition().getX() < (int)wall->getPosition().getX() + 130 &&
//		(int)this->getPosition().getY() + 64 > (int)wall->getPosition().getY() &&
//		(int)this->getPosition().getY() < (int)wall->getPosition().getY() + 130)
//	{
//		GameObjectDelete();
//		wall->clean();
//	}
//}

bool Newbullet::checkCollision(SDLGameObject* wall)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = this->getPosition().getX();
	rightA = this->getPosition().getX() + this->getWidth();
	topA = this->getPosition().getY();
	bottomA = this->getPosition().getY() + this->getHeight();

	//Calculate the sides of rect B
	leftB = wall->getPosition().getX();
	rightB = wall->getPosition().getX() + wall->getWidth();
	topB = wall->getPosition().getY();
	bottomB = wall->getPosition().getY() + wall->getHeight();

	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}