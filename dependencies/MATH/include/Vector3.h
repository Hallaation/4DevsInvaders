#pragma once
/*
Vector, in physics, a quantity that has both magnitude and direction.
It is typically represented by an arrow whose direction is the same as that
of the quantity and whose length is proportional to the quantity's magnitude.
- http://www.britannica.com/topic/vector-physics

Our vector represents this as a set of x, y, and z coordinates.
It also contains implementation of many of the maths functions
required for vector specific maths.
*/
class Vector3
{
public:
	// The data x, y, and z is stored in a union with a float
	//  array as to enable access in contiguous memory
	//  AND be available as public data members
	union // nameless, shared memory space
	{
		float data[3];
		struct // also nameless
		{
			float x;
			float y;
			float z;
		};
	};

	// Default constructor, sets x,y and z to zero
	Vector3();
	// Constructor sets x, y, and z as per arguments
	Vector3(float a_X, float a_Y, float a_Z);
	// Copy constructor from passed vector RO3
	Vector3(const Vector3& a_V3);
	// Destructor RO3
	~Vector3();
	// Assignment operator from passed vector RO3
	Vector3& operator=(const Vector3 a_V3)
	{
		x = a_V3.x;
		y = a_V3.y;
		z = a_V3.z;
		return *this;
	}

	// Memberwise equality check
	bool operator==(const Vector3 a_V3)
	{
		return (this->x == a_V3.x && this->y == a_V3.y && this->z == a_V3.z);
	}
	// Returns a vector containing memberwise addition
	Vector3 operator+(const Vector3& a_RHS) const
	{
		return Vector3(this->x + a_RHS.x, this->y + a_RHS.y, this->z + a_RHS.z);
	}
	// Returns a vector containing memberwise subtraction
	Vector3 operator-(const Vector3& a_RHS) const
	{
		return Vector3(this->x - a_RHS.x, this->y - a_RHS.y, this->z - a_RHS.z);
	}
	// Returns a vector with the members negated
	Vector3 operator-() const
	{
		return Vector3(-this->x, -this->y, -this->z);
	}
	// Scalar multiplication of member variables
	Vector3 operator*(const float a_fScale) const
	{
		return Vector3(this->x * a_fScale, this->y * a_fScale, this->z * a_fScale);
	}
	// Scalar division of member variables
	Vector3 operator/(const float a_fScale) const
	{
		return Vector3(this->x / a_fScale, this->y / a_fScale, this->z / a_fScale);
	}
	// Explicit cast of x, y and z union to a pointer to a float array
	explicit operator float*() const
	{
		return (float*)data;
	}
	// Returns the dot product of the two vectors
	float dot(const Vector3& a_V3) const;
	// Returns the magnitude of the vector
	float magnitude() const;
	// Normalises the member components
	void normalise();
	// Returns a copu of the vector after normalisation
	Vector3 normalised() const;
	// Returns a Vector3 which is the cross product of the vectors
	Vector3 cross(const Vector3& a_V3);
};

// Returns a new vector scale
static Vector3 operator*(const float a_fScale, const Vector3& a_RHS)
{
	return a_RHS * a_fScale;
}

static Vector3 operator/(const float a_fScale, const Vector3& a_RHS)
{
	return a_RHS / a_fScale;
}


