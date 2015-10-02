#ifndef SMART_BOMB
#define SAMRT_BOMB

#include "MovingEntity.h"

#include "Vector2f.h"

#include <iostream> // For debugging

#include <memory>
using std::shared_ptr;
/**
* SmartBomb class - represents the projectile fired by the player's ship.
* Inherits from the MovingEntity class.
*/
class SmartBomb : public MovingEntity //Using MovingEntity because the shooting function in Ship returns a moving entity
{

public:
	/**
    * Constructor. Calls the MovingEntity constructor explicitly.
    * @param x_position is a float containing the initial x position of the SmartBomb.
    */
	SmartBomb(float x_position);	
	
	/**
    * Inherited from MovingEntity.
	* The hit box points describe square around the SmartBomb.
    * @return the list of Vector2f co-ordinates for the hit box of the SmartBomb.
    */
	virtual list<Vector2f> hitboxPoints() override;
	/**
    * Inherited from MovingEntity.
	* Moves the SmartBomb in a trajectory starting at position with direction given calculated by taking the difference between the target's position and the SmartBomb's current position
    * @param delta_time is a float containing the time since the last move() was issued.
    */
	virtual void move(float delta_time) override {};
	/**
    * Inherited from MovingEntity.
	* The SmartBomb will be destroyed if it collides with a Flyer. 
    * @param collider is a pointer to the Entity which the SmartBomb is colliding with.
    */
	virtual void collide(shared_ptr<Entity> collider) override;	
	
private:		
	static constexpr const float _SMART_BOMB_WIDTH = 800.f;
	static constexpr const float _SMART_BOMB_HEIGHT = 600.f;	
	static constexpr const float _SMART_BOMB_SPEED = 0.f;
};	
#endif