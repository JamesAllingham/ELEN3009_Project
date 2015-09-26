#ifndef MISSILE
#define MISSILE

#include "Character.h"
#include "Entity.h"

#include <SFML/System.hpp> // This is only temporary, using SFMLs Vector2f, but later will write a lightweight vector class to use instead
using sf::Vector2f;

#include <iostream> // For debugging

#include <memory>
using std::shared_ptr;

class Missile : public Entity {

public:
	Missile(const Vector2f& position, const Vector2f& velocity_unit);	
	~Missile();
	
	virtual void move(float delta_time) override;
	virtual list<Vector2f> hitboxPoints() override;
	virtual shared_ptr<Entity> shoot(float delta_time);
	virtual void collide(shared_ptr<Entity> collider) override;	
	
private:		
	float _width = 25;
	float _height = 25;	
};	
#endif