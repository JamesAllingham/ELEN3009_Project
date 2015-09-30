#ifndef HOMING_MISSILE
#define HOMING_MISSILE

#include "MovingEntity.h"
#include "Flyer.h"

#include "Vector2f.h"

#include <iostream> // For debugging

#include <memory>
using std::shared_ptr;

/**
* HomingMissile class - represents the homing projectile fired by the player's Ship when a Powerup is active.
* Inherits from the MovingEntity class.
*/
class HomingMissile : public MovingEntity
{

public:
	/**
    * Constructor.
    * @param position is a vector of floats containing the initial position of the HomingMissile.
    * @param nearest_target is a shared pointer which is the nearest enemy to the HomingMissile, which the HomingMissile will lock onto.
    */
	HomingMissile(const Vector2f& position, const shared_ptr<Entity>& nearest_target);	
	
	/**
    * move() function inherited from MovingEntity.
	* Moves the HomingMissile in a trajectory starting at position with direction given calculated by taking the difference between the target's position and the HomingMissile's current position
    * @param delta_time is a float containing the time since the last move() was issued.
    */
	virtual void move(float delta_time) override;
	/**
    * hitboxPoints() function inherited from MovingEntity.
	* The hit box points describe square around the HomingMissile.
    * @return the list of co-ordinates for the hit box of the HomingMissile.
    */
	virtual list<Vector2f> hitboxPoints() override;
	/**
    * collide() function inherited from MovingEntity.
	* The HomingMissile will be destroyed if it collides with a Flyer. 
    * @param collider is a pointer to the Entity which the HomingMissile is colliding with.
    */
	virtual void collide(shared_ptr<Entity> collider) override;	
	
private:		
	static constexpr const float _MISSILE_WIDTH = 25.f;
	static constexpr const float _MISSILE_HEIGHT = 25.f;	
	static constexpr const float _MISSILE_SPEED = 200.f;
	shared_ptr<Entity> _nearest_target;
};	
#endif