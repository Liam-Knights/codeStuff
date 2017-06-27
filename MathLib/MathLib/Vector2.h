#pragma once

class Vector2
{
	public:

		//function to set the variables
	Vector2();
	//sets x and y to x and y
	Vector2(float x, float y);
	//default destructor
	~Vector2();

	//overloading operator +
	Vector2 operator+(const Vector2& rhs);

	//overloading operator -
	Vector2 operator-(const Vector2& rhs);
	
	//overloading operator *
	Vector2 operator*(const float rhs);
	
	//overloading operator /
	Vector2 operator/(const Vector2& rhs);

	//overloading operator -=
	Vector2 operator-();

	//overloading operator +=
	Vector2 operator+=(const Vector2& rhs);

	//vector dot product math
	float dot(Vector2 rhs);
	
	//vector magnitude 
	float magnitude();
	
	//normalization of a vector
	float normalise();

	//float variable pointer overloader
	operator float*();

		float x;
		float y;
};
//overloading operator *
Vector2 operator*(const float lhs, const Vector2& rhs);
//overloading operator /
Vector2 operator/(const float lhs, const Vector2& rhs);