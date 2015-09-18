#ifndef FLYERS
#define FLYERS

#include <ctime>
#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <iostream>

#include "Character.h"
#include "Entity.h"

#include <SFML/System.hpp> // This is only temporary, using SFMLs Vector2f, but later will write a lightweight vector class to use instead
using sf::Vector2f;

class Flyer : public Entity
{
public:

	//Set the position and texture of the Flyer
	Flyer ();
	//Character getFlyer() {return _flyer;};
	//shared_ptr<Flyer> createFlyer();
	virtual void move (float delta_time)  override;
	static int numberOfFlyers() { return _number_of_flyers;};
	
private:

	float RandomPosition (float max_position);

	static int _number_of_flyers;
	static bool _srand_called;
	//Character _enemy;
	bool _moving_up= false;
	bool _moving_down= false;
	bool _moving_left= false;
	bool _moving_right= false;
	
};	
#endif