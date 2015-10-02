#ifndef FLYERS
#define FLYERS

#include <ctime>
#include <cmath>
#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <iostream> // For testing purposes

#include "ShootingMovingEntity.h"
#include "Missile.h"
#include "EntityId.h"
#include "Vector2f.h"

/**
* Flyer class - represents the enemy Flyers.
* Inherits from the ShootingMovingEntity class.
*/
class Flyer : public ShootingMovingEntity
{
public:
	/**
    * Constructor. Calls the ShootingMovingEntity constructor explicitly. Increases the number of Flyer objects.
    */
	Flyer ();
	/**
    * Destructor. Decreases the number of Flyer objects. Increases the number of Flyer objects killed.
    */
	~Flyer();	
	/**
    * Static function. Returns the number of Flyer objects.
    * @return an int containing the number of Flyer objects in the game.  
    */
	static int numberOfFlyers() { return _number_of_flyers;};
	/**
    * Static function. Returns the number of Flyer objects that have been destroyed.
    * @return an int containing the number of Flyer that have been killed.  
    */
	static int numberOfFlyersKilled() { return _number_of_flyers_killed;};
	/**
    * Static function.  Sets the target which all of the Flyer objects will shoot at when in range.
    * @return an int containing the number of Flyer that have been killed.  
    */
	static void setTarget(const shared_ptr<Entity>& target) { _target = target;};
	
	/**
    * Inherited from ShootingMovingEntity.
	* Moves the Flyer in a random direction every second.
    * @param delta_time is a float containing the time since the last move() was issued.
    */
	virtual void move (float delta_time)  override;
	/**
    * Inherited from ShootingMovingEntity.
	* The hit box points describe square around the Flyer.
    * @return the list of Vector2f co-ordinates for the hit box of the Flyer.
    */
	virtual list<Vector2f> hitboxPoints() override;	
	/**
    * Inherited from ShootingMovingEntity.
	* The Flyer shoots a missile at the target if it is in range and enough time has passed since the last shoot() call was issued. 
    * @param delta_time is a float containing the time since the last shoot() was issued.
	* @return a shared pointer to the Missile that has been shot.
    */
	virtual shared_ptr<MovingEntity> shoot(float delta_time) override;
	/**
    * Inherited from ShootingMovingEntity.
	* The Flyer will be destroyed if it collides with a Laser, SmartBomb, HomingMissile or Ship. 
    * @param collider is a pointer to the Entity which the Flyer is colliding with.
    */
	virtual void collide(shared_ptr<Entity> collider) override;	

protected:    
	/**
	* Generates a random float which can be used to create a valid position on the map. Used when spawning the Flyer and when moving it.
    * @param max_position is a float containing the maximum value which can be generated.
	* @return a randomly generated float less than or equal to max_position and greater than or equal to 0.
    */
	float randomPosition (float max_position);

private:

	static int _number_of_flyers;
	static int _number_of_flyers_killed;
	static shared_ptr<Entity> _target;
	
	static constexpr const float _FLYER_WIDTH = 75.f;
	static constexpr const float _FLYER_HEIGHT = 37.f;
	static constexpr const float _FLYER_TARGETING_RANGE = 400.f;
	static constexpr const float _TIME_BETWEEN_SHOTS = 10.f;
	
	float _time_since_last_shot = 9.f;
	float _time_since_last_movement = 1.0f;
	Vector2f _unit_current_velocity;	
	
};	
#endif