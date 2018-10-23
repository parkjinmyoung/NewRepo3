#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{

private:
	int speed = 1;
	int temp = 0;

public:
	Enemy(int s);
	//void load(int x, int y, int width, int height,
	//	std::string textureID);
	//void draw(SDL_Renderer* pRenderer);
	void update();
	//void clean();

};