#include "Ship.h"

Ship::Ship () : _Player() {
	
	_Player.setRadius(40.f);
	_Player.setPosition(100.f, 100.f);
	_Player.setFillColor(sf::Color::Cyan);
}