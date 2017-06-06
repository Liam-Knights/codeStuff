#include "Vector3.h"
#include<cmath>

using namespace std;

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3()
{

}

Vector3 Vector3::operator+(const Vector3& rhs)
{
	Vector3 result;

	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;

	return result;
}

Vector3 Vector3::operator-(const Vector3& rhs)
{
	Vector3 result;

	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;

	return result;
}

Vector3 Vector3::operator*(const float rhs)
{
	Vector3 result;

	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;

	return result;
}

Vector3 operator*(const float lhs, const Vector3& rhs)
{
	Vector3 result;

	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;

	return result;
}

Vector3 Vector3::operator/(const Vector3& rhs)
{
	Vector3 result;

	result.x = x / rhs.x;
	result.y = y / rhs.y;
	result.z = z / rhs.z;

	return result;
}
Vector3 operator/(const float lhs, const Vector3& rhs)
{
	Vector3 result;

	result.x = lhs / rhs.x;
	result.y = lhs / rhs.y;
	result.z = lhs / rhs.z;

	return result;
}

Vector3 Vector3::operator-()
{
	Vector3 result;

	result.x -= x;
	result.y -= y;
	result.z -= z;
	return result;
}

Vector3 Vector3::operator+=(const Vector3& rhs)
{

	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;

}

float Vector3::dot(Vector3 rhs)
{
	float result;

	result = x * rhs.x + y * rhs.y + z * rhs.z;

	return result;
}

Vector3 Vector3::cross(Vector3& rhs)
{
	Vector3 result;

	result.x = y * rhs.z - z * rhs.y;
	result.y = z * rhs.x - x * rhs.z;
	result.z = x * rhs.y - y * rhs.x;

	return result;

}


float Vector3::magnitude()
{
	float result;

	result = sqrtf(x * x + y * y + z * z);

	return result;

}

float Vector3::normalise()
{
	float magn = magnitude();
	if (magn != 0)
	{
		x = x / magn;
		y = y / magn;
		z = z / magn;

		return magn;
	}

	
}

Vector3::operator float*()
{
	return &x;
}