#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{

private:
	int speed = 1;
	int temp = 0;
public:
	Enemy(int s);
	void update();
};