#include "player.h"
#include "Application2D.h"
#include "Input.h"


player::player()
{
}


player::~player()
{
}



Matrix2 player::gunPos()
{
	Vector2 pos;
	Vector2 target;

	Input* input = Input::getInstance();
}