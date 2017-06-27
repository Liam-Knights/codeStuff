#pragma once

class Vector3
{
public:

	//function to set the variables
	Vector3();
	//sets base vairables to the new variables of the same name
	Vector3(float x, float y, float z);
	//default destructor
	~Vector3();

	//overloading operator +
	Vector3 operator+(const Vector3& rhs);

	//overloading operator -
	Vector3 operator-(const Vector3& rhs);

	//overloading operator *
	Vector3 operator*(const float rhs);

	//overloading operator /
	Vector3 operator/(const Vector3& rhs);

	//overloading operator -=
	Vector3 operator-();

	//overloading operator +=
	Vector3 operator+=(const Vector3& rhs);
	
	//crosproduct math for vector
	Vector3 cross(Vector3& rhs);

	//vector dot product math
	float dot(Vector3 rhs);

	//vector magnitude 
	float magnitude();

	//normalization of a vector
	float normalise();

	//float variable pointer overloader
	operator float*();

	float x;
	float y;
	float z;
};
//overloading operator *
Vector3 operator*(const float lhs, const Vector3& rhs);
//overloading operator /
Vector3 operator/(const float lhs, const Vector3& rhs);