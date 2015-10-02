#ifndef I_MOVER
#define I_MOVER

/**
* IMover abstract class - pure interface used to create a contract that allows an entity to move.
*/
class IMover
{
public:
	/**
	* To be used by all Entities capable of movement.
	* No implementation, used for role modelling. 
	* Each class which inherits from IMover will implement this function.
	* @param delta_time is a float containing the time since the last move() was issued.
	*/
	virtual void move(float delta_time) = 0;
};

#endif