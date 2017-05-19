#pragma once
#include "entity.h"
#include <vector>

class colideMan
{
public:
	static colideMan* getInstance();
	static void create();
	static void destroy();
	void addObj(entity* pObj);
	void removeObj(entity* pObj);
	entity* testCollAABB(entity* pObj);



private:

	colideMan();
	~colideMan();

	static colideMan* m_instance;
	std::vector<entity*> m_colideList;

};

