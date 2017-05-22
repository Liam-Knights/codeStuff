#include "colideMan.h"
#include <iostream>

//setting the instance to null to start
colideMan* colideMan::m_instance = nullptr;

//defualt
colideMan::colideMan()
{
}

//default
colideMan::~colideMan()
{
}
//the get instance function
colideMan* colideMan::getInstance()
{
	return m_instance;
}
//creating a new instance
void colideMan::create()
{
	if (!m_instance)
	{
		m_instance = new colideMan();
	}
}

//destroying when done with instance
void colideMan::destroy()
{
	delete m_instance;
}

//adding an object
void colideMan::addObj(entity* pObj)
{
	m_colideList.push_back(pObj);
}

//removeing an object
void colideMan::removeObj(entity* pObj)
{
	auto iterate = find(m_colideList.begin(), m_colideList.end(), pObj);
	if(iterate != m_colideList.end())
	{
		m_colideList.erase(iterate);
	}
}

//testing the collision
entity* colideMan::testCollAABB(entity* pObj)
{
	for(unsigned int i = 0; i < m_colideList.size(); ++i)
	{
		if (pObj == m_colideList[i])
		{
			continue;
		}
		collider collider1 = pObj->getCollider();
		collider1.m_tl = collider1.m_tl + pObj->getPos();
		collider1.m_br = collider1.m_br + pObj->getPos();

		collider collider2 = m_colideList[i]->getCollider();
		collider2.m_tl = collider2.m_tl + m_colideList[i]->getPos();
		collider2.m_br = collider2.m_br + m_colideList[i]->getPos();

		if (collider1.m_br.x > collider2.m_tl.x &&
			collider1.m_br.y > collider2.m_tl.y &&
			collider1.m_tl.x < collider2.m_br.x &&
			collider1.m_tl.y < collider2.m_br.y)
		{
			return m_colideList[i];
		}

	}
	return nullptr;
}