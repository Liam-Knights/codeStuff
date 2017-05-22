#include "enemy.h"
#include "Input.h"
#include "Matrix3.h"
#include "Vector2.h"
#include "colideMan.h"


using namespace aie;

//constructor setting the position and the texture
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

//destructor for deleting the new
enemy::~enemy()
{
	delete m_enemyT;
}

//draw function
void enemy::Draw(aie::Renderer2D* m_2dRender)
{
	m_2dRender->drawSpriteTransformed3x3(m_enemyT, m_globalTransform);
}

//update function
void enemy::update(float deltaTime, aie::Renderer2D * m_Rederm_2dRender)
{

}