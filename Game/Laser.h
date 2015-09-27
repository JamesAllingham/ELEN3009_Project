#ifndef LASER
#define LASER

#include "MovingEntity.h"
#include "Character.h"
#include "IMover.h"
#include "IShooter.h"

#include <SFML/System.hpp> // This is only temporary, using SFMLs Vector2f, but later will write a lightweight vector class to use instead
using sf::Vector2f;

#include <iostream> // For debugging

#include <memory>
using std::shared_ptr;

/**
* Laser class. 
* This class represents the projectile fired by the player's ship.
*/
class Laser : public MovingEntity
{

public:
	/**
    * Constructor.
    * @param position is a vector of floats containing the initial position of the Laser.
    * @param velocity is a vector of floats containing the velocity of the Laser.
    */
	Laser(const Vector2f& position, const Vector2f& velocity_unit);
	
	/**
    * move() function inherited from MovingEntity.
	* Moves the Laser in a straight line starting at position with direction given by velocity_unit.
    * @param delta_time is a float containing the time since the last move was issued.
    */
	virtual void move(float delta_time) override;
	/**
    * hitboxPoints() function inherited from MovingEntity.
	* The hit box points describe square around the lLaser.
    * @return the list of co-ordinates for the hit box of the Laser.
    */
	virtual list<Vector2f> hitboxPoints() override;
	/**
    * collide() function inherited from MovingEntity.
	* The Laser will be destroyed if it collides with a Missile or Flyer. 
    * @param collider is a pointer to the Entity which the Laser is colliding with.
    */
	virtual void collide(shared_ptr<Entity> collider) override;	
	
private:		
	float _width = 35;
	float _height = 25;	
};	
#endif