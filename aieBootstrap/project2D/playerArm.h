#pragma once
#include "entity.h"
#include "bullet.h"

class playerArm : public entity
{
public:
	//structors
	playerArm();
	~playerArm();

	//update function
	void update(float deltatime);
	//draw function
	void draw(aie::Renderer2D* m_2dRender);


private:
	//variables for player arm 
	float rotate;
	bullet* bulet;


};

