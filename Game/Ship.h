#ifndef SHIP
#define SHIP

#include "Events.h"
#include "Character.h"
#include "Entity.h"

class Ship : public Entity {

public:
	//Set the position and texture of the ship
	Ship(TextureID id = TextureID::Ship, float start_x = 380.f, float start_y = 280.f, float velocity = 150.f) : Entity{id, start_x, start_y, velocity} {};
	void controlMovement(Events event);
	virtual void move(float delta_time);
	
private:	
	bool _moving_up = false;
	bool _moving_down = false;
	bool _moving_left = false;
	bool _moving_right = false;
	
};	
#endif