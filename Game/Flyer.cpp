#include "Flyer.h"


Flyer::Flyer() : Entity{TextureID::Flyer, Vector2f(randomPosition(mapLimits().x), randomPosition(mapLimits().y)), Vector2f(75.f,75.f)} {
	
	//std::cout << "entering flyer constructor" <<std::endl;
	//_number_of_flyers = 0;
	//Entity{TextureID::Flyer, static_cast<float>(_rand_x), static_cast<float>(_rand_y), 75.f};
	//std::cout << "Create flyer" << std::endl;
	_number_of_flyers++;
}

Flyer::~Flyer()
{
	_number_of_flyers--;
	//std::cout << "Number of Flyers: " << _number_of_flyers << std::endl;
}

shared_ptr<Entity> Flyer::shoot(float delta_time)
{	
	_time_since_last_shot += delta_time;
	if (_time_since_last_shot > 10.f) 
	{
		if (abs(character().position.x - _target->character().position.x) <= 400.f) 
		{
			Vector2f velocity_unit(_target->character().position - character().position);
			velocity_unit /= sqrtf(velocity_unit.x*velocity_unit.x + velocity_unit.y*velocity_unit.y); // should check for 0's
			_time_since_last_shot = 0.f;
			return shared_ptr<Entity> (new Missile(character().position, velocity_unit));
		}
	}
	
	return shared_ptr<Entity> (nullptr);
}

// shared_ptr<Flyer> Flyer::createFlyer() {
	// shared_ptr<Flyer> flyer_ptr = make_shared<Flyer>();
	// return flyer_ptr;
// }

void Flyer::move(float delta_time){
	
	_time_since_last_movement += delta_time;
	//Vector2f unit_current_velocity(0,0);
	if (_time_since_last_movement >= 1.0f) 
	{
		_unit_current_velocity = Vector2f(randomPosition(mapLimits().x) - character().position.x, randomPosition(mapLimits().y) - character().position.y);
		_unit_current_velocity /= sqrtf(_unit_current_velocity.x*_unit_current_velocity.x + _unit_current_velocity.y*_unit_current_velocity.y);
		_time_since_last_movement =0;
	}
	//else std::cout << "x velocity "<< _unit_current_velocity.x << std::endl;
	moveCharacter(velocity().x*delta_time*_unit_current_velocity.x, velocity().y*delta_time*_unit_current_velocity.y);
	//auto distance = delta_time * _velocity;
	//if (_moving_up) _player.y -= distance;
	//if (_moving_down) _player.y += distance;
	//if (_moving_left) _player.x -= distance;
	//if (_moving_right) _player.x += distance;
	
}

// The reason that I have made this a vitual function is that in future we might want to make the flyer and ship have differently shaped hit boxes
list<Vector2f> Flyer::hitboxPoints()
{
	list<Vector2f> hitbox_points;
	Vector2f top_left_point = character().position;
	// Add the points in a clockwise direction
	hitbox_points.push_back(Vector2f(top_left_point.x, top_left_point.y));
	hitbox_points.push_back(Vector2f(top_left_point.x + _width, top_left_point.y));
	hitbox_points.push_back(Vector2f(top_left_point.x + _width, top_left_point.y - _height));
	hitbox_points.push_back(Vector2f(top_left_point.x, top_left_point.y - _height));
	return hitbox_points;
}

//Need to initialise this in the .cpp file
int Flyer::_number_of_flyers = 0;
shared_ptr<Entity> Flyer::_target;