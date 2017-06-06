#include "Matrix3.h"
#include <cmath>

Matrix3::Matrix3()
{
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
	mtx[0][0] = Xx;
	mtx[0][1] = Xy;
	mtx[0][2] = Xz;

	mtx[1][0] = Yx;
	mtx[1][1] = Yy;
	mtx[1][2] = Yz;

	mtx[2][0] = Zx;
	mtx[2][1] = Zy;
	mtx[2][2] = Zz;

}
Matrix3::~Matrix3()
{
}

Vector3 Matrix3::operator*(const Vector3& rhs)
{

	Vector3 result;

	result.x = mtx[0][0] * rhs.x + mtx[1][0] * rhs.y + mtx[2][0] * rhs.z;
	result.y = mtx[0][1] * rhs.x + mtx[1][1] * rhs.y + mtx[2][1] * rhs.z;
	result.z = mtx[0][2] * rhs.x + mtx[1][2] * rhs.y + mtx[2][2] * rhs.z;

	return result;
}

Matrix3 Matrix3::operator*(const Matrix3& rhs)
{
	Matrix3 result;

	result.mtx[0][0] = mtx[0][0] * rhs.mtx[0][0] + mtx[1][0] * rhs.mtx[0][1] + mtx[2][0] * rhs.mtx[0][2];
	result.mtx[0][1] = mtx[0][1] * rhs.mtx[0][0] + mtx[1][1] * rhs.mtx[0][1] + mtx[2][1] * rhs.mtx[0][2];
	result.mtx[0][2] = mtx[0][2] * rhs.mtx[0][0] + mtx[1][2] * rhs.mtx[0][1] + mtx[2][2] * rhs.mtx[0][2];

	result.mtx[1][0] = mtx[0][0] * rhs.mtx[1][0] + mtx[1][0] * rhs.mtx[1][1] + mtx[2][0] * rhs.mtx[1][2];
	result.mtx[1][1] = mtx[0][1] * rhs.mtx[1][0] + mtx[1][1] * rhs.mtx[1][1] + mtx[2][1] * rhs.mtx[1][2];
	result.mtx[1][2] = mtx[0][2] * rhs.mtx[1][0] + mtx[1][2] * rhs.mtx[1][1] + mtx[2][2] * rhs.mtx[1][2];

	result.mtx[2][0] = mtx[0][0] * rhs.mtx[2][0] + mtx[1][0] * rhs.mtx[2][1] + mtx[2][0] * rhs.mtx[2][2];
	result.mtx[2][1] = mtx[0][1] * rhs.mtx[2][0] + mtx[1][1] * rhs.mtx[2][1] + mtx[2][1] * rhs.mtx[2][2];
	result.mtx[2][2] = mtx[0][2] * rhs.mtx[2][0] + mtx[1][2] * rhs.mtx[2][1] + mtx[2][2] * rhs.mtx[2][2];
	
	return result;
}

Vector3& Matrix3::operator[](int index)
{

	return *(Vector3*)mtx[index];

}

Matrix3::operator float*()
{
	return &mtx[0][0];
}

void Matrix3::setRotateX(const float a)
{
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