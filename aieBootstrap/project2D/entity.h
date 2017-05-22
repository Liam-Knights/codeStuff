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
	//constructer
	entity();
	//destructer
	~entity();
	//the function to set the parent for each of the classes
	void setPerent(entity* Parent);
	//the function to set the child for each pof the classes
	void setChild(entity* child);

	//function made to update the entire program
	void updateGlobalTransform();
	// a basic draw function it is epmty
	virtual void Draw(aie::Renderer2D* m_2dRender);

	//get position function for both enemy and player to be placed on screen
	Vector2 getPos();
	// get collider to enable collisions
	collider& getCollider();

protected:

	//local transform variable
	Matrix3 m_localTransform;
	//global transform variable
	Matrix3 m_globalTransform;

	//collider variabl;e
	collider m_collider;

	//pointer to a parent
	entity* m_Parent;
	std::vector<entity*> m_Children;

	aie::Texture* m_bodyT;
	aie::Texture* m_armT;
	aie::Texture* m_bulletT;
	aie::Texture* m_enemyT;
	aie::Texture* m_groundT;
	aie::Texture* m_backgroundT;

};

