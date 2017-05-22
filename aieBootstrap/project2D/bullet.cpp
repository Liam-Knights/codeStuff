#include "bullet.h"
#include "entity.h"
#include "Input.h"
#include "Matrix3.h"
#include "Vector2.h"
#include "colideMan.h"


using namespace aie;

bullet::bullet()
{
	speed = 200;
	speedDefault = 200;
	m_bulletT = new Texture("./textures/bullet.png");
	m_localTransform.setpos(2000, 2000);

	float BulletWidth = m_bulletT->getWidth() / 2;
	float BulletHeight = m_bulletT->getHeight() / 2;

	m_collider.m_tl = Vector2(BulletWidth, BulletHeight);
	m_collider.m_br = Vector2(-BulletWidth, -BulletHeight);

	colideMan::getInstance()->addObj(this);

	IsThrown = false;
	IsPickedUp = false;
}


bullet::~bullet()
{
	delete m_bulletT;
}

void bullet::update(float deltaTime)
{
	Matrix3 temp;
	Vector2 Dir = Vector2(0,0);

	temp.setpos(Dir * speed * deltaTime);
	m_localTransform = temp * m_localTransform;

	updateGlobalTransform();
}
