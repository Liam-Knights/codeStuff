#pragma once

#include "entity.h"
#include "Matrix2.h"
#include "Vector2.h"

class bullet : public entity
{
public:
	bullet();
	~bullet();

	void update(float deltaTime);
	void draw(aie::Renderer2D* m_2dRenderer);
	void shoot(Vector2 Dir, Vector2 Pos);

private:

	float speed;
	float speedDefault;
	Vector2 direction;

	bool IsThrown;
	bool IsPickedUp;
};

