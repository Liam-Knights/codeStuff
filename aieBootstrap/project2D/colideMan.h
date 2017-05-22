#pragma once
#include "entity.h"
#include <vector>
//this is a short virsion of collision manager kinda
class colideMan
{
public:
	//the get instance function
	static colideMan* getInstance();
	//to create the collider for the collider manager
	static void create();
	//to destory when done
	static void destroy();
	//function to set new objecs
	void addObj(entity* pObj);
	//to remove new objects
	void removeObj(entity* pObj);
	//the test collision function
	entity* testCollAABB(entity* pObj);



private:
	//defualt constructer and destructer
	colideMan();
	~colideMan();

	//static collide instance variable
	static colideMan* m_instance;
	//pointer to the colide list
	std::vector<entity*> m_colideList;

};

