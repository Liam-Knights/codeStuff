#include "Vector2.h"
#include<cmath>

using namespace std;

//function to set the variables
Vector2::Vector2()
{
	//seting x and y
	x = 0;
	y = 0;
}

Vector2::Vector2(float x, float y)
{
	//sets the x and y values to match the new x and y
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{
	//default
}

//overloading operator +
Vector2 Vector2::operator+(const Vector2& rhs)
{
	//setting vector to reult
	Vector2 result;

	//setting the right hand side for the vectors
	result.x = x + rhs.x;
	result.y = y + rhs.y;

	//returning result
	return result;
}

//overloading operator -
Vector2 Vector2::operator-(const Vector2& rhs)
{
	//setting vector to result
	Vector2 result;

	//setting the negitive of the right hand side for x and y
	result.x = x - rhs.x;
	result.y = y - rhs.y;

	//returning result
	return result;
}

//overloading operator *
Vector2 Vector2::operator*(const float rhs)
{
	//setting vector to result
	Vector2 result;

	//multiplication for vector righ hand side
	result.x = x * rhs;
	result.y = y * rhs;

	//returning result
	return result;
}

//overloading operator *
Vector2 operator*(const float lhs, const Vector2& rhs)
{
	//setting vector to result
	Vector2 result;

	//multiplication for x and y value vectors
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;

	return result;
}

//overloading operator /
Vector2 Vector2::operator/(const Vector2& rhs)
{
	//getting vector as result
	Vector2 result;

	//deviding the right hand side for x and y
	result.x = x / rhs.x;
	result.y = y / rhs.y;

	//returning result
	return result;
}

//overloading operator /
Vector2 operator/(const float lhs, const Vector2& rhs)
{
	//vector is now result
	Vector2 result;

	//dividing the x and y values for vector
	result.x = lhs / rhs.x;
	result.y = lhs / rhs.y;

	//returning result
	return result;
}

//overlaoding operator -=
Vector2 Vector2::operator-()
{
	//setting vector to result
	Vector2 result;

	//setting the results x and y to its original removing x and y values
	result.x -= x;
	result.y -= y;

	//returning result
	return result;
}

//overloading operator +=
Vector2 Vector2::operator+=(const Vector2& rhs)
{
	//adding x and y to x and y origianl result
	x += rhs.x;
	y += rhs.y;
	return *this;

}

//vector dot product math
float Vector2::dot(Vector2 rhs)
{
	float result;

	//dot product math
	result = x * rhs.x + y * rhs.y;

	//returning result
	return result;
}

//vector magnitude 
float Vector2::magnitude() 
{
	float result;

	//magnitude math
	//square rooting the dot product
	result = sqrtf(x * x + y * y);

	return result;

}

//normalization of a vector
float Vector2::normalise()
{
	//setting magn to equal the magnitude function
	float magn = magnitude();
	// if magn isnt 0 
	if (magn != 0)
	{
		//deviding x and y by mang
		x = x / magn;
		y = y / magn;

		//returning magn
		return magn;
	}

	
}

//float variable pointer overloader
Vector2::operator float*()
{
	//returning x
	return &x;
}
