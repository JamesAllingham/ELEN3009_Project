#ifndef POWERUP
#define POWERUP

#include "Character.h"
#include "Entity.h"
#include "Vector2f.h"

#include <memory>
using std::shared_ptr;
#include <ctime>

#include <iostream> // For debugging
/**
* Powerup class - represents the powerups that the player can pick up to get HomingMissile shots.
* Inherits from the Entity class.
*/
class Powerup : public Entity
{

public:
	/**
    * Constructor. Calls the Entity constructor explicitly.
	* Prevents more Powerup objects from spawning.
    */
	Powerup();
	/**
    * Destructor. Allows a Powerup object to spawn again.
    */
	~Powerup();	
	/**
    * Inherited from Entity.
	* The hit box points describe square around the Powerup.
    * @return the list of Vector2f co-ordinates for the hit box of the Powerup.
    */
	virtual list<Vector2f> hitboxPoints() override;
	/**
    * Inherited from Entity.
	* The Powerup will be destroyed if it collides with a Ship. 
    * @param collider is a pointer to the Entity which the Powerup is colliding with.
    */
	virtual void collide(shared_ptr<Entity> collider) override;	
	/**
    * Static function.
    * @return a bool containing the current state of a Powerup being on the map.
    */
	static bool PowerupOnTheMap ();
	
protected:   
	/**
	* Generates a random float which can be used to create a valid position on the map. Used when spawning the Powerup.
    * @param max_position is a float containing the maximum value which can be generated.
	* @return a randomly generated float less than or equal to max_position and greater than or equal to 0.
    */
	float randomPosition (float max_position);
	
private:		
	static const constexpr float _POWER_UP_WIDTH = 26;
	static const constexpr float _POWER_UP_HEIGHT = 30;
	static bool _powerup_on_the_map;
};	
#endif