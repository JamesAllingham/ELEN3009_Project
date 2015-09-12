#ifndef ENTITY
#define ENTITY

#include "Character.h"

class Entity {

public:
	//Set the position and texture of the ship
	Entity(TextureID id, float start_x, float start_y, float velocity, float max_x, float max_y): _character{id, start_x, start_y}, _velocity(velocity), _max_x(max_x), _max_y(max_y) {};
	Character character() {return _character;};
	virtual void move (float delta_time, float max_x, float max_y) = 0;
	
protected:
	Character _character;
	
	float _velocity; //movement speed in pixels per second	//we should probably make this into a vector2f like struct/ object so that we can have x and y velocity which will be useful to make homing missiles later
	float _max_x;
	float _max_y;
};	
#endif