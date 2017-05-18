#pragma once
#include "entity.h"
#include "Matrix2.h"
#include "Vector2.h"
#include "Application.h"
#include "Renderer2D.h"



class player : public entity
{
public:
	player();
	~player();



	Matrix2 gunPos();



};

