#pragma once

#include "playerArm.h"
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
private:

	float speed;
	float speedDefault;
	Vector3 direction;

	bool IsThrown;
	bool IsPickedUp;
};

