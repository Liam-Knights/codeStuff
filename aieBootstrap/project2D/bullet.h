#pragma once

#include "entity.h"
#include "Matrix2.h"
#include "Vector2.h"

class bullet : public entity
{
public:
	//structors
	bullet();
	~bullet();
	//update functions
	void update(float deltaTime);
	//draw function
	void draw(aie::Renderer2D* m_2dRenderer);
	//shoot function
	void shoot(Vector2 Dir, Vector2 Pos);

private:
	//variables for bullet
	float speed;
	float speedDefault;
	Vector2 direction;
	//variables for bullet
	bool IsThrown;
	bool IsPickedUp;
};

