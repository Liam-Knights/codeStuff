#include "Matrix4.h"
#include <cmath>

Matrix4::Matrix4()
{
	mtx[0][0] = 1;
	mtx[1][0] = 0;
	mtx[2][0] = 0;
	mtx[3][0] = 0;

	mtx[0][1] = 0;
	mtx[1][1] = 1;
	mtx[2][1] = 0;
	mtx[3][1] = 0;

	mtx[0][2] = 0;
	mtx[1][2] = 0;
	mtx[2][2] = 1;
	mtx[3][2] = 0;

	mtx[0][3] = 0;
	mtx[1][3] = 0;
	mtx[2][3] = 0;
	mtx[3][3] = 1;

}

Matrix4::Matrix4(float Xx, float Xy, float Xz, float Xw, float Yx, float Yy, float Yz, float Yw, float Zx, float Zy, float Zz, float Zw, float Wx, float Wy, float Wz, float Ww)
{								   
	mtx[0][0] = Xx;
	mtx[0][1] = Xy;
	mtx[0][2] = Xz;
	mtx[0][3] = Xw;
								   
	mtx[1][0] = Yx;
	mtx[1][1] = Yy;
	mtx[1][2] = Yz;
	mtx[1][3] = Yw;
								   
	mtx[2][0] = Zx;
	mtx[2][1] = Zy;
	mtx[2][2] = Zz;
	mtx[2][3] = Zw;
								   
	mtx[3][0] = Wx;
	mtx[3][1] = Wy;
	mtx[3][2] = Wz;
	mtx[3][3] = Ww;
								   
}
Matrix4::~Matrix4()
{
}

Vector4 Matrix4::operator*(const Vector4& rhs)
{

	Vector4 result;

	result.x = mtx[0][0] * rhs.x + mtx[1][0] * rhs.y + mtx[2][0] * rhs.z + mtx[3][0] * rhs.w;
	result.y = mtx[0][1] * rhs.x + mtx[1][1] * rhs.y + mtx[2][1] * rhs.z + mtx[3][1] * rhs.w;
	result.z = mtx[0][2] * rhs.x + mtx[1][2] * rhs.y + mtx[2][2] * rhs.z + mtx[3][2] * rhs.w;
	result.w = mtx[0][3] * rhs.x + mtx[1][3] * rhs.y + mtx[2][3] * rhs.z + mtx[3][3] * rhs.w;

	return result;
}

Matrix4 Matrix4::operator*(const Matrix4& rhs)
{
	Matrix4 result;

	result.mtx[0][0] = mtx[0][0] * rhs.mtx[0][0] + mtx[1][0] * rhs.mtx[0][1] + mtx[2][0] * rhs.mtx[0][2] + mtx[3][0] * rhs.mtx[0][3];
	result.mtx[0][1] = mtx[0][1] * rhs.mtx[0][0] + mtx[1][1] * rhs.mtx[0][1] + mtx[2][1] * rhs.mtx[0][2] + mtx[3][1] * rhs.mtx[0][3];
	result.mtx[0][2] = mtx[0][2] * rhs.mtx[0][0] + mtx[1][2] * rhs.mtx[0][1] + mtx[2][2] * rhs.mtx[0][2] + mtx[3][2] * rhs.mtx[0][3];
	result.mtx[0][3] = mtx[0][3] * rhs.mtx[0][0] + mtx[1][3] * rhs.mtx[0][1] + mtx[2][3] * rhs.mtx[0][2] + mtx[3][3] * rhs.mtx[0][3];

	result.mtx[1][0] = mtx[0][0] * rhs.mtx[1][0] + mtx[1][0] * rhs.mtx[1][1] + mtx[2][0] * rhs.mtx[1][2] + mtx[3][0] * rhs.mtx[1][3];
	result.mtx[1][1] = mtx[0][1] * rhs.mtx[1][0] + mtx[1][1] * rhs.mtx[1][1] + mtx[2][1] * rhs.mtx[1][2] + mtx[3][1] * rhs.mtx[1][3];
	result.mtx[1][2] = mtx[0][2] * rhs.mtx[1][0] + mtx[1][2] * rhs.mtx[1][1] + mtx[2][2] * rhs.mtx[1][2] + mtx[3][2] * rhs.mtx[1][3];
	result.mtx[1][3] = mtx[0][3] * rhs.mtx[1][0] + mtx[1][3] * rhs.mtx[1][1] + mtx[2][3] * rhs.mtx[1][2] + mtx[3][3] * rhs.mtx[1][3];

	result.mtx[2][0] = mtx[0][0] * rhs.mtx[2][0] + mtx[1][0] * rhs.mtx[2][1] + mtx[2][0] * rhs.mtx[2][2] + mtx[3][0] * rhs.mtx[2][3];
	result.mtx[2][1] = mtx[0][1] * rhs.mtx[2][0] + mtx[1][1] * rhs.mtx[2][1] + mtx[2][1] * rhs.mtx[2][2] + mtx[3][1] * rhs.mtx[2][3];
	result.mtx[2][2] = mtx[0][2] * rhs.mtx[2][0] + mtx[1][2] * rhs.mtx[2][1] + mtx[2][2] * rhs.mtx[2][2] + mtx[3][2] * rhs.mtx[2][3];
	result.mtx[2][3] = mtx[0][3] * rhs.mtx[2][0] + mtx[1][3] * rhs.mtx[2][1] + mtx[2][3] * rhs.mtx[2][2] + mtx[3][3] * rhs.mtx[2][3];

	result.mtx[3][0] = mtx[0][0] * rhs.mtx[3][0] + mtx[1][0] * rhs.mtx[3][1] + mtx[2][0] * rhs.mtx[3][2] + mtx[3][0] * rhs.mtx[3][3];
	result.mtx[3][1] = mtx[0][1] * rhs.mtx[3][0] + mtx[1][1] * rhs.mtx[3][1] + mtx[2][1] * rhs.mtx[3][2] + mtx[3][1] * rhs.mtx[3][3];
	result.mtx[3][2] = mtx[0][2] * rhs.mtx[3][0] + mtx[1][2] * rhs.mtx[3][1] + mtx[2][2] * rhs.mtx[3][2] + mtx[3][2] * rhs.mtx[3][3];
	result.mtx[3][3] = mtx[0][3] * rhs.mtx[3][0] + mtx[1][3] * rhs.mtx[3][1] + mtx[2][3] * rhs.mtx[3][2] + mtx[3][3] * rhs.mtx[3][3];

	return result;
}

