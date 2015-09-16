#include "Entity.h"

void Entity::setMapLimits (float max_x, float max_y)
{
	_max_x = max_x; 
	_max_y = max_y;
}

float Entity::_max_x = 4800;
float Entity::_max_y = 600;