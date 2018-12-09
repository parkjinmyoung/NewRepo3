#include "Player.h"
#include "InputHandler.h"
#include "PlayState.h"
#include "Newbullet.h"

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

	
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		//shoot
		if (SDL_GetTicks() > waitshoot)
		{
			//rithgt 
			if (TheInputHandler::Instance()->getMousePosition()->getX() > m_position.getX() &&
				abs(m_position.getX() - TheInputHandler::Instance()->getMousePosition()->getX())
				>= abs(m_position.getY() - TheInputHandler::Instance()->getMousePosition()->getY()))
			{

				cout << S_Play::Instance()->m_gameObjects.size() << endl;

				S_Play::Instance()->m_gameObjects.push_back
				(new Newbullet(new LoaderParams(m_position.getX() + 60, m_position.getY(), 64, 64, "bullet"), S_Play::Instance()->GameObjectsOrder++, 5, 0));


				m_textureID = "playerright";
			}
			//left
			else if (TheInputHandler::Instance()->getMousePosition()->getX() < m_position.getX() &&
				abs(m_position.getX() - TheInputHandler::Instance()->getMousePosition()->getX())
				>= abs(m_position.getY() - TheInputHandler::Instance()->getMousePosition()->getY()))
			{
				cout << S_Play::Instance()->m_gameObjects.size() << endl;

				S_Play::Instance()->m_gameObjects.push_back
				(new Newbullet(new LoaderParams(m_position.getX() + 20, m_position.getY(), 64, 64, "bullet"), S_Play::Instance()->GameObjectsOrder++, -5, 0));


				m_textureID = "playerleft";
			}

			//up
			else if (TheInputHandler::Instance()->getMousePosition()->getY() < m_position.getY() &&
				abs(m_position.getX() - TheInputHandler::Instance()->getMousePosition()->getX())
				< abs(m_position.getY() - TheInputHandler::Instance()->getMousePosition()->getY()))
			{

				cout << S_Play::Instance()->m_gameObjects.size() << endl;

				S_Play::Instance()->m_gameObjects.push_back
				(new Newbullet(new LoaderParams(m_position.getX() + 40, m_position.getY() - 30, 64, 64, "bullet"), S_Play::Instance()->GameObjectsOrder++, 0, -5));


				m_textureID = "playerback";
			}
			//doun
			else if (TheInputHandler::Instance()->getMousePosition()->getY() > m_position.getY() &&
				abs(m_position.getX() - TheInputHandler::Instance()->getMousePosition()->getX())
				< abs(m_position.getY() - TheInputHandler::Instance()->getMousePosition()->getY()))
			{
				cout << S_Play::Instance()->m_gameObjects.size() << endl;

				S_Play::Instance()->m_gameObjects.push_back
				(new Newbullet(new LoaderParams(m_position.getX() + 40, m_position.getY() + 30, 64, 64, "bullet"), S_Play::Instance()->GameObjectsOrder++, 0, 5));


				m_textureID = "playerfront";
			}
			waitshoot = SDL_GetTicks() + 600.0f;
		}

	}
	
}


Player::Player(const LoaderParams* pParams , int n) : SDLGameObject(pParams,n)
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

	for (std::vector<SDLGameObject*>::size_type i = 0;
		i != S_Play::Instance()->m_gameObjects.size(); i++)
	{
		if (S_Play::Instance()->m_gameObjects[i]->Tag == "WALL")
		{
			if (checkCollision(S_Play::Instance()->m_gameObjects[i]))
			{

			}
		}
		if (S_Play::Instance()->m_gameObjects[i]->Tag == "ENEMY")
		{
			if (checkCollision(S_Play::Instance()->m_gameObjects[i]))
			{
				MY_GAMEMACHINE::Instance()->changeState(
					S_Over::Instance());
				break;
			}
			
		}
	}

	m_currentFrame = int(((SDL_GetTicks() / 100) % 2));
	SDLGameObject::update();


}


bool Player::checkCollision(SDLGameObject* wall)
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