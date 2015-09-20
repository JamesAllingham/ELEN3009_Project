#include "Ship.h"
#include "Flyer.h"

Ship::Ship() : Entity{TextureID::Ship, Vector2f(mapLimits().x/2, mapLimits().y/2), Vector2f(250.f,250.f)}, _delta_position(0,0) 
{
	//std::cout << "Create ship" << std::endl;
};

shared_ptr<Entity> Ship::shoot(float delta_time)
{
	if (_shooting) 
	{
		_shooting = false;
		Vector2f velocity_unit;
		if (facingRight()) 
		{
			velocity_unit = Vector2f(1,0);
			return shared_ptr<Entity> (new Laser(character().position + Vector2f(75.f, (37.f - 7.f)/2), velocity_unit));
		}
		else 
		{
			velocity_unit = Vector2f(-1,0);
			return shared_ptr<Entity> (new Laser(character().position + Vector2f(-25.f, (37.f - 7.f)/2), velocity_unit));
		}
	}
	
	if (_shoot_homing_missile)
	{
		
		_shoot_homing_missile = false;
		if (_number_of_homing_missiles > 0)
		{
			--_number_of_homing_missiles;
			return shared_ptr<Entity> (new HomingMissile(character().position + Vector2f(75.f, (37.f - 23.f)/2), _nearest_target));
		}
		
		
	}

	return shared_ptr<Entity> (nullptr);
	
}

void Ship::controlShooting(Events event)
{
	switch (event){
		case Events::Space_Pressed:
			_shooting = true;
			break;
		case Events::E_Pressed:
			_shoot_homing_missile = true;
		default:
			break;
	}
}

void Ship::controlMovement(Events event)
{
	
	switch (event){
		case Events::W_Pressed:
			_moving_up = true;
			break;
		case Events::W_Released:
			_moving_up = false;
			break;
		case Events::S_Pressed:
			_moving_down = true;
			break;
		case Events::S_Released:
			_moving_down = false;
			break;
		case Events::A_Pressed:
			_moving_left = true;
			break;
		case Events::A_Released:
			_moving_left = false;
			break;
		case Events::D_Pressed:
			_moving_right = true;
			break;
		case Events::D_Released:
			_moving_right = false;
			break;
		default:
			break;
	}
}

void Ship::move(float delta_time) 
{
	Vector2f old_position = position();
	auto distance = delta_time * velocity();
	if (_moving_up) moveCharacter(0, -distance.y);
	if (_moving_down) moveCharacter(0, distance.y);
	if (_moving_left) moveCharacter(-distance.x,0);
	if (_moving_right) moveCharacter(distance.x,0);
	_delta_position =  position() - old_position;
	
	if ( (_moving_left && !_moving_right && facingRight()) || (!_moving_left && _moving_right && !facingRight()) )
	{
		//if (facingRight()) moveCharacter(_width,0);
		//else moveCharacter(-_width,0);
		switchDirection();
	}
}

// The reason that I have made this a vitual function is that in future we might want to make the flyer and ship have differently shaped hit boxes
list<Vector2f> Ship::hitboxPoints()
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

Vector2f Ship::changeInPosition() 
{
	Vector2f delta_position = _delta_position;
	_delta_position = Vector2f(0,0);
	
	return delta_position;	
}

void Ship::setNearestTarget(EntityHolder& targets) 
{
	auto minimum = numeric_limits<float>::max();
	for ( auto target : targets)
	{
		if (target->character().texture_ID == TextureID::Flyer)
		{
			auto diff_in_x = target->character().position.x - character().position.x;
			auto diff_in_y = target->character().position.y - character().position.y;
			auto distance = sqrtf(diff_in_x*diff_in_x + diff_in_y*diff_in_y);
			if ( distance < minimum)
			{
				_nearest_target = target;
				minimum = distance;
			}
			
		}
	}
}