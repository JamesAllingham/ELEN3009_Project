#include "Flyer.h"


Flyer::Flyer() : ShootingMovingEntity{EntityID::Flyer, Vector2f(randomPosition(mapLimits().x), randomPosition(mapLimits().y)), Vector2f(_FLYER_SPEED,_FLYER_SPEED)} {
	_number_of_flyers++;
}

Flyer::~Flyer()
{
	_number_of_flyers--;
	_number_of_flyers_killed++;
}

float Flyer::randomPosition (float max_positon) const {
	int largest_dimension = static_cast<int>((_FLYER_WIDTH>_FLYER_HEIGHT)?_FLYER_WIDTH:_FLYER_HEIGHT);
	int tmp = static_cast<int>(max_positon - largest_dimension);
	int rand_num = rand()%tmp;
	return static_cast<float>(rand_num);
}

void Flyer::collide(const shared_ptr<Entity>& collider) 
{
	switch (collider->id())
	{
		case EntityID::Ship:
		case EntityID::Laser:
		case EntityID::Homing_Missile:
		case EntityID::Smart_Bomb:
			destroy();
			break;
		default:
			break;
	}
}	

shared_ptr<MovingEntity> Flyer::shoot(float delta_time)
{	
	_time_since_last_shot += delta_time;
	if (_time_since_last_shot > _TIME_BETWEEN_SHOTS) 
	{
		if (abs(position().x - _target->position().x) <= _FLYER_TARGETING_RANGE) 
		{
			Vector2f velocity_unit = Vector2f(_target->position() - position()).unitVector();
			_time_since_last_shot = 0.f;
			return make_shared<Missile> (position(), velocity_unit);
		}
	}
	
	return shared_ptr<MovingEntity> (nullptr);
}

void Flyer::move(float delta_time){
	_time_since_last_movement += delta_time;
	if (_time_since_last_movement >= 1.0f) 
	{
		_unit_current_velocity = Vector2f(randomPosition(mapLimits().x) - position().x, randomPosition(mapLimits().y) - position().y).unitVector();
		_time_since_last_movement =0;
	}
	movePosition(velocity().x*delta_time*_unit_current_velocity.x, velocity().y*delta_time*_unit_current_velocity.y);	
	
}

list<Vector2f> Flyer::hitboxPoints()
{
	list<Vector2f> hitbox_points;
	Vector2f top_left_point = position();
	// Add the points in a clockwise direction
	hitbox_points.push_back(Vector2f(top_left_point.x, top_left_point.y));
	hitbox_points.push_back(Vector2f(top_left_point.x + _FLYER_WIDTH, top_left_point.y));
	hitbox_points.push_back(Vector2f(top_left_point.x + _FLYER_WIDTH, top_left_point.y - _FLYER_HEIGHT));
	hitbox_points.push_back(Vector2f(top_left_point.x, top_left_point.y - _FLYER_HEIGHT));
	return hitbox_points;
}

int Flyer::_number_of_flyers = 0;
int Flyer::_number_of_flyers_killed = 0;
shared_ptr<Entity> Flyer::_target;