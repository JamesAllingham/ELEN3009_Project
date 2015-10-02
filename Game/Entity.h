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
* Entity class - represents any in game Entity. Anything that can be interacted with in some way for example the PowerUp or Laser classes. 
* Entity objects have a position and id. They can be destroyed and collide with other Entity objects.
*/
class Entity {

public:
	/**
    * Constructor. 
	* @param id is an scoped enumeration containing the type of Entity. This required for the mapping of textures to entities when rendering the game. 
    * @param position is a Vector2f of floats containing the initial position of the Entity.
    */
	Entity(EntityID id, Vector2f position): _id(id), _position(position) {};
	/**
    * Returns the character information for rendering an Entity.
    * @return a Character object which contains the EntityID and position. 
    */
	Character character() {return Character(_id, _position);};
	/**
    * Static function. Sets the bounds of the map in which the Entity is allowed to spawn or move.
    * @param max_position a Vector2f containing the maximum x and y positions allowed for an entity. The x an y positions supplied must be greater than or equal to 0. 
    */
	static void setMapLimits (const Vector2f& max_position);
	/**
    * Static function. Returns the current map limits.
    * @return a Vector2f containing the maximum x and y positions allowed for an entity. The x an y positions supplied must be greater than or equal to 0. 
    */
	static Vector2f mapLimits() {return _max_position;};
	/**
    * Returns the current position.
    * @return a Vector2f containing the current x and y positions for an entity. The x an y positions supplied must be greater than or equal to 0. 
    */
	Vector2f position() {return _position;};
	/**
    * Returns a strongly typed enumeration containing the ID of the entity. 
    * @return the EntityID.
    */
	EntityID id() {return _id;};
	/**
    * Returns the status of an Entity.
    * @return a bool indicating whether or not the Entity has been destroyed and needs to be deleted.
    */
	bool destroyed() {return _destroyed;};
	/**
    * Sets the status of the Entity to destroyed.
    * No arguments or return value.
    */
	void destroy() {_destroyed = true;};
	
	/**
    * Pure virtual function. Must be implemented by the derived class.
    * @return a Vector2f list containing the points describing the hit box of the Entity. 
    */
	virtual list<Vector2f> hitboxPoints() = 0;
	/**
    * Pure virtual function. Must be implemented by the derived class.
	* This will allow role based action to take place for a collision.
    * @param collider a shared pointer to the Entity which has been collided with. 
    */
	virtual void collide(shared_ptr<Entity> collider) = 0;

protected:  	
	/**
    * Moves the entity. 
    * @param delta_position is a Vector2f containing the amount to move in both the x and y directions. Can be positive, negative or 0. 
    */
    void movePosition(Vector2f delta_position);
	/**
    * Moves the entity. Overload of movePosition() allowing individual float values to be used instead of a vector.
    * @param x a float containing the amount the move the entity in the x direction. Can be positive, negative or 0.
	* @param y a float containing the amount the move the entity in the y direction. Can be positive, negative or 0.
    */
	void movePosition(float x, float y);
	
private:
	EntityID _id;
	Vector2f _position;
	bool _destroyed = false;
	static Vector2f _max_position;
};	
#endif