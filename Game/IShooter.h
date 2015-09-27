#ifndef I_SHOOTER
#define I_SHOOTER

#include "MovingEntity.h"

class IShooter
{
	public:
		virtual shared_ptr<MovingEntity> shoot(float delta_time) = 0;
};

#endif