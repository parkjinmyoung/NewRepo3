#include "PlayState.h"
#include "PauseState.h"


const std::string PlayState::s_playID = "PLAY";

PlayState*PlayState::s_pInstance = 0;

void PlayState::update()
{

	SDLGameState::update();


	/*if (checkCollision(
		dynamic_cast<SDLGameObject*>(m_gameObjects[0]),
		dynamic_cast<SDLGameObject*>(m_gameObjects[1])))
	{
		MY_GAMEMACHINE::Instance()->changeState(
			S_Over::Instance());
	}
	else */
	if (TheInputHandler::Instance()->isKeyDown(
		SDL_SCANCODE_ESCAPE))
	{
		MY_GAMEMACHINE::Instance()->changeState(
			S_Pause::Instance());

	}
}

void PlayState::render()
{
	SDLGameState::render();
}

bool PlayState::onEnter()
{
	GameObjectsOrder = 0;

	if (!TheTextureManager::Instance()->load("assets/front.png",
		"player", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/go front.png",
		"playerfront", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/go right.png",
		"playerright", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/go left.png",
		"playerleft", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/go back.png",
		"playerback", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/bullet3.png",
		"bullet", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/badak.png",
		"badak", TheGame::Instance()->getRenderer()))
	{
		return false;
	}


	SDLGameObject* grass = new BackGround(
		new LoaderParams(0, 0, 800, 800, "badak"), GameObjectsOrder++);
	m_gameObjects.push_back(grass);


	SDLGameObject* player = new Player(
						//xÁÂÇ¥ yÁÂÇ¥ /°¡·Î ¼¼·Î
		new LoaderParams(336, 359 , 128, 82, "player"), GameObjectsOrder++);
	m_gameObjects.push_back(player);




	
	
	
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	SDLGameState::onExit();


	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	std::cout << "exiting PlayState\n";
	return true;
}


bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	//Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}