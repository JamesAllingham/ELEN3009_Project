#ifndef MISSILE
#define MISSILE

#include "MovingEntity.h"

#include "Vector2f.h"

#include <memory>
using std::shared_ptr;

/**
* Missile class - represents the projectile fired by an enemy Flyer.
* Inherits from the MovingEntity class.
*/
class Missile : public MovingEntity
{

public:
	/**
    * Constructor. Calls the MovingEntity constructor explicitly.
    * @param position is a Vector2f containing the initial position of the Missile.
    * @param velocity_unit is a Vector2f containing the velocity unit direction of the Missile.
    */
	Missile(const Vector2f& position, const Vector2f& velocity_unit);
	/**
    * Inherited from MovingEntity.
	* Moves the Missile in a straight line starting at position with direction given by velocity_unit.
    * @param delta_time is a float containing the time since the last move() was issued.
    */
	virtual void move(float delta_time) override;
	/**
    * Inherited from MovingEntity.
	* The hit box points describe square around the Missile.
    * @return the list of Vector2f co-ordinates for the hit box of the Missile.
    */
	virtual list<Vector2f> hitboxPoints() override;
	/**
    * Inherited from MovingEntity.
	* The Missile will be destroyed if it collides with a Laser or Ship. 
    * @param collider is a pointer to the Entity which the Missile is colliding with.
    */
	virtual void collide(const shared_ptr<Entity>& collider) override;	
	
private:		
	static constexpr const auto _MISSILE_WIDTH = 25.f;
	static constexpr const auto _MISSILE_HEIGHT = 25.f;	
	static constexpr const auto _MISSILE_SPEED = 90.f;
};	
#endif