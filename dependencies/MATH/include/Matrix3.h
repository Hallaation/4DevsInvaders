#pragma once
#include "Vector3.h"
#include "Vector2.h"
class Matrix3
{
public:
	union
	{
		float data[9];
		struct
		{
			// Column Major
			float m00, m01, m02, m10, m11, m12, m20, m21, m22;
		};
	};

	void SetTranslation(float a_x, float a_y)
	{
		m20 = a_x;
		m21 = a_y;
	}

	Vector2 Position()
	{
		return Vector2(m20, m21);
	}

	Vector2 Forward()
	{
		return Vector2(m10, m11);
	}
	
	Vector2 Right()
	{
		return Vector2(m00, m01);
	}

	Matrix3();
	Matrix3(float a_m00, float a_m01, float a_m02, float a_m10, float a_m11, float a_m12, float a_m20, float a_m21, float a_m22 );
	Matrix3(const Matrix3& a_M3);
	~Matrix3();

	// asgn
	Matrix3& operator=(const Matrix3& a_M3)
	{
		m00 = a_M3.m00;
		m01 = a_M3.m01;
		m02 = a_M3.m02;
		m10 = a_M3.m10;
		m11 = a_M3.m11;
		m12 = a_M3.m12;
		m20 = a_M3.m20;
		m21 = a_M3.m21;
		m22 = a_M3.m22;
		return *this;
	}

	// equality
	bool operator==(const Matrix3& a_M3)
	{
		return (m00 == a_M3.m00 &&
				m01 == a_M3.m01 &&
				m02 == a_M3.m02 &&
				m10 == a_M3.m10 &&
				m11 == a_M3.m11 &&
				m12 == a_M3.m12 &&
				m20 == a_M3.m20 &&
				m21 == a_M3.m21 &&
				m22 == a_M3.m22);
	}
	// float*
	explicit operator float*() const
	{
		return (float*)data;
	}
	// Identity
	static Matrix3 Identity();

	// Set RotationZ
	void setRotateZ(float a_zRot);
	void setRotateY(float a_yRot);
	void setRotateX(float a_xRot);

	Vector3 operator*(const Vector3& a_V3) const
	{
		// MATRIX x VECTOR
		// [ m00 , m10 , m20 ] * [ x ]   = [ x.m00 + y.m10 + z.m20]
		// [ m01 , m11 , m21 ]   [ y ]     [ x.m01 + y.m11 + z.m21]
		// [ m02 , m12 , m22 ]   [ z ]	   [ x.m02 + y.m12 + z.m22]
		return Vector3(a_V3.x*m00 + a_V3.y*m10 + a_V3.z*m20,
					   a_V3.x*m01 + a_V3.y*m11 + a_V3.z*m21, 
					   a_V3.x*m02 + a_V3.y*m12 + a_V3.z*m22);
	}

	Matrix3 operator*(const Matrix3& a_M3) const
	{
		// [ m00, m10, m20 ] * [ n00, n10, n20  ] = [ m00.n00 + m10.n01 + m20.n02 ,  m00.n10 + m10.n11 + m20.n12 , m00.n20 + m10.n21 + m20.n22 ]
		// [ m01, m11, m21 ]   [ n01, n11, n21  ]   [ m01.n00 + m11.n01 + m21.n02 ,  m01.n10 + m11.n11 + m21.n12 , m01.n20 + m11.n21 + m21.n22 ]
		// [ m02, m12, m22 ]   [ n02, n12, n22  ]   [ m02.n00 + m12.n01 + m22.n02 ,  m02.n10 + m12.n11 + m22.n12 , m02.n20 + m12.n21 + m22.n22 ]

		return Matrix3(m00 * a_M3.m00 + m10 * a_M3.m01 + m20 * a_M3.m02, // Col. 1
					   m01 * a_M3.m00 + m11 * a_M3.m01 + m21 * a_M3.m02,
					   m02 * a_M3.m00 + m12 * a_M3.m01 + m22 * a_M3.m02,
					   m00 * a_M3.m10 + m10 * a_M3.m11 + m20 * a_M3.m12, // Col. 2
					   m01 * a_M3.m10 + m11 * a_M3.m11 + m21 * a_M3.m12,
					   m02 * a_M3.m10 + m12 * a_M3.m11 + m22 * a_M3.m12,
					   m00 * a_M3.m20 + m10 * a_M3.m21 + m20 * a_M3.m22, // Col. 3
					   m01 * a_M3.m20 + m11 * a_M3.m21 + m21 * a_M3.m22,
					   m02 * a_M3.m20 + m12 * a_M3.m21 + m22 * a_M3.m22);
	}
};



