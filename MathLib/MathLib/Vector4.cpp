#include "Vector4.h"
#include<cmath>

using namespace std;

Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 1.0f;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4::~Vector4()
{

}

Vector4 Vector4::operator+(const Vector4& rhs)
{
	Vector4 result;

	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;
	result.w = w + rhs.w;

	return result;
}

Vector4 Vector4::operator-(const Vector4& rhs)
{
	Vector4 result;

	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;
	result.w = w - rhs.w;

	return result;
}

Vector4 Vector4::operator*(const float rhs)
{
	Vector4 result;

	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;
	result.w = w * rhs;

	return result;
}

Vector4 operator*(const float lhs, const Vector4& rhs)
{
	Vector4 result;

	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;
	result.w = lhs * rhs.w;

	return result;
}

Vector4 Vector4::operator/(const Vector4& rhs)
{
	Vector4 result;

	result.x = x / rhs.x;
	result.y = y / rhs.y;
	result.z = z / rhs.z;
	result.w = w / rhs.w;

	return result;
}
Vector4 operator/(const float lhs, const Vector4& rhs)
{
	Vector4 result;

	result.x = lhs / rhs.x;
	result.y = lhs / rhs.y;
	result.z = lhs / rhs.z;
	result.w = lhs / rhs.w;

	return result;
}

Vector4 Vector4::operator-()
{
	Vector4 result;

	result.x -= x;
	result.y -= y;
	result.z -= z;
	result.w -= w;

	return result;
}

Vector4 Vector4::operator+=(const Vector4& rhs)
{

	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;

	return *this;

}

float Vector4::dot(Vector4 rhs)
{
	float result;

	result = x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;

	return result;
}

Vector4 Vector4::cross(Vector4& rhs)
{
	Vector4 result;

	result.x = y * rhs.z - z * rhs.y;
	result.y = z * rhs.x - x * rhs.z;
	result.z = x * rhs.y - y * rhs.x;
	result.w = 0;

	return result;

}


float Vector4::magnitude()
{
	float result;

	result = sqrtf(x * x + y * y + z * z + w * w);

	return result;

}

float Vector4::normalise()
{
	float magn = magnitude();
	if (magn != 0)
	{
		x = x / magn;
		y = y / magn;
		z = z / magn;
		w = w / magn;

		return magn;
	}


}
Vector4::operator float*()
{
	return &x;
}