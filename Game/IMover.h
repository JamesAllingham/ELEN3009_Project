#ifndef I_MOVER
#define I_MOVER

class IMover
{
	public:
		virtual void move(float delta_time) = 0;
};

#endif