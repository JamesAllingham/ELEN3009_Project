#ifndef SHIP
#define SHIP

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using sf::Keyboard;
using sf::CircleShape;
using sf::Color;
using sf::Vector2f;
using sf::Time;

class Ship {

public:

	Ship ();
	CircleShape get_Character() {return _player;};
	void handle_Ship_Movement (Keyboard::Key, bool);
	void move_The_Ship (Time);
	
private:

	CircleShape _player;
	
	bool _is_moving_up= false; // = false;
	bool _is_moving_down= false;
	bool _is_moving_left= false;
	bool _is_moving_right= false;
	float _pixels_per_second = 30.0f; //ship movement speed
	
};	
#endif