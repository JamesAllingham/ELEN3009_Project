#ifndef ENTITY
#define ENTITY

#include "Character.h"
#include "EntityID.h"
#include <SFML/System.hpp> // This is only temporary, using SFMLs Vector2f, but later will write a lightweight vector class to use instead
using sf::Vector2f;

#include <iostream> // For debugging
#include <list>
using std::list;
#include <memory>
using std::shared_ptr;

class Entity {

public:
	//Set the position and texture of the ship
	Entity(EntityID id, Vector2f position, Vector2f velocity);
	Character character() {return Character(_id, _position);};	
	//static void setMapLimits (float max_x, float max_y);
	static void setMapLimits (const Vector2f& max_position);
	static Vector2f mapLimits() {return _max_position;};
	Vector2f velocity() {return _velocity;};
	Vector2f position() {return _position;};
	EntityID id() {return _id;};
	bool destroyed() {return _destroyed;};
	void destroy() {_destroyed = true;};
	
	//void switchDirection () {_character.facing_right = !_character.facing_right;};
	//bool facingRight () {return _character.facing_right;};
	
	// For now move and shoot are part of entity but in future we should look into having two more derived classes in the hierarchy - ShootingEntity and MovingEntity
	virtual void move(float delta_time) = 0;
	virtual shared_ptr<Entity> shoot(float delta_time) = 0;
	virtual list<Vector2f> hitboxPoints() = 0;
	virtual void collide(shared_ptr<Entity> collider) = 0;

protected:
    void movePosition(float x, float y);
	void movePosition(Vector2f position);	
	float randomPosition (float max_position);
	
private:
	//Character _character;
	EntityID _id;
	Vector2f _position;
	Vector2f _velocity; 
	bool _destroyed = false;
	static bool _srand_called;	
	static Vector2f _max_position;
};	
#endif