#ifndef FLYERS
#define FLYERS

#include <ctime>
#include <memory>
using std::shared_ptr;
using std::make_shared;

#include "Events.h"
#include "Character.h"
#include "SpawnPoint.h"
#include "Stopwatch.h"

class Flyer : public Entity
{
public:

	//Set the position and texture of the Flyer
	Flyer ();
	Character getFlyer() {return _flyer;};
	static shared_ptr<Flyer> createFlyer();
	void controlMovement (Events event);
	void move (float delta_time);
	static int numberOfFlyers () { return _number_of_flyers;};
	
private:

	static int _number_of_flyers = 0;
	Character _enemy;
	
	bool _moving_up= false;
	bool _moving_down= false;
	bool _moving_left= false;
	bool _moving_right= false;
	float _pixels_per_second = 75.0f; //Flyer movement speed
	
};	
#endif