#include "Entity.h"

void Entity::setMapLimits(const Vector2f& max_position)
{
	_max_position = max_position;
	
}

void Entity::movePosition(float x, float y)
{
	Vector2f temporary_position_change(x,y);
	movePosition(temporary_position_change);
}

void Entity::movePosition(Vector2f position) // Needs to consider width and height
{
	//Needs to check when in the corner (calling both x and y maxes)
	if (_position.x + position.x > _max_position.x || _position.x + position.x < 0.f || _position.y + position.y > _max_position.y || _position.y + position.y < 0.f) 
	{		
		if (_position.x + position.x > _max_position.x || _position.x + position.x < 0.f)
		{
			_position.y += position.y;
			if (_position.x + position.x >= _max_position.x) 
			{					
				_position.x += _max_position.x - _position.x;
			}
			else 
			{
				_position.x += 0.f - _position.x;
			}
		}
		if (_position.y + position.y > _max_position.y || _position.y + position.y < 0.f)
		{
			_position.x += position.x;
			if (_position.y + position.y >= _max_position.y) 
			{					
				_position.y += _max_position.y - _position.y;
			}
			else 
			{
				_position.y += 0.f - _position.y;
			}
		}		
		
	}
	else _position += position;
}

float Entity::randomPosition (float max_positon) {
	// This function needs to take into account the size of the flyer so that they don't spawn half off of the screen
	// Need to fix this static call to seed the random function
	int rand_num;
	if (!_srand_called) {
		srand(time(0));
		_srand_called = true;
	}
	int tmp = static_cast<int>(max_positon);
	rand_num = rand()%tmp;
	return static_cast<float>(rand_num);
}

Vector2f Entity::_max_position = Vector2f(4800,600);
bool Entity::_srand_called = false;