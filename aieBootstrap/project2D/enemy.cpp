#include "enemy.h"
#include "Input.h"
#include "Matrix3.h"
#include "Vector2.h"
#include "colideMan.h"


using namespace aie;

enemy::enemy()
{
	m_enemyT = new Texture("./textures/slime.png");
	

	Matrix3 changePos;
	changePos[2][0] = -300;
	changePos[2][1] = 0;
	m_localTransform = m_localTransform * changePos;

	colideMan::getInstance()->addObj(this);
	updateGlobalTransform();
}


enemy::~enemy()
{
	delete m_enemyT;
}


void enemy::Draw(aie::Renderer2D* m_2dRender)
{
	m_2dRender->drawSpriteTransformed3x3(m_enemyT, m_globalTransform);
}

void enemy::update(float deltaTime, aie::Renderer2D * m_Rederm_2dRender)
{

}