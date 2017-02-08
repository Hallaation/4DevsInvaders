#pragma once
#include "Vector2.h"
class Matrix2
{
public:
	union
	{
		float data[4];
		struct
		{
			// Column Major
			float m00, m01, m10, m11;
		};
	};

	Matrix2();
	Matrix2(float a_m00, float a_m01, float a_m10, float a_m11);
	Matrix2(const Matrix2& a_M2);
	~Matrix2();
	
	// asgn
	Matrix2& operator=(const Matrix2& a_M2)
	{
		m00 = a_M2.m00;
		m01 = a_M2.m01;
		m10 = a_M2.m10;
		m11 = a_M2.m11;
		return *this;
	}

	// equality
	bool operator==(const Matrix2& a_M2)
	{
		return 
			(m00 == a_M2.m00 &&
			 m01 == a_M2.m01 &&
			 m10 == a_M2.m10 &&
			 m11 == a_M2.m11);
	}
	// float*
	explicit operator float*() const
	{
		return (float*)data;
	}
	// Identity
	static Matrix2 Identity();

	// Set RotationZ
	void setRotateZ(float a_xRot);

	Vector2 operator*(const Vector2& a_V2) const
	{
		// MATRIX x VECTOR
		// [ m00 , m10 ] * [ x ]   = [ x.m00 + y.m10 ]
		// [ m01 , m11 ]   [ y ]     [ x.m01 + y.m11 ]
		return Vector2(a_V2.x*m00 + a_V2.y*m10, a_V2.x*m01 + a_V2.y*m11);
	}

	Matrix2 operator*(const Matrix2& a_M2) const
	{
		// [ m00 , m10 ] * [ n00 , n10 ] = [ m00.n00 + m10.n01 , m00.n10 + m10.n11 ]
		// [ m01 , m11 ]   [ n01 , n11 ]   [ m01.n00 + m11.n01 , m01.n10 + m11.n11 ]
		return Matrix2(m00*a_M2.m00 + m10*a_M2.m01, m01*a_M2.m00 + m11*a_M2.m01,
					   m00*a_M2.m10 + m10*a_M2.m11, m01*a_M2.m10 + m11*a_M2.m11);
	}
};

