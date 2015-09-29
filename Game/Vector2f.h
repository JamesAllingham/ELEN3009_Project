#ifndef VECTOR2F
#define VECTOR2F

class Vector2f
{
public:
	Vector2f () {};
	Vector2f (const float x_in, const float y_in) : x(x_in), y(y_in) {};
	
	Vector2f CrossProduct ( Vector2f lhs, Vector2f rhs) {return Vector2f( lhs.x * rhs.y - lhs.y * rhs.x , lhs.y * rhs.x - lhs.x * rhs.y);};
	
	float x = 0;
	float y = 0; //public due to the original vector2f class having these as public too
	
private:

};

inline bool operator==(Vector2f lhs, Vector2f rhs)
{
	return (lhs.x == rhs.x && lhs.y == rhs.y);
}

// PLUS operators

inline Vector2f& operator+( Vector2f& lhs, Vector2f rhs)
{
	lhs = Vector2f(lhs.x + rhs.x, lhs.y + rhs.y);
	return lhs;
}

inline Vector2f operator+( Vector2f lhs, Vector2f rhs)
{
	return Vector2f(lhs.x + rhs.x, lhs.y + rhs.y);
}

inline Vector2f& operator+( Vector2f& lhs, float scalar)
{
	lhs = Vector2f(lhs.x + scalar, lhs.y + scalar);
	return lhs;
}

inline Vector2f operator+( Vector2f lhs, float scalar)
{
	return Vector2f(lhs.x + scalar, lhs.y + scalar);
}

inline Vector2f& operator+= ( Vector2f& lhs, Vector2f rhs)
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

inline Vector2f& operator-( Vector2f& lhs, Vector2f rhs)
{
	lhs = Vector2f(lhs.x - rhs.x, lhs.y - rhs.y);
	return lhs;
}

inline Vector2f operator-( Vector2f lhs, Vector2f rhs)
{
	return Vector2f(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline Vector2f& operator-( Vector2f& lhs, float scalar)
{
	lhs = Vector2f(lhs.x - scalar, lhs.y - scalar);
	return lhs;
}

inline Vector2f operator-( Vector2f lhs, float scalar)
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

inline Vector2f& operator*( Vector2f& lhs, Vector2f rhs)
{
	lhs = Vector2f(lhs.x * rhs.x, lhs.y * rhs.y);
	return lhs;
}

inline Vector2f operator*( Vector2f lhs, Vector2f rhs)
{
	return Vector2f(lhs.x * rhs.x, lhs.y * rhs.y);
}

inline Vector2f& operator* ( Vector2f& lhs, float scalar)
{
	lhs = Vector2f(lhs.x * scalar , lhs.y * scalar);
	return lhs;
}

inline Vector2f operator* ( Vector2f lhs, float scalar)
{
	return Vector2f(lhs.x * scalar , lhs.y * scalar);
}

inline Vector2f& operator* ( float scalar, Vector2f& lhs)
{
	lhs = Vector2f(lhs.x * scalar , lhs.y * scalar);
	return lhs;
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

// using rvalue division created confusion for some reason
// inline Vector2f& operator/ ( Vector2f& lhs, float scalar)
// {
	// lhs = Vector2f( lhs.x / scalar , lhs.y / scalar);
	// return lhs;
// }

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