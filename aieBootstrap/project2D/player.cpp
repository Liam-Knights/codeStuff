#include "player.h"
#include "Input.h"
#include "Matrix3.h"
#include "Vector2.h"
#include "colideMan.h"


using namespace aie;

player::player()
{
	m_bodyT = new Texture("./textures/body.png");
	speed = 600.0f;
	mass = 1.5f;
	drag = 1;
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
	arm->draw(m_2dRender);
}

void player::update(float deltaTime)
{
	Input* input = Input::getInstance();
	Dir = Vector2(0, 0);
	if (input->isKeyDown(INPUT_KEY_W))
	{
		veloc.y += 100;
	}
	if (input->isKeyDown(INPUT_KEY_A))
	{
		Dir = Vector2(-1, 0);
	}
	if (input->isKeyDown(INPUT_KEY_D))
	{
		Dir = Vector2(1, 0);
	}
	Vector2 forcesum = Dir *speed;
	Vector2 acceleration;
	acceleration.x = forcesum.x / mass;
	acceleration.y = forcesum.y / mass;
	Vector2 dampening = -(veloc * drag);
	veloc += (acceleration + dampening) * deltaTime;
	pos = veloc * deltaTime;
	
	Matrix3 changePos;
	changePos[2][0] = pos.x;
	changePos[2][1] = pos.y;
	m_localTransform = m_localTransform * changePos;
	
	updateGlobalTransform();
	arm->update(deltaTime);
	entity* coll = colideMan::getInstance()->testCollAABB(this);
	if (coll != nullptr)
	{
		//mass = 25.0;
		veloc = -veloc;
		//pos = veloc * deltaTime;
	}
	/*else
	{
		mass = 1.5f;
	}*/


	
}