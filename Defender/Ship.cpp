#include "Ship.h"

Ship::Ship () : _player() {
	
	_player.setRadius(4.f);
	_player.setPosition(100.f, 100.f);
	_player.setFillColor(sf::Color::Cyan);
}