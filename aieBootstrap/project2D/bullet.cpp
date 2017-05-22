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
	//m_localTransform.setpos(2000, 2000);

	float BulletWidth = m_bulletT->getWidth() / 2;
	float BulletHeight = m_bulletT->getHeight() / 2;

	m_collider.m_tl = Vector2(BulletWidth, BulletHeight);
	m_collider.m_br = Vector2(-BulletWidth, -BulletHeight);

	//colideMan::getInstance()->addObj(this);

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

	temp[2][0]= (direction.x * speed * deltaTime);
	temp[2][1] = (direction.y * speed * deltaTime);
	m_localTransform = m_localTransform * temp;

	updateGlobalTransform();
}

void bullet::shoot(Vector2 Dir, Vector2 Pos)
{
	direction = Dir;
	m_localTransform[2][0] = Pos.x;
	m_localTransform[2][1] = Pos.y;
	updateGlobalTransform();
}

void bullet::draw(aie::Renderer2D* m_2dRender)
{
	m_2dRender->drawSpriteTransformed3x3(m_bulletT, m_globalTransform);
}
