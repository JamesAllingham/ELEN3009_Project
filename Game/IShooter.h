#ifndef I_SHOOTER
#define I_SHOOTER

#include "MovingEntity.h"

/**
* IShooter abstract class - pure interface used to create a contract that allows an entity to shoot.
*/
class IShooter
{
public:
	/**
	* shoot() function to be used by all Entities capable of shooting.
	* No implementation, used for role modelling. 
	* Each class which inherits from IShooter will implement this function.
	* @param delta_time is a float containing the time since the last shoot() was issued.
	* @return a shared pointer to the MovingEntity which represents the projectile being shot.
	*/
	virtual shared_ptr<MovingEntity> shoot(float delta_time) = 0;
};

#endif