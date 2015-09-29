#ifndef SHIP
#define SHIP

#include "ShootingMovingEntity.h"
#include "Events.h"
#include "Laser.h"
#include "HomingMissile.h"
#include "EntityHolder.h"
#include "SmartBomb.h"
#include "EntityID.h"

#include "Vector2f.h"

#include <iostream> // For debugging
#include <list>
using std::list;
#include <memory>
using std::shared_ptr;
#include <limits>
using std::numeric_limits;

class Ship : public ShootingMovingEntity
{

public:
	Ship();
	void controlMovement(Events event);
	void controlShooting(Events event);
	Vector2f changeInPosition();
	void addHomingMissiles() {_number_of_homing_missiles+=3;};
	int numberOfHomingMissiles() { return _number_of_homing_missiles;};
	void switchDirection () {_facing_right = !_facing_right;};
	bool facingRight () {return _facing_right;};
	void setNearestTarget(EntityHolder& targets);
	shared_ptr<Entity> nearestTarget() { return _nearest_target;};
	
	virtual void move(float delta_time) override;
	virtual list<Vector2f> hitboxPoints() override;
	virtual shared_ptr<MovingEntity> shoot(float delta_time) override;	
	virtual void collide(shared_ptr<Entity> collider) override;
	int numberOfLivesRemaining () {return _number_of_lives;};
	
private:	
	bool _moving_up = false;
	bool _moving_down = false;
	bool _moving_left = false;
	bool _moving_right = false;
	bool _facing_right = true;
	
	bool _shooting = false;
	bool _shoot_homing_missile = false;
	bool _shoot_smart_bomb = false;
	
	float _width = 75;
	float _height = 25;
	
	shared_ptr<Entity> _nearest_target;
	int _number_of_homing_missiles = 0;
	int _number_of_lives = 3;
	int _number_of_smart_bombs = 2;
	
	Vector2f _delta_position;
	
	
};	
#endif