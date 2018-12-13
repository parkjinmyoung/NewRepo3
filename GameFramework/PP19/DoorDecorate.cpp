#include "DoorDecorate.h"
#include "PlayState.h"

DoorDecorate::DoorDecorate(SDLGameState* state) : StateDecorate(state)
{
	super = state;
}

void DoorDecorate::update()
{
	super->update();
}

void DoorDecorate::render()
{
	super->render();
}

bool DoorDecorate::onEnter()
{
	bool c = super->onEnter();



	return c;
}

bool DoorDecorate::onExit()
{
	return super->onExit();
}