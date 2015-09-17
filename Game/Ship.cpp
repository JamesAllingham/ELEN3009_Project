#include "Ship.h"

Ship::Ship() : Entity{TextureID::Ship, maximumX()/2, maximumY()/2, 150.f} {};

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

void Ship::move(float delta_time) {
	
	auto distance = delta_time * velocity();
	if (_moving_up) moveCharacter(0, - distance);
	if (_moving_down) moveCharacter(0,  + distance);
	if (_moving_left) moveCharacter(- distance,0);
	if (_moving_right) moveCharacter(+ distance,0);
	
}