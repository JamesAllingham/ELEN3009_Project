#ifndef ENTITY
#define ENTITY

#include "Character.h"
#include "EntityID.h"
#include "Vector2f.h"

#include <iostream> // For debugging
#include <list>
using std::list;
#include <memory>
using std::shared_ptr;
#include <ctime>

/**
* Entity class. 
* This class represents any in game Entity. Anything that can be interacted with in some way for example the PowerUp or Laser classes. 
* Entity objects have a position and id. They can be destroyed and collide with other Entity objects.
*/
class Entity {

public:
	//Set the position and texture of the ship
	Entity(EntityID id, Vector2f position): _id(id), _position(position) {};
	Character character() {return Character(_id, _position);};
	static void setMapLimits (const Vector2f& max_position);
	static Vector2f mapLimits() {return _max_position;};
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
	EntityID _id;
	Vector2f _position;
	bool _destroyed = false;
	static bool _srand_called;	
	static Vector2f _max_position;
};	
#endif