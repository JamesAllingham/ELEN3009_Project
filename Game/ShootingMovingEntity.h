#ifndef SHOOTING_MOVING_ENTITY
#define SHOOTING_MOVING_ENTITY

#include "IShooter.h"
#include "MovingEntity.h"
#include "Vector2f.h"
#include "EntityID.h"

#include <list>
using std::list;

/**
* ShootingMovingEntity class. 
* This class is an extension of the MovingEntity class which adds the shoot() function. This facilitates a new role - the shooting, moving entity which has the following functionality: shoot(), move(), hitBoxPoints() and collide().
*/
class ShootingMovingEntity: public MovingEntity, public IShooter
{
	public:
		/**
		* Constructor. Calls the MovingEntity constructor explicitly and the IShooter constructor implicitly. 
		* @param entity_ID is a EntityID containing the type of Entity being created.
		* @param position is a vector of floats containing the initial position of the ShootingMovingEntity.
		* @param velocity is a vector of floats containing the velocity of the ShootingMovingEntity.
		*/
		ShootingMovingEntity(EntityID entity_ID, Vector2f position, Vector2f velocity): MovingEntity{entity_ID, position, velocity} {};
		
		/**
		* shoot() function inherited from IShooter.
		* Shoots a MovingEntity as defined by the derived class.
		* @param delta_time is a float containing the time since the last shoot() was issued.
		* @return a shared pointer to the MovingEntity which represents the projectile being shot.
		*/
		virtual shared_ptr<MovingEntity> shoot(float delta_time) override = 0;
		/**
		* move() function inherited from MovingEntity
		* Moves the ShootingMovingEntity as defined by the derived classes.
		* @param delta_time is a float containing the time since the last move() was issued.
		*/
		virtual void move(float delta_time) override = 0;
		/**
        * hitboxPoints() function inherited from MovingEntity.
		* The hit box points describe hit box of the ShootingMovingEntity.
		* @return the list of co-ordinates for the hit box of the ShootingMovingEntity as described by the derived class.
		*/
		virtual list<Vector2f> hitboxPoints() override  = 0;
		/**
		* collide() function inherited from MovingEntity.
		* The ShootingMovingEntity will be destroyed if it collides with Entities described by the derived class. 
		* @param collider is a pointer to the Entity which the ShootingMovingEntity is colliding with.
		*/
		virtual void collide(shared_ptr<Entity> collider) override = 0;
};

#endif