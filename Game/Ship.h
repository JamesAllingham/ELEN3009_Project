#ifndef SHIP
#define SHIP

#include "Events.h"
#include "Character.h"
#include "Entity.h"

class Ship : public Entity {

public:
	//Set the position and texture of the ship
	// I don't think that the issue is caused by this constructor or the static variables
	Ship();
	void controlMovement(Events event);
	virtual void move(float delta_time);
	
private:	
	bool _moving_up = false;
	bool _moving_down = false;
	bool _moving_left = false;
	bool _moving_right = false;
	
	
};	
#endif