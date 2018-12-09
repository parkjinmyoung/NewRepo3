#pragma once
#include "GameState.h"
#include "Game.h"
#include "GameOverState.h"
class PlayState : public SDLGameState
{
public:

	static PlayState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new PlayState();
			return s_pInstance;
		}
		return s_pInstance;
	}

	int GameObjectsOrder = 0;

	std::vector<SDLGameObject*> m_WallObjects;

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }
	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
private:
	PlayState() {} ;
	

	static const std::string s_playID;
	static PlayState* s_pInstance;

};

typedef PlayState S_Play;