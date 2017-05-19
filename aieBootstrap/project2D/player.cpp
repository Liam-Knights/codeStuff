#include "player.h"
#include "Input.h"
#include "Matrix3.h"
#include "Vector2.h"
#include "colideMan.h"


using namespace aie;

player::player()
{
	m_bodyT = new Texture("./tectures/body.png");
	speed = 600.0f;
	mass = 1.5f;
	arm = new playerArm;
	arm->setPerent(this);
	setChild(arm);
	colideMan::getInstance()->addObj(this);
}


player::~player()
{
	delete m_bodyT;
	delete arm;
}


void player::Draw(aie::Renderer2D* m_2dRender)
{
	m_2dRender->setCameraPos(m_globalTransform.mtx[2][0] - 640, m_globalTransform.mtx[2][1] - 360);
	m_2dRender->drawSpriteTransformed3x3(m_bodyT, m_globalTransform);
	arm->Draw(m_2dRender);
}

void player::update(float deltaTime)
{
	Input* input = Input::getInstance();
	
}