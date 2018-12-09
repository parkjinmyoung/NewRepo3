#include "StateDecorate.h"

StateDecorate::StateDecorate(SDLGameState* state)
{
	super = state;

}

void StateDecorate::update()
{
	super->update();
}

void StateDecorate::render()
{
	super->render();
}

bool StateDecorate::onEnter()
{
	return super->onEnter();
}

bool StateDecorate::onExit()
{
	return super->onExit();
}

bool StateDecorate::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	return S_Play::Instance()->checkCollision(p1,p2);
}