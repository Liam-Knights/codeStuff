#pragma once
#include "entity.h"
#include "playerArm.h"



class player : public entity
{
public:
	//structors
	player();
	~player();

	//draw function
	void Draw(aie::Renderer2D* m_2dRender);
	//update function for the player
	void update(float deltaTime);

private:

	//variables needed for player
	playerArm* arm;
	Vector2 pos;
	Vector2 Dir;
	Vector2 veloc;
	float mass;
	float drag;
	float speed;

};

