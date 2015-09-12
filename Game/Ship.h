#ifndef SHIP
#define SHIP

#include "Events.h"
#include "Character.h"
#include "Entity.h"

class Ship : public Entity {

public:
	//Set the position and texture of the ship
	Ship() : Entity{TextureID::Ship, _max_x/2, _max_y/2, 150.f} {};
	void controlMovement(Events event);
	virtual void move(float delta_time);
	
private:	
	bool _moving_up = false;
	bool _moving_down = false;
	bool _moving_left = false;
	bool _moving_right = false;
	
	
};	
#endif