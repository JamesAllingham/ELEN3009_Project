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

/**
* Entity class. 
* This class represents any in game Entity. Anything that can be interacted with in some way for example the PowerUp or Laser classes. 
* Entity objects have a position and id. They can be destroyed and collide with other Entity objects.
*/
class Entity {

public:
	/**
    * Constructor. 
	* @param id is an scoped enumeration containing the type of entity. This required for the mapping of textures to entities when rendering the game. 
    * @param position is a Vector2f of floats containing the initial position of the Entity.
    */
	Entity(EntityID id, Vector2f position): _id(id), _position(position) {};
	/**
    * character() function which returns the character information for rendering an Entity.
    * @return a Character object which contains the EntityID and position. 
    */
	Character character() {return Character(_id, _position);};
	/**
    * setMapLimits() static function which sets the bounds of the map in which the Entity is allowed to spawn or move.
    * @param a Vector2f containing the maximum x and y positions allowed for an entity. 
    */
	static void setMapLimits (const Vector2f& max_position);
	/**
    * mapLimits() static function which returns the current map limits.
    * @return a Vector2f containing the maximum x and y positions allowed for an entity. 
    */
	static Vector2f mapLimits() {return _max_position;};
	Vector2f position() {return _position;};
	EntityID id() {return _id;};
	bool destroyed() {return _destroyed;};
	void destroy() {_destroyed = true;};
	
	/**
    * hitboxPoints() pure virtual function which must be implemented by the derived class.
    * @return a Vector2f list containing the points describing the hit box of the Entity. 
    */
	virtual list<Vector2f> hitboxPoints() = 0;
	/**
    * collide() pure virtual function which must be implemented by the derived class.
	* This will allow role based action to take place for a collision.
    * @param collider a shared pointer to the Entity which has been collided with. 
    */
	virtual void collide(shared_ptr<Entity> collider) = 0;

protected:    	
	void movePosition(float x, float y);
    void movePosition(Vector2f position);
	
private:
	EntityID _id;
	Vector2f _position;
	bool _destroyed = false;
	static Vector2f _max_position;
};	
#endif