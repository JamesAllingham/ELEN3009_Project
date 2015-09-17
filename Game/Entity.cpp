#include "Entity.h"

Entity::Entity(TextureID id, float start_x, float start_y, float velocity): _character{id, start_x, start_y}, _velocity(velocity) {};

void Entity::setMapLimits (float max_x, float max_y)
{
	_max_x = max_x; 
	_max_y = max_y;
}

void Entity::moveCharacter(float x, float y)
{
	_character.x += x;
	_character.y += y;
}

float Entity::_max_x = 4800;
float Entity::_max_y = 600;