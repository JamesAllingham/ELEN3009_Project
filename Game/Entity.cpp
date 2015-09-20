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
	moveCharacter(temporary_position_change);
	//_character.position += temporary_position_change;
}

void Entity::moveCharacter(Vector2f position)
{
	//Needs to check when in the corner (calling both x and y maxes)
	if (_character.position.x + position.x > _max_position.x || _character.position.x + position.x < 0.f || _character.position.y + position.y > _max_position.y || _character.position.y + position.y < 0.f) 
	{
		//std::cout << "end of range" << std::endl;
		if (_character.position.x + position.x > _max_position.x || _character.position.x + position.x < 0.f) _character.position.y += position.y;
		if (_character.position.y + position.y > _max_position.y || _character.position.y + position.y < 0.f) _character.position.x += position.x;
	}
	else _character.position += position;
}

float Entity::randomPosition (float max_positon) {
	// This function needs to take into account the size of the flyer so that they dont spawn half off of the screen
	// Need to fix this static call to seed the rnadom function
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