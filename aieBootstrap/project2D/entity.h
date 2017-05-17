#pragma once
#include "Matrix3.h"
#include <Vector>

class entity
{
public:
	
	entity* m_Parent;
	std::vector<entity*> m_Children;

	entity();
	~entity();

	Matrix3 m_localTransform;
	Matrix3 m_globalTransform;

	void updateGlobalTransform();
	void rotate(float angle);

	

};

