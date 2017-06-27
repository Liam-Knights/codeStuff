#include "Vector4.h"
#include<cmath>

using namespace std;

//function to set the variables
Vector4::Vector4()
{
	//seting x and y
	x = 0;
	y = 0;
	z = 0;
	w = 1.0f;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	//sets the x and y values to match the new x and y
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4::~Vector4()
{
	//default
}

//overloading operator +
Vector4 Vector4::operator+(const Vector4& rhs)
{
	Vector4 result;

	//setting the right hand side for the vectors
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;
	result.w = w + rhs.w;

	return result;
}

//overloading operator -
Vector4 Vector4::operator-(const Vector4& rhs)
{
	Vector4 result;


	//setting the negitive of the right hand side for x and y
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;
	result.w = w - rhs.w;

	return result;
}

//overloading operator *
Vector4 Vector4::operator*(const float rhs)
{
	Vector4 result;

	//multiplication for vector righ hand side
	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;
	result.w = w * rhs;

	return result;
}

//overloading operator *
Vector4 operator*(const float lhs, const Vector4& rhs)
{
	Vector4 result;

	//multiplication for x and y value vectors
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;
	result.w = lhs * rhs.w;

	return result;
}

//overloading operator /
Vector4 Vector4::operator/(const Vector4& rhs)
{
	Vector4 result;

	//deviding the right hand side for x and y
	result.x = x / rhs.x;
	result.y = y / rhs.y;
	result.z = z / rhs.z;
	result.w = w / rhs.w;

	return result;
}

//overloading operator /
Vector4 operator/(const float lhs, const Vector4& rhs)
{
	Vector4 result;

	//dividing the x and y values for vector
	result.x = lhs / rhs.x;
	result.y = lhs / rhs.y;
	result.z = lhs / rhs.z;
	result.w = lhs / rhs.w;

	return result;
}

//overloading operator -=
Vector4 Vector4::operator-()
{
	Vector4 result;

	//setting the results x and y to its original removing x and y values
	result.x -= x;
	result.y -= y;
	result.z -= z;
	result.w -= w;

	return result;
}

//overloading operator +=
Vector4 Vector4::operator+=(const Vector4& rhs)
{

	//adding x and y to x and y origianl result
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;

	return *this;

}

//DOT PRODUCT MATH
float Vector4::dot(Vector4 rhs)
{
	float result;

	//dot product math
	result = x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;

	return result;
}

//CROSS PRODUCT MATH
Vector4 Vector4::cross(Vector4& rhs)
{
	Vector4 result;

	//cross product
	result.x = y * rhs.z - z * rhs.y;
	result.y = z * rhs.x - x * rhs.z;
	result.z = x * rhs.y - y * rhs.x;
	result.w = 0;

	return result;

}


//vector magnitude
float Vector4::magnitude()
{
	float result;

	//magnitude math
	//square rooting the dot product
	result = sqrtf(x * x + y * y + z * z + w * w);

	return result;

}

//normalization of a vector
float Vector4::normalise()
{
	//setting magn to equal the magnitude function
	float magn = magnitude();
	if (magn != 0)
	{
		//deviding x y z and w by mang
		x = x / magn;
		y = y / magn;
		z = z / magn;
		w = w / magn;

		return magn;
	}


}
Vector4::operator float*()
{
	//returning x
	return &x;
}