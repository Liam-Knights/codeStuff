#pragma once
#include "Matrix3.h"
#include <Vector>
#include "Matrix2.h"
#include "Vector2.h"
#include "Application.h"
#include "Renderer2D.h"
#include "colider.h"
#include "Texture.h"

class entity
{
public:

	entity();
	~entity();

	void setPerent(entity* Parent);
	void setChild(entity* child);

	void updateGlobalTransform();
	virtual void Draw(aie::Renderer2D* m_2dRender);

	Vector2 getPos();
	collider& getCollider();

protected:
	Matrix3 m_localTransform;
	Matrix3 m_globalTransform;

	collider m_collider;

	entity* m_Parent;
	std::vector<entity*> m_Children;

	aie::Texture* m_bodyT;
	aie::Texture* m_armT;
	aie::Texture* m_bulletT;
	aie::Texture* m_enemyT;
	aie::Texture* m_groundT;
	aie::Texture* m_backgroundT;

};

