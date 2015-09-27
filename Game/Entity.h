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
	Entity(EntityID id, Vector2f position, Vector2f velocity): _id(id), _position(position), _velocity(velocity) {};
	Character character() {return Character(_id, _position);};
	static void setMapLimits (const Vector2f& max_position);
	static Vector2f mapLimits() {return _max_position;};
	Vector2f velocity() {return _velocity;};
	Vector2f position() {return _position;};
	EntityID id() {return _id;};
	bool destroyed() {return _destroyed;};
	void destroy() {_destroyed = true;};
	
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