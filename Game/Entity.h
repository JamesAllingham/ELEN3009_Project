#ifndef ENTITY
#define ENTITY

#include "Character.h"

class Entity {

public:
	//Set the position and texture of the ship
	Entity(TextureID id, float start_x, float start_y, float velocity);
	Character character() {return _character;};
	virtual void move (float delta_time) = 0;
	static void setMapLimits (float max_x, float max_y);
	static float maximumX() {return _max_x;};
	static float maximumY()  {return _max_y;};
	float velocity() {return _velocity;};
	float xPosition()  {return _character.x;};
	float yPosition() {return _character.y;};

protected:
    void moveCharacter(float x, float y);	
	
private:
	Character _character;
	
	float _velocity; //movement speed in pixels per second	//we should probably make this into a vector2f like struct/ object so that we can have x and y velocity which will be useful to make homing missiles later
	static float _max_x;
	static float _max_y;
};	
#endif