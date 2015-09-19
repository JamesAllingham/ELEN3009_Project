#ifndef SHIP
#define SHIP

#include "Events.h"
#include "Character.h"
#include "Entity.h"

#include <SFML/System.hpp> // This is only temporary, using SFMLs Vector2f, but later will write a lightweight vector class to use instead
using sf::Vector2f;

#include <iostream> // For debugging
#include <list>
using std::list;

class Ship : public Entity {

public:
	Ship();
	void controlMovement(Events event);
	Vector2f changeInPosition();
	void addHomingMissiles() {_number_of_homing_missiles+=3;};
	int numberOfHomingMissiles() { return _number_of_homing_missiles;};
	
	virtual void move(float delta_time) override;
	virtual list<Vector2f> hitboxPoints() override;
	
private:	
	bool _moving_up = false;
	bool _moving_down = false;
	bool _moving_left = false;
	bool _moving_right = false;
	
	float _width = 75;
	float _height = 25;
	
	int _number_of_homing_missiles = 0;
	
	Vector2f _delta_position;
	
	
};	
#endif