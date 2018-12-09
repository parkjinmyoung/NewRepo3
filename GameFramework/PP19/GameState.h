#pragma once
#include<string>
#include<vector>
#include "SDLGameObject.h"

class GameState
{

public:
	std::vector<SDLGameObject*> m_gameObjects;


	virtual void update() = 0;
	virtual void render() = 0;
	virtual bool onEnter() = 0; 
	virtual bool onExit() = 0;
	virtual std::string getStateID() const = 0;
};