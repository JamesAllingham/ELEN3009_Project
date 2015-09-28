#include "Flyer.h"


Flyer::Flyer() : ShootingMovingEntity{EntityID::Flyer, Vector2f(randomPosition(mapLimits().x), randomPosition(mapLimits().y)), Vector2f(75.f,75.f)} {
	_number_of_flyers++;
}

Flyer::~Flyer()
{
	_number_of_flyers--;
	_number_of_flyers_killed++;
}

void Flyer::collide(shared_ptr<Entity> collider) 
{
	switch (collider->id())
	{
		case EntityID::Ship:
		case EntityID::Laser:
		case EntityID::Homing_Missile:		
			destroy();
			break;
		default:
			break;
	}
}	

shared_ptr<MovingEntity> Flyer::shoot(float delta_time)
{	
	_time_since_last_shot += delta_time;
	if (_time_since_last_shot > 10.f) 
	{
		if (abs(position().x - _target->position().x) <= 400.f) 
		{
			Vector2f velocity_unit(_target->position() - position());
			velocity_unit /= sqrtf(velocity_unit.x*velocity_unit.x + velocity_unit.y*velocity_unit.y); // should check for 0's
			_time_since_last_shot = 0.f;
			return shared_ptr<MovingEntity> (new Missile(position(), velocity_unit));
		}
	}
	
	return shared_ptr<MovingEntity> (nullptr);
}

void Flyer::move(float delta_time){
	_time_since_last_movement += delta_time;
	if (_time_since_last_movement >= 1.0f) 
	{
		_unit_current_velocity = Vector2f(randomPosition(mapLimits().x) - position().x, randomPosition(mapLimits().y) - position().y);
		_unit_current_velocity /= sqrtf(_unit_current_velocity.x*_unit_current_velocity.x + _unit_current_velocity.y*_unit_current_velocity.y);
		_time_since_last_movement =0;
	}
	movePosition(velocity().x*delta_time*_unit_current_velocity.x, velocity().y*delta_time*_unit_current_velocity.y);	
	
}

// The reason that I have made this a vitual function is that in future we might want to make the flyer and ship have differently shaped hit boxes
list<Vector2f> Flyer::hitboxPoints()
{
	list<Vector2f> hitbox_points;
	Vector2f top_left_point = position();
	// Add the points in a clockwise direction
	hitbox_points.push_back(Vector2f(top_left_point.x, top_left_point.y));
	hitbox_points.push_back(Vector2f(top_left_point.x + _width, top_left_point.y));
	hitbox_points.push_back(Vector2f(top_left_point.x + _width, top_left_point.y - _height));
	hitbox_points.push_back(Vector2f(top_left_point.x, top_left_point.y - _height));
	return hitbox_points;
}

//Need to initialise this in the .cpp file
int Flyer::_number_of_flyers = 0;
int Flyer::_number_of_flyers_killed = 0;
shared_ptr<Entity> Flyer::_target;