#ifndef FLYERS
#define FLYERS

#include <ctime>
#include <cmath>
#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <iostream> // For testing purposes

#include "ShootingMovingEntity.h"
#include "Missile.h"
#include "EntityId.h"

#include "Vector2f.h"

//class Ship;

class Flyer : public ShootingMovingEntity
{
public:
	Flyer ();
	~Flyer();	
	static int numberOfFlyers() { return _number_of_flyers;};
	static int numberOfFlyersKilled() { return _number_of_flyers_killed;};
	static void setTarget(const shared_ptr<Entity>& target) { _target = target;};
	
	virtual void move (float delta_time)  override;
	virtual list<Vector2f> hitboxPoints() override;	
	virtual shared_ptr<MovingEntity> shoot(float delta_time) override;
	virtual void collide(shared_ptr<Entity> collider) override;	
	
private:

	static int _number_of_flyers;
	static int _number_of_flyers_killed;
	static shared_ptr<Entity> _target;
	
	float _width = 75;
	float _height = 37;
	
	float _time_since_last_shot = 9.f;
	float _time_since_last_movement = 1.0f;
	Vector2f _unit_current_velocity;	
	
};	
#endif