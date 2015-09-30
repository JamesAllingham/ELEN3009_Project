#ifndef MOVING_ENTITY
#define MOVING_ENTITY

#include "IMover.h"
#include "Entity.h"
#include "Vector2f.h"
#include "EntityID.h"

#include <list>
using std::list;

/**
* MovingEntity class. 
* This class is an extension of the Entity class which adds the move() function. This facilitates a new role - the moving entity which has the following functionality: move(), hitBoxPoints() and collide().
*/
class MovingEntity: public Entity, public IMover
{
	public:
		/**
		* Constructor. Calls the Entity constructor explicitly and the IMover constructor implicitly. 
		* @param entity_ID is a EntityID containing the type of Entity being created.
		* @param position is a Vector2f containing the initial position of the MovingEntity.
		* @param velocity is a Vector2f containing the velocity of the MovingEntity.
		*/
		MovingEntity(EntityID entity_ID, Vector2f position, Vector2f velocity): Entity{entity_ID, position}, _velocity(velocity) {};
		
		/**
		* move() function inherited from IMover.
		* Moves the MovingEntity as defined by the derived classes.
		* @param delta_time is a float containing the time since the last move() was issued.
		*/
		virtual void move(float delta_time) override = 0;
		/**
        * hitboxPoints() function inherited from Entity.
		* The hit box points describe hit box of the MovingEntity.
		* @return the list of Vector2f co-ordinates for the hit box of the MovingEntity as described by the derived class.
		*/
		virtual list<Vector2f> hitboxPoints() override = 0;
		/**
		* collide() function inherited from Entity.
		* The MovingEntity will be destroyed if it collides with Entities described by the derived class. 
		* @param collider is a pointer to the Entity which the MovingEntity is colliding with.
		*/
		virtual void collide(shared_ptr<Entity> collider) override = 0;			
		
		Vector2f velocity() {return _velocity;};
		
	private:
		
		Vector2f _velocity; 
};

#endif