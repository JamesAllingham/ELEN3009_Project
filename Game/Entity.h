#ifndef ENTITY
#define ENTITY

#include "Character.h"

#include <SFML/System.hpp> // This is only temporary, using SFMLs Vector2f, but later will write a lightweight vector class to use instead
using sf::Vector2f;

#include <iostream> // For debugging

class Entity {

public:
	//Set the position and texture of the ship
	Entity(TextureID id, Vector2f start_pos, Vector2f velocity);
	Character character() {return _character;};
	virtual void move (float delta_time) = 0;
	//static void setMapLimits (float max_x, float max_y);
	static void setMapLimits (const Vector2f& max_position);
	static Vector2f mapLimits() {return _max_position;};
	Vector2f velocity() {return _velocity;};
	Vector2f position()  {return _character.position;};

protected:
    void moveCharacter(float x, float y);
	void moveCharacter(Vector2f position);	
	
private:
	Character _character;
	
	Vector2f _velocity; 
	static Vector2f _max_position;
};	
#endif