#ifndef VECTOR2F
#define VECTOR2F

#include <cmath>

/**
* Vector2f lightweight class - responsible for vector mathematics.
* Operators are overloaded for equality, inequality, scalar and vector addition, scalar and vector subtraction, scalar multiplication, the dot product between two vectors and scalar division.
*/
class Vector2f
{
public:
	Vector2f () {};
	Vector2f (float x_in, float y_in) : x(x_in), y(y_in) {};	
	
	/**
	* Calculates the unit vector of a vector.
	* @return a Vector2f containing the direction of the original vector but with a magnitude of 1.
	*/
	Vector2f unitVector()
	{
		float mag = sqrtf(this->x*this->x + this->y*this->y);
		return Vector2f (this->x / mag , this->y / mag );
	};
	
	float x = 0;
	float y = 0; //public due to the original vector2f class having these as public too
	
private:

};
	
inline bool operator==(const Vector2f& lhs, const Vector2f& rhs)
{
	return (lhs.x == rhs.x && lhs.y == rhs.y);
}

inline bool operator!=(const Vector2f& lhs, const Vector2f& rhs)
{
	return !(lhs==rhs);
}

// PLUS operators

inline Vector2f operator+( const Vector2f& lhs, const Vector2f& rhs)
{
	return Vector2f(lhs.x + rhs.x, lhs.y + rhs.y);
}

inline Vector2f operator+( const Vector2f& lhs, float scalar)
{
	return Vector2f(lhs.x + scalar, lhs.y + scalar);
}

inline Vector2f& operator+= ( Vector2f& lhs, const Vector2f& rhs)
{
	lhs = Vector2f(lhs.x + rhs.x, lhs.y + rhs.y);
	return lhs;
}

inline Vector2f& operator+= ( Vector2f& lhs, float scalar)
{
	lhs = Vector2f(lhs.x + scalar, lhs.y + scalar);
	return lhs;
}

// MINUS operators

inline Vector2f operator-( const Vector2f& lhs, const Vector2f& rhs)
{
	return Vector2f(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline Vector2f operator-( const Vector2f& lhs, float scalar)
{
	return Vector2f(lhs.x - scalar, lhs.y - scalar);
}

inline Vector2f& operator-= ( Vector2f& lhs, Vector2f rhs)
{
	lhs = Vector2f(lhs.x - rhs.x, lhs.y - rhs.y);
	return lhs;
}

inline Vector2f& operator-= ( Vector2f& lhs, float scalar)
{
	lhs = Vector2f(lhs.x - scalar, lhs.y - scalar);
	return lhs;
}

// MULTIPLY operators (dot product)

inline float operator*( Vector2f lhs, Vector2f rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

inline Vector2f operator* ( Vector2f lhs, float scalar)
{
	return Vector2f(lhs.x * scalar , lhs.y * scalar);
}

inline Vector2f operator* ( float scalar, Vector2f lhs)
{
	return Vector2f(lhs.x * scalar , lhs.y * scalar);
}

inline Vector2f& operator*= ( Vector2f& lhs, Vector2f rhs)
{
	lhs = Vector2f(lhs.x * rhs.x, lhs.y * rhs.y);
	return lhs;
}

inline Vector2f& operator*= ( Vector2f& lhs, float scalar)
{
	lhs = Vector2f(lhs.x * scalar, lhs.y * scalar);
	return lhs;
}

// DIVISION operators

inline Vector2f operator/ ( Vector2f lhs, float scalar)
{
	return Vector2f( lhs.x / scalar , lhs.y / scalar);
}

inline Vector2f& operator/= ( Vector2f& lhs, float scalar)
{
	lhs = Vector2f( lhs.x / scalar , lhs.y / scalar);
	return lhs;
}
#endif