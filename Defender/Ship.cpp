#include "Ship.h"

Ship::Ship () : _player() {
	
	_player.setRadius(4.f);
	_player.setPosition(320.f, 240.f);
	_player.setFillColor(Color::Cyan);
}

void Ship::handle_Ship_Movement(Keyboard::Key key, bool is_pressed) {
	
	if (key == Keyboard::W) _is_moving_up = is_pressed;
	else if (key == Keyboard::S) _is_moving_down = is_pressed;
	else if (key == Keyboard::A) _is_moving_left = is_pressed;
	else if (key == Keyboard::D) _is_moving_right = is_pressed;
}

void Ship::move_The_Ship () {
	
	Vector2f movement (0.f, 0.f);
	
	if (_is_moving_up) movement.y -= 1.f;
	if (_is_moving_down) movement.y += 1.f;
	if (_is_moving_left) movement.x -= 1.f;
	if (_is_moving_right) movement.x += 1.f;
	
	_player.move(movement);
}