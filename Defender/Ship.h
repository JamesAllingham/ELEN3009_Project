#ifndef SHIP
#define SHIP

#include "Events.h"
#include "Character.h"

class Ship : public Character 
{
public:

	//Set the position and texture of the ship
	Ship () : _player{TextureID::Ship, 380.f, 280.f} {};
	Character getCharacter() {return _player;};
	void controlMovement (Events event);
	void move (float delta_time);
	
private:

	Character _player;
	
	bool _moving_up= false;
	bool _moving_down= false;
	bool _moving_left= false;
	bool _moving_right= false;
	float _pixels_per_second = 150.0f; //ship movement speed
	
};	
#endif