#include "Flyer.h"

Flyer::Flyer()  : _enemy{TextureID::Flyer, 380.f, 280.f} {
	
	float rand_pos = 0;
	srand(time(0));
	
	Character flyer(TextureID::Flyer, rand_x, rand_y);
}

void Flyer::createFlyers() {
	
	while (num_of_flyers < 15) {
		num_of_flyers ++;
	}
}

void Flyer::controlMovement(Events event) {
	
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

void Flyer::move(float delta_time) {
	
	auto distance = delta_time * _pixels_per_second;
	if (_moving_up) _player.y -= distance;
	if (_moving_down) _player.y += distance;
	if (_moving_left) _player.x -= distance;
	if (_moving_right) _player.x += distance;
	
}