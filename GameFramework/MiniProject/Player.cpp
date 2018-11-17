#include "Player.h"
void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		
		TheGame::Instance()->m_gameObjects.push_back
		(new Newbullet(new LoaderParams(m_position.getX() + 100, m_position.getY(), 64, 64, "bullet"), TheGame::Instance()->GameObjectsOrder++));

		cout << TheGame::Instance()->m_gameObjects.size() << endl;
		
	}
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;

}


Player::Player(const LoaderParams* pParams,int n) : SDLGameObject(pParams ,n)
{
	
}

void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Player::update()
{
	

	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();


}

