#include "entity.h"



entity::entity()
{
	m_collider.m_tl = Vector2(-100, -100);
	m_collider.m_br = Vector2(100, 100);
	m_Parent = nullptr;
}


entity::~entity()
{
}

void entity::updateGlobalTransform()
{
	if (m_Parent != nullptr)
	{
		m_globalTransform = m_Parent->m_globalTransform * m_localTransform;
	}
	else
	{
		m_globalTransform = m_localTransform;
	}

	for (auto child : m_Children)
	{
		child->updateGlobalTransform();
	}
}

void entity::setPerent(entity* Parent)
{
	m_Parent = Parent;
}

void entity::setChild(entity* child)
{
	m_Children.push_back(child);
}

void entity::Draw(aie::Renderer2D* m_2dRender)
{}

Vector2 entity::getPos()
{
	Vector2 pos;
	pos.x = m_globalTransform[2][0];
	pos.y = m_globalTransform[2][1];
	return pos;
}
collider& entity::getCollider()
{
	return m_collider;
}