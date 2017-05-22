#pragma once
#include "entity.h"
#include "bullet.h"

class playerArm : public entity
{
public:
	playerArm();
	~playerArm();


	void update(float deltatime);

	void draw(aie::Renderer2D* m_2dRender);


private:
	float rotate;
	bullet* bulet;


};

