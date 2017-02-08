#pragma once
/*
Vector, in physics, a quantity that has both magnitude and direction.
It is typically represented by an arrow whose direction is the same as that
of the quantity and whose length is proportional to the quantity's magnitude.
  - http://www.britannica.com/topic/vector-physics

Our vector represents this as a pair of x and y coordinates.
It also contains implementation of many of the maths functions
required for vector specific maths.
*/
class Vector2
{
public:
	// The data x, y is stored in a union with a float
	//  array as to enable access in contiguous memory
	//  AND be available as public data members
	union // nameless, shared memory space
	{
		float data[2]; 
		struct // also nameless
		{
			float x;
			float y;
		};
	};

	// Default constructor, sets x and y to zero
	Vector2();
	// Constructor sets x and y as per arguments
	Vector2(float a_X, float a_Y);
	// Copy constructor from passed vector RO3
	Vector2(const Vector2& a_V2);
	// Destructor RO3
	~Vector2();
	// Assignment operator from passed vector RO3
	Vector2& operator=(const Vector2& a_V2)
	{
		x = a_V2.x;
		y = a_V2.y;
		return *this;
	}

	// Memberwise equality check
	bool operator==(const Vector2& a_V2)
	{
		return (this->x == a_V2.x && this->y == a_V2.y);
	}
	// Returns a vector containing memberwise addition
	Vector2 operator+(const Vector2& a_RHS) const
	{
		return Vector2(this->x + a_RHS.x, this->y + a_RHS.y);
	}
	// Returns a vector containing memberwise subtraction
	Vector2 operator-(const Vector2& a_RHS) const
	{
		return Vector2(this->x - a_RHS.x, this->y - a_RHS.y);
	}
	// Returns a vector with the members negated
	Vector2 operator-() const
	{
		return Vector2(-this->x , -this->y);
	}
	// Scalar multiplication of member variables
	Vector2 operator*(const float a_fScale) const
	{
		return Vector2(this->x * a_fScale, this->y * a_fScale);
	}
	// Scalar division of member variables
	Vector2 operator/(const float a_fScale) const
	{
		return Vector2(this->x / a_fScale, this->y / a_fScale);
	}
	// Explicit cast of x and y to a pointer to a float array
	explicit operator float*() const
	{
		return (float*)data;
	}
	// Returns the dot product of the two vectors
	float dot(const Vector2& a_V2) const;
	// Returns the magnitude of the vector
	float magnitude() const;
	// Normalises the member components
	void normalise();
	// Returns a copu of the vector after normalisation
	Vector2 normalised() const;
};

// Returns a new vector scale
static Vector2 operator*(const float a_fScale, const Vector2& a_RHS)
{
	return a_RHS * a_fScale;
}

static Vector2 operator/(const float a_fScale, const Vector2& a_RHS)
{
	return a_RHS / a_fScale;
}

