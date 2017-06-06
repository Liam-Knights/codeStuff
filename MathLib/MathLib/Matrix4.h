#pragma once
#include "Vector4.h"
#include "Vector3.h"


class Matrix4
{
public:

	//matrix 4 constuctor 
	//sets mtx to the initial numbers
	Matrix4();
	//matrix 4 constuctor
	//this sets mtx to its x,y,z and w values
	Matrix4(float Xx, float Xy, float Xz, float Xw, float Yx, float Yy, float Yz, float Yw, float Zx, float Zy, float Zz, float Zw, float Wx, float Wy, float Wz, float Ww);

	//matrix 4 destructor
	//defualt destructor
	~Matrix4();


	////function to do the times of a matrix
	//of the right hand side
	Vector4 operator*(const Vector4& rhs);

	//operator function to overload the [] parameter boxes
	//returns a pointer to a vector
	Vector4& operator[](int index);

	//function to do the times od a matrix
	//against another matrix
	Matrix4 operator*(const Matrix4& rhs);


	//set rotateX function X axis
	//this sets the sin and cosin for the matrix x axis
	void setRotateX(const float a);

	//set rotateY function Y axis
	//this sets the sin and cosin for the matrix y axis
	void setRotateY(const float a);

	//set rotateZ function Z axis
	//this sets the sin and cosin for the matrix z axis
	void setRotateZ(const float a);

	//function to set scale
	//takes in x, y and z parameters and sets them to the matrix
	void setScale(const float x, const float y, const float z);
	
	//setPos function
	//the set position function for the x and y axis
	void setpos(const float x, const float y, const float z);

	//setPos function
	//the function to set the position of the right hand side
	void setpos(const Vector3& rhs);


	//overloading the * for the matrix variable operator function
	//returns mtx[#][#]
	operator float*();

	//matrix variable used in all the math
	float mtx[4][4];
};