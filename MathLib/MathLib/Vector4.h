#pragma once

class Vector4
{
public:

	//function to set the variables
	Vector4();
	//sets base vairables to the new variables of the same name
	Vector4(float x, float y, float z, float w);
	//default destructor
	~Vector4();

	//overloading operator +
	Vector4 operator+(const Vector4& rhs);

	//overloading operator -
	Vector4 operator-(const Vector4& rhs);

	//overloading operator *
	Vector4 operator*(const float rhs);

	//overloading operator /
	Vector4 operator/(const Vector4& rhs);

	//overloading operator -=
	Vector4 operator-();

	//overloading operator +=
	Vector4 operator+=(const Vector4& rhs);

	//crosproduct math for vector
	Vector4 cross(Vector4& rhs);

	//vector dot product math
	float dot(Vector4 rhs);

	//vector magnitude 
	float magnitude();

	//normalization of a vector
	float normalise();
	
	//float variable pointer overloader
	operator float*();

	float x;
	float y;
	float z;
	float w;
};
//overloading operator *
Vector4 operator*(const float lhs, const Vector4& rhs);
//overloading operator /
Vector4 operator/(const float lhs, const Vector4& rhs);