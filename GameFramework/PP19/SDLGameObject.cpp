#include "SDLGameObject.h"
#include "Game.h"
#include "Nullobject.h"


SDLGameObject::SDLGameObject(const LoaderParams* pParams) :
	GameObject(pParams),
	m_position(pParams->getX(), pParams->getY()),
	m_velocity(0.0f, 0.0f), m_acceleration(0.0f, 0.0f)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_currentRow = 1;
	m_currentFrame = 0;


}

SDLGameObject::SDLGameObject(const LoaderParams* pParams, int n) :
	GameObject(pParams),
	m_position(pParams->getX(), pParams->getY()),
	m_velocity(0.0f, 0.0f), m_acceleration(0.0f, 0.0f)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_currentRow = 1;
	m_currentFrame = 0;

	Order = n;
}

void SDLGameObject::draw()
{
	if (m_velocity.getX() > 0)
	{
		TextureManager::Instance()->drawFrame(m_textureID,
			(Uint32)m_position.getX(), (Uint32)m_position.getY(),
			m_width, m_height, m_currentRow, m_currentFrame,
			TheGame::Instance()->getRenderer(),
			SDL_FLIP_HORIZONTAL);
	}
	else {
		TextureManager::Instance()->drawFrame(m_textureID,
			(Uint32)m_position.getX(), (Uint32)m_position.getY(),
			m_width, m_height, m_currentRow, m_currentFrame,
			TheGame::Instance()->getRenderer());
	}
}

void SDLGameObject::update()
{
	m_velocity += m_acceleration;
	m_position += m_velocity;
}

void SDLGameObject::GameObjectDelete()
{
	S_Play::Instance()->m_gameObjects[Order] = new Nullobject(new LoaderParams(NULL, NULL, NULL, NULL, ""), Order);
}

void SDLGameObject::clean()
{
}

bool SDLGameObject::checkCollision(SDLGameObject* wall)
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