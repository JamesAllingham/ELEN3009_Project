#ifndef HOMING_MISSILE
#define HOMING_MISSILE

#include "Character.h"
#include "Entity.h"
#include "Flyer.h"

#include <SFML/System.hpp> // This is only temporary, using SFMLs Vector2f, but later will write a lightweight vector class to use instead
using sf::Vector2f;

#include <iostream> // For debugging

#include <memory>
using std::shared_ptr;

class HomingMissile : public Entity {

public:
	HomingMissile(const Vector2f& position, const shared_ptr<Entity>& nearest_target);	
	~HomingMissile();
	
	virtual void move(float delta_time) override;
	virtual list<Vector2f> hitboxPoints() override;
	virtual shared_ptr<Entity> shoot(float delta_time);
	
private:		
	float _width = 25;
	float _height = 25;
	shared_ptr<Entity> _nearest_target;
};	
#endif