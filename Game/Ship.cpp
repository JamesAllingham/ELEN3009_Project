#include "Ship.h"

Ship::Ship() : Entity{TextureID::Ship, Vector2f(mapLimits().x/2, mapLimits().y/2), Vector2f(150.f,150.f)}, _delta_position(0,0) 
{
	
};

void Ship::controlMovement(Events event) {
	
	switch (event){
		case Events::W_Pressed:
			_moving_up = true;
			break;
		case Events::W_Released:
			_moving_up = false;
			break;
		case Events::S_Pressed:
			_moving_down = true;
			break;
		case Events::S_Released:
			_moving_down = false;
			break;
		case Events::A_Pressed:
			_moving_left = true;
			break;
		case Events::A_Released:
			_moving_left = false;
			break;
		case Events::D_Pressed:
			_moving_right = true;
			break;
		case Events::D_Released:
			_moving_right = false;
			break;
		default:
			break;
	}
}

void Ship::move(float delta_time) 
{
	Vector2f old_position = position();
	auto distance = delta_time * velocity();
	if (_moving_up) moveCharacter(0, -distance.y);
	if (_moving_down) moveCharacter(0, distance.y);
	if (_moving_left) moveCharacter(-distance.x,0);
	if (_moving_right) moveCharacter(distance.x,0);
	_delta_position =  position() - old_position;
}

Vector2f Ship::changeInPosition() 
{
	Vector2f delta_position = _delta_position;
	_delta_position = Vector2f(0,0);
	
	return delta_position;	
}