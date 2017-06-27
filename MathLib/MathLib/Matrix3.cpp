#include "Matrix3.h"
#include <cmath>

Matrix3::Matrix3()
{

	//the initial numbers for mtx
	//mtx the array for the matrix 
	mtx[0][0] = 1;
	mtx[1][0] = 0;
	mtx[2][0] = 0;

	mtx[0][1] = 0;
	mtx[1][1] = 1;
	mtx[2][1] = 0;
	
	mtx[0][2] = 0;
	mtx[1][2] = 0;
	mtx[2][2] = 1;

}

Matrix3::Matrix3(float Xx, float Xy, float Xz, float Yx, float Yy, float Yz, float Zx, float Zy, float Zz)
{
	//x values for mtx
	mtx[0][0] = Xx;
	mtx[0][1] = Xy;
	mtx[0][2] = Xz;

	//y values for mtx
	mtx[1][0] = Yx;
	mtx[1][1] = Yy;
	mtx[1][2] = Yz;

	//z values fot mtx
	mtx[2][0] = Zx;
	mtx[2][1] = Zy;
	mtx[2][2] = Zz;

}
Matrix3::~Matrix3()
{
	//default
}

Vector3 Matrix3::operator*(const Vector3& rhs)
{
	//setting vector to result
	Vector3 result;

	//sets the multiplication for mtx x y and z
	result.x = mtx[0][0] * rhs.x + mtx[1][0] * rhs.y + mtx[2][0] * rhs.z;
	result.y = mtx[0][1] * rhs.x + mtx[1][1] * rhs.y + mtx[2][1] * rhs.z;
	result.z = mtx[0][2] * rhs.x + mtx[1][2] * rhs.y + mtx[2][2] * rhs.z;

	//returning
	return result;
}

Matrix3 Matrix3::operator*(const Matrix3& rhs)
{
	//sets matrix2 to result
	Matrix3 result;

	//multiplicatiojn needed for the right hand side of the matrix
	result.mtx[0][0] = mtx[0][0] * rhs.mtx[0][0] + mtx[1][0] * rhs.mtx[0][1] + mtx[2][0] * rhs.mtx[0][2];
	result.mtx[0][1] = mtx[0][1] * rhs.mtx[0][0] + mtx[1][1] * rhs.mtx[0][1] + mtx[2][1] * rhs.mtx[0][2];
	result.mtx[0][2] = mtx[0][2] * rhs.mtx[0][0] + mtx[1][2] * rhs.mtx[0][1] + mtx[2][2] * rhs.mtx[0][2];

	result.mtx[1][0] = mtx[0][0] * rhs.mtx[1][0] + mtx[1][0] * rhs.mtx[1][1] + mtx[2][0] * rhs.mtx[1][2];
	result.mtx[1][1] = mtx[0][1] * rhs.mtx[1][0] + mtx[1][1] * rhs.mtx[1][1] + mtx[2][1] * rhs.mtx[1][2];
	result.mtx[1][2] = mtx[0][2] * rhs.mtx[1][0] + mtx[1][2] * rhs.mtx[1][1] + mtx[2][2] * rhs.mtx[1][2];

	result.mtx[2][0] = mtx[0][0] * rhs.mtx[2][0] + mtx[1][0] * rhs.mtx[2][1] + mtx[2][0] * rhs.mtx[2][2];
	result.mtx[2][1] = mtx[0][1] * rhs.mtx[2][0] + mtx[1][1] * rhs.mtx[2][1] + mtx[2][1] * rhs.mtx[2][2];
	result.mtx[2][2] = mtx[0][2] * rhs.mtx[2][0] + mtx[1][2] * rhs.mtx[2][1] + mtx[2][2] * rhs.mtx[2][2];
	
	//returns result
	return result;
}

Vector3& Matrix3::operator[](int index)
{
	//returns a pointer to a vector
	return *(Vector3*)mtx[index];

}

Matrix3::operator float*()
{
	//returns mtx
	return &mtx[0][0];
}

void Matrix3::setRotateX(const float a)
{
	//sets the rotate function for the x value
	mtx[0][0] = 1;
	mtx[1][0] = 0;
	mtx[2][0] = 0;

	mtx[0][1] = 0;
	mtx[1][1] = cos(a);
	mtx[2][1] = -sin(a);

	mtx[0][2] = 0;
	mtx[1][2] = sin(a);
	mtx[2][2] = cos(a);
}

void Matrix3::setRotateY(const float a)
{
	//sets the rotate function fot the y value
	mtx[0][0] = cos(a);
	mtx[1][0] = 0;
	mtx[2][0] = sin(a);

	mtx[0][1] = 0;
	mtx[1][1] = 1;
	mtx[2][1] = 0;

	mtx[0][2] = -sin(a);
	mtx[1][2] = 0;
	mtx[2][2] = cos(a);
}

void Matrix3::setRotateZ(const float a)
{
	//sets the rotate function for the z value
	mtx[0][0] = cos(a);
	mtx[1][0] = -sin(a);
	mtx[2][0] = 0;

	mtx[0][1] = sin(a);
	mtx[1][1] = cos(a);
	mtx[2][1] = 0;

	mtx[0][2] = 0;
	mtx[1][2] = 0;
	mtx[2][2] = 1;
}

void  Matrix3::setScale(const float x, const float y, const float z)
{
	//sets the scale for the x y and z values
	mtx[0][0] = x;
	mtx[0][1] = 0;
	mtx[0][2] = 0;

	mtx[1][0] = 0;
	mtx[1][1] = y;
	mtx[1][2] = 0;

	mtx[2][0] = 0;
	mtx[2][1] = 0;
	mtx[2][2] = z;

}

void  Matrix3::setpos(const float x, const float y)
{
	//sets the position of the x y and z matrix
	mtx[0][0] = 1;
	mtx[0][1] = 0;
	mtx[0][2] = x;

	mtx[1][0] = 0;
	mtx[1][1] = 1;
	mtx[1][2] = y;

	mtx[2][0] = 0;
	mtx[2][1] = 0;
	mtx[2][2] = 1;
}

void  Matrix3::setpos(const Vector2& rhs)
{
	//sets the position for the right hand side for x y and z
	mtx[0][0] = 1;
	mtx[0][1] = 0;
	mtx[0][2] = rhs.x;

	mtx[1][0] = 0;
	mtx[1][1] = 1;
	mtx[1][2] = rhs.y;

	mtx[2][0] = 0;
	mtx[2][1] = 0;
	mtx[2][2] = 1;

}