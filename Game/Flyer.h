#ifndef FLYERS
#define FLYERS

#include <ctime>

#include "Events.h"
#include "Character.h"
#include "SpawnPoint.h"
#include "Stopwatch.h"

class Flyer {

public:

	//Set the position and texture of the Flyer
	Flyer ();
	Character getFlyer() {return _flyer;};
	void createFlyers();
	void controlMovement (Events event);
	void move (float delta_time);
	
	static int num_of_flyers = 0;
	
private:

	Character _enemy;
	
	bool _moving_up= false;
	bool _moving_down= false;
	bool _moving_left= false;
	bool _moving_right= false;
	float _pixels_per_second = 75.0f; //Flyer movement speed
	
};	
#endif