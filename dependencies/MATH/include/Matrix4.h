#pragma once
#include "Vector4.h"
class Matrix4
{
public:
	union
	{
		float data[16];
		struct
		{
			// Column Major
			float m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33;
		};
	};

	Matrix4();
	Matrix4(float a_m00, float a_m01, float a_m02, float a_m03, float a_m10, float a_m11, float a_m12, float a_m13, float a_m20, float a_m21, float a_m22, float a_m23, float a_m30, float a_m31, float a_m32, float a_m33);
	Matrix4(const Matrix4& a_M4);
	~Matrix4();

	// asgn
	Matrix4& operator=(const Matrix4& a_M4)
	{
		m00 = a_M4.m00;
		m01 = a_M4.m01;
		m02 = a_M4.m02;
		m03 = a_M4.m03;
		m10 = a_M4.m10;
		m11 = a_M4.m11;
		m12 = a_M4.m12;
		m13 = a_M4.m13;
		m20 = a_M4.m20;
		m21 = a_M4.m21;
		m22 = a_M4.m22;
		m23 = a_M4.m23;
		m30 = a_M4.m30;
		m31 = a_M4.m31;
		m32 = a_M4.m32;
		m33 = a_M4.m33;
		return *this;
	}

	// equality
	bool operator==(const Matrix4& a_M4)
	{
		return (
			m00 == a_M4.m00 &&
			m01 == a_M4.m01 &&
			m02 == a_M4.m02 &&
			m03 == a_M4.m03 &&
			m10 == a_M4.m10 &&
			m11 == a_M4.m11 &&
			m12 == a_M4.m12 &&
			m13 == a_M4.m13 &&
			m20 == a_M4.m20 &&
			m21 == a_M4.m21 &&
			m22 == a_M4.m22 &&
			m23 == a_M4.m23 &&
			m30 == a_M4.m30 &&
			m31 == a_M4.m31 &&
			m32 == a_M4.m32 &&
			m33 == a_M4.m33 
			);
	}
	// float*
	explicit operator float*() const
	{
		return (float*)data;
	}
	// Identity
	static Matrix4 Identity();

	// Set RotationZ
	void setRotateZ(float a_zRot);
	void setRotateY(float a_yRot);
	void setRotateX(float a_xRot);

	Vector4 operator*(const Vector4& a_V4) const
	{
		// MATRIX x VECTOR
		// [ m00 , m10 , m20 , m30] * [ x ]   = [ x.m00 + y.m10 + z.m20 + w*m30 ]
		// [ m01 , m11 , m21 , m31]   [ y ]     [ x.m01 + y.m11 + z.m21 + w*m31 ]
		// [ m02 , m12 , m22 , m32]   [ z ]	    [ x.m02 + y.m12 + z.m22 + w*m32 ]
		// [ m03 , m13 , m23 , m33]   [ w ]	    [ x.m03 + y.m13 + z.m23 + w*m33 ]

		return Vector4
			(
				(a_V4.x*m00 + a_V4.y*m10 + a_V4.z*m20 + a_V4.w*m30),
				(a_V4.x*m01 + a_V4.y*m11 + a_V4.z*m21 + a_V4.w*m31),
				(a_V4.x*m02 + a_V4.y*m12 + a_V4.z*m22 + a_V4.w*m32),
				(a_V4.x*m03 + a_V4.y*m13 + a_V4.z*m23 + a_V4.w*m33)
			);
	}

	Matrix4 operator*(const Matrix4& a_M4) const
	{
		// [ m00, m10, m20, m30] * [ n00, n10, n20, n30 ] = [ m00.n00 + m10.n01 + m20.n02  + m30.n03,  m00.n10 + m10.n11 + m20.n12  + m30.n13, m00.n20 + m10.n21 + m20.n22 + m30.n23,  m00.n30 + m10.n31 + m20.n32 + m30.n33,]
		// [ m01, m11, m21, m31]   [ n01, n11, n21, n31 ]   [ m01.n00 + m11.n01 + m21.n02  + m31.n03,  m01.n10 + m11.n11 + m21.n12  + m30.n13, m01.n20 + m11.n21 + m21.n22 + m31.n23,  m01.n30 + m11.n31 + m21.n32 + m31.n33,]
		// [ m02, m12, m22, m32]   [ n02, n12, n22, n32 ]   [ m02.n00 + m12.n01 + m22.n02  + m32.n03,  m02.n10 + m12.n11 + m22.n12  + m30.n13, m02.n20 + m12.n21 + m22.n22 + m32.n23,  m02.n30 + m12.n31 + m22.n32 + m32.n33,]
		// [ m03, m13, m23, m33]   [ n03, n13, n23, n33 ]   [ m03.n00 + m13.n01 + m23.n02  + m33.n03,  m03.n10 + m13.n11 + m23.n12  + m30.n13, m03.n20 + m13.n21 + m23.n22 + m33.n23,  m03.n30 + m13.n31 + m23.n32 + m33.n33,]

		return Matrix4
			(
				m00 * a_M4.m00 + m10 * a_M4.m01 + m20 * a_M4.m02 + m30 * a_M4.m03,
				m01 * a_M4.m00 + m11 * a_M4.m01 + m21 * a_M4.m02 + m31 * a_M4.m03,
				m02 * a_M4.m00 + m12 * a_M4.m01 + m22 * a_M4.m02 + m32 * a_M4.m03,
				m03 * a_M4.m00 + m13 * a_M4.m01 + m23 * a_M4.m02 + m33 * a_M4.m03,
				m00 * a_M4.m10 + m10 * a_M4.m11 + m20 * a_M4.m12 + m30 * a_M4.m13,
				m01 * a_M4.m10 + m11 * a_M4.m11 + m21 * a_M4.m12 + m30 * a_M4.m13,
				m02 * a_M4.m10 + m12 * a_M4.m11 + m22 * a_M4.m12 + m30 * a_M4.m13,
				m03 * a_M4.m10 + m13 * a_M4.m11 + m23 * a_M4.m12 + m30 * a_M4.m13,
				m00 * a_M4.m20 + m10 * a_M4.m21 + m20 * a_M4.m22 + m30 * a_M4.m23,
				m01 * a_M4.m20 + m11 * a_M4.m21 + m21 * a_M4.m22 + m31 * a_M4.m23,
				m02 * a_M4.m20 + m12 * a_M4.m21 + m22 * a_M4.m22 + m32 * a_M4.m23,
				m03 * a_M4.m20 + m13 * a_M4.m21 + m23 * a_M4.m22 + m33 * a_M4.m23,
				m00 * a_M4.m30 + m10 * a_M4.m31 + m20 * a_M4.m32 + m30 * a_M4.m33,
				m01 * a_M4.m30 + m11 * a_M4.m31 + m21 * a_M4.m32 + m31 * a_M4.m33,
				m02 * a_M4.m30 + m12 * a_M4.m31 + m22 * a_M4.m32 + m32 * a_M4.m33,
				m03 * a_M4.m30 + m13 * a_M4.m31 + m23 * a_M4.m32 + m33 * a_M4.m33
			);
	}
};