Vector4& Matrix4::operator[](int index)
{

	return *(Vector4*)mtx[index];

	
}

Matrix4::operator float*()
{
	return &mtx[0][0];
}

void Matrix4::setRotateX(const float a)
{
	mtx[0][0] = 1;
	mtx[1][0] = 0;
	mtx[2][0] = 0;
	mtx[3][0] = 0;

	mtx[0][1] = 0;
	mtx[1][1] = cos(a);
	mtx[2][1] = -sin(a);
	mtx[3][1] = 0;

	mtx[0][2] = 0;
	mtx[1][2] = sin(a);
	mtx[2][2] = cos(a);
	mtx[3][2] = 0;

	mtx[0][3] = 0;
	mtx[1][3] = 0;
	mtx[2][3] = 0;
	mtx[3][3] = 1;
}

void Matrix4::setRotateY(const float a)
{
	mtx[0][0] = cos(a);
	mtx[1][0] = 0;
	mtx[2][0] = sin(a);
	mtx[3][0] = 0;

	mtx[0][1] = 0;
	mtx[1][1] = 1;
	mtx[2][1] = 0;
	mtx[3][1] = 0;

	mtx[0][2] = -sin(a);
	mtx[1][2] = 0;
	mtx[2][2] = cos(a);
	mtx[3][2] = 0;

	mtx[0][3] = 0;
	mtx[1][3] = 0;
	mtx[2][3] = 0;
	mtx[3][3] = 1;
}

void Matrix4::setRotateZ(const float a)
{
	mtx[0][0] = cos(a);
	mtx[1][0] = -sin(a);
	mtx[2][0] = 0;
	mtx[3][0] = 0;

	mtx[0][1] = sin(a);
	mtx[1][1] = cos(a);
	mtx[2][1] = 0;
	mtx[3][1] = 0;

	mtx[0][2] = 0;
	mtx[1][2] = 0;
	mtx[2][2] = 1;
	mtx[3][2] = 0;

	mtx[0][3] = 0;
	mtx[1][3] = 0;
	mtx[2][3] = 0;
	mtx[3][3] = 1;
}

void  Matrix4::setScale(const float x, const float y, const float z)
{

	mtx[0][0] = x;
	mtx[0][1] = 0;
	mtx[0][2] = 0;
	mtx[0][3] = 0;

	mtx[1][0] = 0;
	mtx[1][1] = y;
	mtx[1][2] = 0;
	mtx[1][3] = 0;

	mtx[2][0] = 0;
	mtx[2][1] = 0;
	mtx[2][2] = z;
	mtx[2][3] = 0;

	mtx[3][0] = 0;
	mtx[3][1] = 0;
	mtx[3][2] = 0;
	mtx[3][3] = 1;
}

void  Matrix4::setpos(const float x, const float y, const float z)
{
	mtx[0][0] = 1;
	mtx[0][1] = 0;
	mtx[0][2] = 0;
	mtx[0][3] = x;

	mtx[1][0] = 0;
	mtx[1][1] = 1;
	mtx[1][2] = 0;
	mtx[1][3] = y;

	mtx[2][0] = 0;
	mtx[2][1] = 0;
	mtx[2][2] = 1;
	mtx[2][3] = z;

	mtx[3][0] = 0;
	mtx[3][1] = 0;
	mtx[3][2] = 0;
	mtx[3][3] = 1;
}

void  Matrix4::setpos(const Vector3& rhs)
{
	mtx[0][0] = 1;
	mtx[0][1] = 0;
	mtx[0][2] = 0;
	mtx[0][3] = rhs.x;

	mtx[1][0] = 0;
	mtx[1][1] = 1;
	mtx[1][2] = 0;
	mtx[1][3] = rhs.y;

	mtx[2][0] = 0;
	mtx[2][1] = 0;
	mtx[2][2] = 1;
	mtx[2][3] = rhs.z;

	mtx[3][0] = 0;
	mtx[3][1] = 0;
	mtx[3][2] = 0;
	mtx[3][3] = 1;
}