#include "Vector2.h"
#include<cmath>

using namespace std;

//function to set the variables
Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{

}

//overloading operator +
Vector2 Vector2::operator+(const Vector2& rhs)
{
	Vector2 result;

	result.x = x + rhs.x;
	result.y = y + rhs.y;

	return result;
}

//overloading operator -
Vector2 Vector2::operator-(const Vector2& rhs)
{
	Vector2 result;

	result.x = x - rhs.x;
	result.y = y - rhs.y;

	return result;
}

//overloading operator *
Vector2 Vector2::operator*(const float rhs)
{
	Vector2 result;

	result.x = x * rhs;
	result.y = y * rhs;

	return result;
}

//overloading operator *
Vector2 operator*(const float lhs, const Vector2& rhs)
{
	Vector2 result;

	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;

	return result;
}

//overloading operator /
Vector2 Vector2::operator/(const Vector2& rhs)
{
	Vector2 result;

	result.x = x / rhs.x;
	result.y = y / rhs.y;

	return result;
}

//overloading operator /
Vector2 operator/(const float lhs, const Vector2& rhs)
{
	Vector2 result;

	result.x = lhs / rhs.x;
	result.y = lhs / rhs.y;

	return result;
}

Vector2 Vector2::operator-()
{
	Vector2 result;

	result.x -= x;
	result.y -= y;
	return result;
}

Vector2 Vector2::operator+=(const Vector2& rhs)
{
	
	x += rhs.x;
	y += rhs.y;
	return *this;

}

float Vector2::dot(Vector2 rhs)
{
	float result;

	result = x * rhs.x + y * rhs.y;

	return result;
}

float Vector2::magnitude() 
{
	float result;

	result = sqrtf(x * x + y * y);

	return result;

}

float Vector2::normalise()
{
	float magn = magnitude();
	if (magn != 0)
	{
		x = x / magn;
		y = y / magn;

		return magn;
	}

	
}

Vector2::operator float*()
{
	return &x;
}
