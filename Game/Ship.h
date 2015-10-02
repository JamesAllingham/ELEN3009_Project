#ifndef SHIP
#define SHIP

#include "ShootingMovingEntity.h"
#include "Events.h"
#include "Laser.h"
#include "HomingMissile.h"
#include "EntityHolder.h"
#include "SmartBomb.h"
#include "EntityID.h"
#include "Vector2f.h"

#include <iostream> // For debugging
#include <list>
using std::list;
#include <memory>
using std::shared_ptr;
#include <limits>
using std::numeric_limits;
/**
* Ship class - represents the user controlled player object.
* Inherits from the ShootingMovingEntity class.
*/
class Ship : public ShootingMovingEntity
{
public:
	/**
    * Constructor. Creates the ship at the centre of the map.
    */
	Ship();
	/**
    * Changes the state of the Ship so that when the move() function is called a specific action will take place based on the user's input in the form of an event.
    * @param event is an Events object which represents a command given by the user and relayed via the UserInterface object.
    */
	void controlMovement(Events event);
	/**
    * Changes the state of the Ship so that when the shoot() function is called a specific action will take place based on the user's input in the form of an event.
    * @param event is an Events object which represents a command given by the user and relayed via the UserInterface object.
    */
	void controlShooting(Events event);
	/**
    * Allows the movement of the Ship to be tracked in turn allowing for the camera to be centred around the player.
    * @return a Vector2f containing the change in position of the Ship since the last call of changeInPosition().
    */
	Vector2f changeInPosition();
	/**
    * Returns the number of missiles available to the player.
    * @return an int containing the number of homing missiles the Ship has remaining.
    */	
	int numberOfHomingMissiles() { return _number_of_homing_missiles;};	
	/**
    * Adds homing missiles to the Ship when a Powerup is picked up.
    * No parameters or return value.
    */	
	void addHomingMissiles() {_number_of_homing_missiles+=3;};
	/**
    * Change the direction which the Ship is facing.
    * No parameters or return value.
    */	
	void switchDirection () {_facing_right = !_facing_right;};
	/**
    * Returns the direction of the Ship.
    * @return an bool containing whether or not the Ship is facing right.
    */
	bool facingRight () {return _facing_right;};
	/**
    * Find the closest target to the Ship for firing a HomingMissile.
    * @param targets a list of possible targets for the Ship.
    */
	void setNearestTarget(EntityHolder& targets);
	/**
    * Returns the current nearest target of the ship.
    * @return a shared pointer to the Flyer which is nearest to the Ship.
    */
	shared_ptr<Entity> nearestTarget() { return _nearest_target;};
	/**
    * Returns the number of lives remaining for the player.
    * @return an int contining the number of lives left.
    */
	int numberOfLivesRemaining () {return _number_of_lives;};
	/**
    * Inherited from ShootingMovingEntity.
	* Moves the Ship in the direction set by the controlMovement() function.
    * @param delta_time is a float containing the time since the last move() was issued.
    */
	virtual void move(float delta_time) override;
	/**
    * Inherited from ShootingMovingEntity.
	* The hit box points describe square around the Ship.
    * @return the list of Vector2f co-ordinates for the hit box of the Ship.
    */
	virtual list<Vector2f> hitboxPoints() override;
	/**
    * Inherited from ShootingMovingEntity.
	* The Ship shoots a Laser, HomingMissile or SmartBomb depending on the state set by the controlShooting() function.
    * @param delta_time is a float containing the time since the last shoot() was issued.
	* @return a shared pointer to the Laser, HomingMissile or SmartBomb that has been shot.
    */
	virtual shared_ptr<MovingEntity> shoot(float delta_time) override;	
	/**
    * Inherited from ShootingMovingEntity.
	* The Ship will loose a life if it collides with a Missile or Flyer.
	* The Ship will gain 3x HomingMsile if it collides with a Powerup.	
    * @param collider is a pointer to the Entity which the Ship is colliding with.
    */
	virtual void collide(shared_ptr<Entity> collider) override;
	
	
private:		
	bool _moving_up = false;
	bool _moving_down = false;
	bool _moving_left = false;
	bool _moving_right = false;
	bool _facing_right = true;
	
	bool _shoot_laser = false;
	bool _shoot_homing_missile = false;
	bool _shoot_smart_bomb = false;
	
	static constexpr const float _SHIP_WIDTH = 75;
	static constexpr const float _SHIP_HEIGHT = 30;
	static constexpr const float _SHIP_SPEED = 250.f;
	static constexpr const float _SMART_BOMB_X_OFFSET = -400.f;
	static constexpr const float _LASER_X_OFFSET = 25.f;
	static constexpr const float _LASER_Y_OFFSET = 10.f;
	static constexpr const float _HOMING_MISSILE_X_OFFSET = 35.f;
	static constexpr const float _HOMING_MISSILE_Y_OFFSET = 10.f;
	
	shared_ptr<Entity> _nearest_target;
	int _number_of_homing_missiles = 0;
	int _number_of_lives = 3;
	int _number_of_smart_bombs = 2;	
	Vector2f _delta_position;	
};	
#endif