#include "Vector3.h"
#include<cmath>

using namespace std;

//function to set the variables
Vector3::Vector3()
{
	//seting x and y
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
	//sets the x and y values to match the new x and y
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3()
{
	//default
}

//overloading operator +
Vector3 Vector3::operator+(const Vector3& rhs)
{
	//setting vector to reult
	Vector3 result;

	//setting the right hand side for the vectors
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;

	return result;
}

//overloading operator -
Vector3 Vector3::operator-(const Vector3& rhs)
{
	Vector3 result;

	//setting the negitive of the right hand side for x and y
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;

	return result;
}

//overloading operator *
Vector3 Vector3::operator*(const float rhs)
{
	Vector3 result;

	//multiplication for vector righ hand side
	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;

	return result;
}

//overloading operator *
Vector3 operator*(const float lhs, const Vector3& rhs)
{
	Vector3 result;
	
	//multiplication for x and y value vectors
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;

	return result;
}

//overloading operator /
Vector3 Vector3::operator/(const Vector3& rhs)
{
	Vector3 result;


	//deviding the right hand side for x and y
	result.x = x / rhs.x;
	result.y = y / rhs.y;
	result.z = z / rhs.z;

	return result;
}

//overloading operator /
Vector3 operator/(const float lhs, const Vector3& rhs)
{
	Vector3 result;

	//dividing the x and y values for vector
	result.x = lhs / rhs.x;
	result.y = lhs / rhs.y;
	result.z = lhs / rhs.z;

	return result;
}

//overloading operator -=
Vector3 Vector3::operator-()
{
	Vector3 result;

	//setting the results x and y to its original removing x and y values
	result.x -= x;
	result.y -= y;
	result.z -= z;
	return result;
}

//overloading operator +=
Vector3 Vector3::operator+=(const Vector3& rhs)
{
	//adding x and y to x and y origianl result
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;

}

//vector dot product math
float Vector3::dot(Vector3 rhs)
{
	float result;

	//dot product math
	result = x * rhs.x + y * rhs.y + z * rhs.z;

	return result;
}

//cross product
Vector3 Vector3::cross(Vector3& rhs)
{
	Vector3 result;

	//cross product
	result.x = y * rhs.z - z * rhs.y;
	result.y = z * rhs.x - x * rhs.z;
	result.z = x * rhs.y - y * rhs.x;

	return result;

}


//vector magnitude 
float Vector3::magnitude()
{
	float result;

	//magnitude math
	//square rooting the dot product
	result = sqrtf(x * x + y * y + z * z);

	return result;

}

//normalization of a vector
float Vector3::normalise()
{
	//setting magn to equal the magnitude function
	float magn = magnitude();
	if (magn != 0)
	{
		//deviding x y and z by mang
		x = x / magn;
		y = y / magn;
		z = z / magn;

		return magn;
	}

	
}

Vector3::operator float*()
{
	//returning x
	return &x;
}