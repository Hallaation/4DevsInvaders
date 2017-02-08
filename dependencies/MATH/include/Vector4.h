#pragma once
/*
Vector, in physics, a quantity that has both magnitude and direction.
It is typically represented by an arrow whose direction is the same as that
of the quantity and whose length is proportional to the quantity's magnitude.
- http://www.britannica.com/topic/vector-physics

Our vector represents this as a set of x, y,z and w coordinates.
It also contains implementation of many of the maths functions
required for vector specific maths.
*/
class Vector4
{
public:
	// The data x, y,z and w is stored in a union with a float
	//  array as to enable access in contiguous memory
	//  AND be available as public data members
	union // nameless, shared memory space
	{
		float data[4];
		struct // also nameless
		{
			float x;
			float y;
			float z;
			float w;
		};
	};

	// Default constructor, sets x,y and z to zero
	Vector4();
	// Constructor sets x, y, and z as per arguments
	Vector4(float a_X, float a_Y, float a_Z, float a_W);
	// Copy constructor from passed vector RO3
	Vector4(const Vector4& a_V4);
	// Destructor RO3
	~Vector4();
	// Assignment operator from passed vector RO3
	Vector4& operator=(const Vector4 a_V4)
	{
		x = a_V4.x;
		y = a_V4.y;
		z = a_V4.z;
		w = a_V4.w;
		return *this;
	}

	// Memberwise equality check
	bool operator==(const Vector4 a_V4)
	{
		return (this->x == a_V4.x && this->y == a_V4.y && this->z == a_V4.z && this->w == a_V4.w);
	}
	// Returns a vector containing memberwise addition
	Vector4 operator+(const Vector4& a_RHS) const
	{
		return Vector4(this->x + a_RHS.x, this->y + a_RHS.y, this->z + a_RHS.z, this->w);
	}
	// Returns a vector containing memberwise subtraction
	Vector4 operator-(const Vector4& a_RHS) const
	{
		return Vector4(this->x - a_RHS.x, this->y - a_RHS.y, this->z - a_RHS.z, this->w);
	}
	// Returns a vector with the members negated EXCEPT W
	Vector4 operator-() const
	{
		return Vector4(-this->x, -this->y, -this->z, this->w);
	}
	// Scalar multiplication of member variables EXCEPT W
	Vector4 operator*(const float a_fScale) const
	{
		return Vector4(this->x * a_fScale, this->y * a_fScale, this->z * a_fScale, this->w);
	}
	// Scalar division of member variables EXCEPT W
	Vector4 operator/(const float a_fScale) const
	{
		return Vector4(this->x / a_fScale, this->y / a_fScale, this->z / a_fScale, this->w);
	}
	// Explicit cast of x, y, z, and w union to a pointer to a float array
	explicit operator float*() const
	{
		return (float*)data;
	}
	// Returns the dot product of the two vectors, EXCEPT W
	float dot(const Vector4& a_V4) const;
	// Returns the magnitude of the vector, EXCEPT W
	float magnitude() const;
	// Normalises the member components, EXCEPT W
	void normalise();
	// Returns a copy of the vector after normalisation, Ignoring W
	Vector4 normalised() const;
	// Vector cross, EXCEPT W
	Vector4 cross(const Vector4& a_V4);
};

// Returns a new vector scale
static Vector4 operator*(const float a_fScale, const Vector4& a_RHS)
{
	return a_RHS * a_fScale;
}

static Vector4 operator/(const float a_fScale, const Vector4& a_RHS)
{
	return a_RHS / a_fScale;
}


