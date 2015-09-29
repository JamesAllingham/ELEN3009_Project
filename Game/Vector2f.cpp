#include "Vector2f.h"

bool Vector2f::operator==(Vector2f lhs, Vector2f rhs)
{
	return (lhs.x == rhs.x && lhs.y == rhs.y);
}

Vector2f Vector2f::operator+( Vector2f lhs, Vector2f rhs)
{
	return Vector2f(lhs.x + rhs.x, lhs.y + rhs.y);
}

Vector2f Vector2f::operator+( Vector2f lhs, float scalar)
{
	return Vector2f(lhs.x + scalar, lhs.y + scalar);
}

Vector2f Vector2f::operator-( Vector2f lhs, Vector2f rhs)
{
	return Vector2f(lhs.x - rhs.x, lhs.y - rhs.y);
}

Vector2f Vector2f::operator*( Vector2f lhs, Vector2f rhs)
{
	return Vector2f(lhs.x * rhs.x, lhs.y * rhs.y);
}

Vector2f Vector2f::operator* ( float scalar, Vector2f vector_in) 
{
	return Vector2f(scalar * vector_in.x, scalar * vector_in.y);
}

Vector2f Vector2f::operator* ( Vector2f vector_in, float scalar)
{
	return Vector2f(vector_in.x * scalar , vector_in.y * scalar);
}

Vector2f Vector2f::operator/ ( Vector2f lhs, float scalar)
{
	return Vector2f( lhs.x / scalar , lhs.y / scalar);
}

Vector2f Vector2f::operator/= ( Vector2f vector, float scalar)
{
	return Vector2f( vector.x/scalar , vector.y/scalar);
}

Vector2f Vector2f::operator*= ( Vector2f lhs, Vector2f rhs)
{
	return Vector2f(lhs.x * rhs.x, lhs.y * rhs.y);
}

Vector2f Vector2f::operator*= ( Vector2f lhs, float scalar)
{
	return Vector2f(lhs.x * scalar, lhs.y * scalar);
}

Vector2f Vector2f::operator+= ( Vector2f lhs, Vector2f rhs)
{
	std:: cout << "lhs.x = " << lhs.x << " rhs.x = " << rhs.x << " X = " <<(lhs.x + rhs.x) << std::endl;
	return Vector2f(lhs.x + rhs.x, lhs.y + rhs.y);
}

Vector2f Vector2f::operator+= ( Vector2f lhs, float scalar)
{
	return Vector2f(lhs.x + scalar, lhs.y + scalar);
}

Vector2f Vector2f::operator-= ( Vector2f lhs, Vector2f rhs)
{
	return Vector2f(lhs.x - rhs.x, lhs.y - rhs.y);
}

Vector2f Vector2f::operator-= ( Vector2f lhs, float scalar)
{
	return Vector2f(lhs.x - scalar, lhs.y - scalar);
}