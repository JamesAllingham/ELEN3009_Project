#ifndef ENTITY
#define ENTITY

#include "Character.h"

#include <SFML/System.hpp> // This is only temporary, using SFMLs Vector2f, but later will write a lightweight vector class to use instead
using sf::Vector2f;

#include <iostream> // For debugging
#include <list>
using std::list;

class Entity {

public:
	//Set the position and texture of the ship
	Entity(TextureID id, Vector2f start_pos, Vector2f velocity);
	Character character() {return _character;};	
	//static void setMapLimits (float max_x, float max_y);
	static void setMapLimits (const Vector2f& max_position);
	static Vector2f mapLimits() {return _max_position;};
	Vector2f velocity() {return _velocity;};
	Vector2f position()  {return _character.position;};
	
	// For now move and shoot are part of entity but in future we should look into having two more derived classes in the heirarchy - ShootingEntity and MovingEntity
	virtual void move(float delta_time) = 0;
	//virtual void shoot() = 0;
	virtual list<Vector2f> hitboxPoints() = 0;

protected:
    void moveCharacter(float x, float y);
	void moveCharacter(Vector2f position);	
	
private:
	Character _character;
	
	Vector2f _velocity; 
	static Vector2f _max_position;
};	
#endif