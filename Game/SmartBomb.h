#ifndef SMART_BOMB
#define SMART_BOMB

#include "Character.h"
#include "Entity.h"

#include <SFML/System.hpp> // This is only temporary, using SFMLs Vector2f, but later will write a lightweight vector class to use instead
using sf::Vector2f;

#include <iostream> // For debugging

#include <memory>
using std::shared_ptr;

class SmartBomb : public Entity {

public:
	SmartBomb(const Vector2f& position, const shared_ptr<Entity>& nearest_target);
	~SmartBomb();
	
	virtual void move(float delta_time) override {};
	virtual list<Vector2f> hitboxPoints() override;
	virtual shared_ptr<Entity> shoot(float delta_time);
	
private:		
	float _width = 23;
	float _height = 25;
	const list<shared_ptr<Entity>> targets;
};	
#endif