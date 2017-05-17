#pragma once
#include "entity.h"
#include "Matrix2.h"
#include <Vector>

class player : public entity
{
public:
	player();
	~player();


	Matrix2 positon;



};

