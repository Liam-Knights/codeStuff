#include "Matrix2.h"
#include <cmath>

Matrix2::Matrix2()
{
	//the initial numbers for mtx
	//mtx the array for the matrix 

	mtx[0][0] = 1;
	mtx[1][0] = 0;
	mtx[0][1] = 0;
	mtx[1][1] = 1;

}

Matrix2::Matrix2(float Xx, float Xy, float Yx, float Yy)
{
	//the x values for mtx
	mtx[0][0] = Xx;
	mtx[0][1] = Xy;

	//the y values for mtx
	mtx[1][0] = Yx;
	mtx[1][1] = Yy;
}
Matrix2::~Matrix2()
{
	//defualt destructor
}

Vector2 Matrix2::operator*(const Vector2& rhs)
{
	//setting vector to result
	Vector2 result;

	//the multiplication needed for the x and y axis
	result.x = mtx[0][0] * rhs.x + mtx[1][0] * rhs.y;
	result.y = mtx[0][1] * rhs.x + mtx[1][1] * rhs.y;

	//returning result
	return result;
}

Matrix2 Matrix2::operator*(const Matrix2& rhs)
{
	//sets matrix2 to result
	Matrix2 result;

	//multiplicatiojn needed for the right hand side of the matrix
	result.mtx[0][0] = mtx[0][0] * rhs.mtx[0][0] + mtx[0][1] * rhs.mtx[1][0];
	result.mtx[0][1] = mtx[0][0] * rhs.mtx[0][1] + mtx[0][1] * rhs.mtx[1][1];

	result.mtx[1][0] = mtx[1][0] * rhs.mtx[0][0] + mtx[1][1] * rhs.mtx[1][0];
	result.mtx[1][1] = mtx[1][0] * rhs.mtx[0][1] + mtx[1][1] * rhs.mtx[1][1];

	//returning result 
	return result;
}

Vector2& Matrix2::operator[](int index)
{
	//returns a pointer to a vector
	return *(Vector2*)mtx[index];

}

void Matrix2::setRotate(const float a)
{
	//sets the rotate and the position
	mtx[0][0] = cos(a);
	mtx[1][0] = -sin(a);

	mtx[0][1] = sin(a);
	mtx[1][1] = cos(a);
}

Matrix2::operator float*()
{
	//returns mtx
	return &mtx[0][0];
}

void  Matrix2::setScale(const float x, const float y)
{
	//sets the scale for the c and y values
	mtx[0][0] = x;
	mtx[0][1] = 0;

	mtx[1][0] = 0;
	mtx[1][1] = y;

}