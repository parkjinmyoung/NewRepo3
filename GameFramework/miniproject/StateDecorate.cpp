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
