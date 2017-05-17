#include "entity.h"



entity::entity()
{
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