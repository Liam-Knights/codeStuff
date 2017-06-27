#include "Matrix4.h"
#include <cmath>

Matrix4::Matrix4()
{
	//the initial numbers for mtx
	//mtx the array for the matrix 
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
	//x value for mtx
	mtx[0][0] = Xx;
	mtx[0][1] = Xy;
	mtx[0][2] = Xz;
	mtx[0][3] = Xw;
					
	//y value for mtx
	mtx[1][0] = Yx;
	mtx[1][1] = Yy;
	mtx[1][2] = Yz;
	mtx[1][3] = Yw;
					
	//z value for mtx
	mtx[2][0] = Zx;
	mtx[2][1] = Zy;
	mtx[2][2] = Zz;
	mtx[2][3] = Zw;
						
	//w value for mtx
	mtx[3][0] = Wx;
	mtx[3][1] = Wy;
	mtx[3][2] = Wz;
	mtx[3][3] = Ww;
								   
}
Matrix4::~Matrix4()
{
	//default destructor
}

Vector4 Matrix4::operator*(const Vector4& rhs)
{
	//setting vector to result
	Vector4 result;

	//sets the multiplication for mtx x y z and w
	result.x = mtx[0][0] * rhs.x + mtx[1][0] * rhs.y + mtx[2][0] * rhs.z + mtx[3][0] * rhs.w;
	result.y = mtx[0][1] * rhs.x + mtx[1][1] * rhs.y + mtx[2][1] * rhs.z + mtx[3][1] * rhs.w;
	result.z = mtx[0][2] * rhs.x + mtx[1][2] * rhs.y + mtx[2][2] * rhs.z + mtx[3][2] * rhs.w;
	result.w = mtx[0][3] * rhs.x + mtx[1][3] * rhs.y + mtx[2][3] * rhs.z + mtx[3][3] * rhs.w;

	//returns result
	return result;
}

Matrix4 Matrix4::operator*(const Matrix4& rhs)
{
	//setting matrix to result
	Matrix4 result;

	//multiplicatiojn needed for the right hand side of the matrix
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

	//returns result
	return result;
}

Vector4& Matrix4::operator[](int index)
{
	//returns a pointer to a vector
	return *(Vector4*)mtx[index];

	
}

Matrix4::operator float*()
{
	//returns mtx
	return &mtx[0][0];
}

void Matrix4::setRotateX(const float a)
{
	//sets rotate for x
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
	//sets rotate for y
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
	//sets rotate for z

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

	//sets the scale 
	//sets what would be w to 1
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
	//sets the position for the x y and z
	//sets what would be w to 1
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
	//sets the position for the right hand side for x y and z
	//sets what would be w to 1
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