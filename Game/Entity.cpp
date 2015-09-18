#include "Entity.h"

Entity::Entity(TextureID id, Vector2f start_position, Vector2f velocity): _character{id, start_position}, _velocity(velocity) {};

// void Entity::setMapLimits(float max_x, float max_y)
// {
	// _max_position.x = max_x; 
	// _max_position.y = max_y;
// }

void Entity::setMapLimits(const Vector2f& max_position)
{
	_max_position = max_position;
	
}

void Entity::moveCharacter(float x, float y)
{
	Vector2f temporary_position_change(x,y);
	_character.position += temporary_position_change;
}

void Entity::moveCharacter(Vector2f position)
{
	_character.position += position;
}	

Vector2f Entity::_max_position = Vector2f(4800,600);