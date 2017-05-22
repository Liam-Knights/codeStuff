#pragma once
#include "entity.h"

class enemy : public entity
{
public:
	//structors
	enemy();
	~enemy();

	//draw function
	void Draw(aie::Renderer2D* m_2dRender);
	//update function
	void update(float deltaTime, aie::Renderer2D * m_Rederm_2dRender);

private:
};

