#pragma once
#include "Vector3.h"
#include "Vector2.h"


class Matrix3
{
public:

	//matrix 3 constuctor 
	//sets mtx to the initial numbers
	Matrix3();

	//second matrix 3 constuctor 
	//this sets mtx to its X, Y and z values
	Matrix3(float Xx, float Xy, float Xz, float Yx, float Yy, float Yz, float Zx, float Zy, float Zz);

	//matrix 3 destructor
	//this is a defualt destructor
	~Matrix3();


	////function to do the times of a matrix
	//multiplication for the right hand side
	Vector3 operator*(const Vector3& rhs);

	//operator function to overload the [] parameter boxes
	//returns a pointer to a vector
	Vector3& operator[](int index);

	//function to do the times od a matrix
	//against another matrix
	Matrix3 operator*(const Matrix3& rhs);

	//set rotateX function X axis
	//this sets the sin and cosin for the matrix x axis
	void setRotateX(const float a);

	//set rotateY function
	//this sets the sin and cosin for the matrix y axis
	void setRotateY(const float a);

	//set rotateZ function
	//this sets the sin and cosin for the matrix Z axis
	void setRotateZ(const float a);

	//function to set scale
	//takes in x, y and z parameters and sets them to the matrix
	void setScale(const float x, const float y, const float z);

	//setPos function
	//the set position function for the x and y axis
	void setpos(const float x, const float y);

	//setPos function
	//the function to set the position of the right hand side
	void setpos(const Vector2& rhs);


	//overloading the * for the matrix variable operator function
	//returns mtx[#][#]
	operator float*();

	//matrix variable used in all the math
	float mtx[3][3];
};