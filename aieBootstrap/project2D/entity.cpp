#include "entity.h"


//constructer setting the scaler for the collider and setting the initial parent to null
entity::entity()
{
	m_collider.m_tl = Vector2(-100, -100);
	m_collider.m_br = Vector2(100, 100);
	m_Parent = nullptr;
}

//default destructor
entity::~entity()
{
}

//function made to update the entire program
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

//the function to se the parent
void entity::setPerent(entity* Parent)
{
	m_Parent = Parent;
}

//the function to set the child
void entity::setChild(entity* child)
{
	m_Children.push_back(child);
}

// a deafualt draw function it is empty
void entity::Draw(aie::Renderer2D* m_2dRender)
{}

//get position function
Vector2 entity::getPos()
{
	Vector2 pos;
	pos.x = m_globalTransform[2][0];
	pos.y = m_globalTransform[2][1];
	return pos;
}

//the function to get the collider
collider& entity::getCollider()
{
	return m_collider;
}