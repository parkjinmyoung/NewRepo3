#include "Player.h"
#include <stdlib.h>

void Player::handleInput()
{
	
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
	{
		m_velocity.setX(2);
		m_textureID = "playerright";
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
	{
		m_velocity.setX(-2);
		m_textureID = "playerleft";
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
	{
		m_velocity.setY(-2);
		m_textureID = "playerback";
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))
	{
		m_velocity.setY(2);
		m_textureID = "playerfront";
	}


	//if (TheInputHandler::Instance()->)
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		//shoot
		if ( SDL_GetTicks() > waitshoot)
		{
		//rithgt 
		if (TheInputHandler::Instance()->getMousePosition()->getX() > m_position.getX() &&
			abs(m_position.getX() - TheInputHandler::Instance()->getMousePosition()->getX())
			>= abs(m_position.getY() - TheInputHandler::Instance()->getMousePosition()->getY()))
		{
			TheGame::Instance()->m_gameObjects.push_back
			(new Newbullet(new LoaderParams(m_position.getX() + 60, m_position.getY(), 64, 64, "bullet"), TheGame::Instance()->GameObjectsOrder++, 5, 0));

			cout << TheGame::Instance()->m_gameObjects.size() << endl;
			m_textureID = "playerright";
		}
		//left
		else if (TheInputHandler::Instance()->getMousePosition()->getX() < m_position.getX() &&
			abs(m_position.getX() - TheInputHandler::Instance()->getMousePosition()->getX())
			>= abs(m_position.getY() - TheInputHandler::Instance()->getMousePosition()->getY()))
		{
			TheGame::Instance()->m_gameObjects.push_back
			(new Newbullet(new LoaderParams(m_position.getX() + 20, m_position.getY(), 64, 64, "bullet"), TheGame::Instance()->GameObjectsOrder++, -5, 0));

			cout << TheGame::Instance()->m_gameObjects.size() << endl;
			m_textureID = "playerleft";
		}

		//up
		else if (TheInputHandler::Instance()->getMousePosition()->getY() < m_position.getY() &&
			abs(m_position.getX() - TheInputHandler::Instance()->getMousePosition()->getX())
			< abs(m_position.getY() - TheInputHandler::Instance()->getMousePosition()->getY()))
		{
			TheGame::Instance()->m_gameObjects.push_back
			(new Newbullet(new LoaderParams(m_position.getX() + 40, m_position.getY() - 30, 64, 64, "bullet"), TheGame::Instance()->GameObjectsOrder++, 0, -5));

			cout << TheGame::Instance()->m_gameObjects.size() << endl;
			m_textureID = "playerback";
		}
		//doun
		else if (TheInputHandler::Instance()->getMousePosition()->getY() > m_position.getY() &&
			abs(m_position.getX() - TheInputHandler::Instance()->getMousePosition()->getX())
			< abs(m_position.getY() - TheInputHandler::Instance()->getMousePosition()->getY()))
		{
			TheGame::Instance()->m_gameObjects.push_back
			(new Newbullet(new LoaderParams(m_position.getX() + 40, m_position.getY() + 30, 64, 64, "bullet"), TheGame::Instance()->GameObjectsOrder++, 0, 5));

			cout << TheGame::Instance()->m_gameObjects.size() << endl;
			m_textureID = "playerfront";
		}
		waitshoot = SDL_GetTicks() + 600.0f;
		}
		
	}

	//Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	//m_velocity = (*vec - m_position) / 100;

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

	m_textureID = "player";
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 2));
	SDLGameObject::update();


}

