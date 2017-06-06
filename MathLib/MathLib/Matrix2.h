#pragma once
#include "Vector2.h"

class Matrix2
{
public:

	//matrix 2 constuctor 
	//sets mtx to the initial numbers
	Matrix2();

	//second matrix 2 constuctor 
	//this sets the x and y values for mtx 
	Matrix2(float Xx, float Xy, float Yx, float Yy);

	//matrix 2 destructor
	//this is just a defualt destructor
	~Matrix2();

	////function to do the times of a matrix
	//of the right hand side
	Vector2 operator*(const Vector2& rhs);

	//operator function to overload the [] parameter boxes
	//returns a pointer to a vector
	Vector2& operator[](int index);

	//function to do the times od a matrix
	//against another matrix
	Matrix2 operator*(const Matrix2& rhs);

	//set rotate function
	//this sets the sin and cosin for the matrix
	void setRotate(const float a);

	//function to set scale
	//takes in x and y parameters and sets them to the matrix
	void setScale(const float x, const float y);

	//overloading the * for the matrix variable operator function
	//returns mtx[#][#]
	operator float*();

	//matrix variable used in all the math
	float mtx[2][2];
};

