#pragma once
#include "entity.h"

class enemy : public entity
{
public:
	enemy();
	~enemy();

	void Draw(aie::Renderer2D* m_2dRender);
	void update(float deltaTime, aie::Renderer2D * m_Rederm_2dRender);

private:
};

