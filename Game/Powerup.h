#ifndef POWERUP
#define POWERUP

#include "Character.h"
#include "Entity.h"

#include <SFML/System.hpp> // This is only temporary, using SFMLs Vector2f, but later will write a lightweight vector class to use instead
using sf::Vector2f;

#include <iostream> // For debugging

#include <memory>
using std::shared_ptr;

class Powerup : public Entity
{

public:
	Powerup();
	~Powerup();
	
	//virtual void move(float delta_time) override {};
	virtual list<Vector2f> hitboxPoints() override;
	//virtual shared_ptr<Entity> shoot(float delta_time) {return shared_ptr<Entity> (nullptr);};
	virtual void collide(shared_ptr<Entity> collider) override;	
	
	static bool PowerupOnTheMap ();
	
private:		
	float _width = 42;
	float _height = 48;
	static bool _powerup_on_the_map;
};	
#endif