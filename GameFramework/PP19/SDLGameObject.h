#pragma once
#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	SDLGameObject(const LoaderParams* pParams, int n);
	virtual void draw();
	virtual void update();
	virtual void clean();

	bool checkCollision(SDLGameObject* wall);

	Vector2D& getPosition() { return m_position; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }

	virtual void GameObjectDelete();
	string Tag = "";

protected:

	int Order;

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;
};