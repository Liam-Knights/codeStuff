#pragma once
#include "entity.h"
#include "playerArm.h"



class player : public entity
{
public:
	player();
	~player();

	void Draw(aie::Renderer2D* m_2dRender);
	void update(float deltaTime);

private:

	playerArm* arm;
	Vector2 pos;
	Vector2 Dir;
	Vector2 veloc;
	float mass;
	float drag;
	float speed;

};

