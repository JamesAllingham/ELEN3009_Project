#include "Ship.h"


Ship::Ship() : ShootingMovingEntity{EntityID::Ship, Vector2f(mapLimits().x/2, mapLimits().y/2), Vector2f(250.f,250.f)}, _delta_position(0,0) 
{
	
};

void Ship::collide(shared_ptr<Entity> collider) 
{
	switch (collider->id())
	{
		case EntityID::Power_Up:
			addHomingMissiles();
			break;
		case EntityID::Flyer:
		case EntityID::Missile:		
			_number_of_lives --;
			if (_number_of_lives == 0)
			{
				destroy();
			}
			break;
		default:
			break;
	}	
}	

shared_ptr<MovingEntity> Ship::shoot(float delta_time)
{
	if (_shooting) 
	{
		_shooting = false;
		Vector2f velocity_unit;
		if (facingRight()) 
		{
			velocity_unit = Vector2f(1,0);
			return shared_ptr<MovingEntity> (new Laser(position() + Vector2f(75.f, (37.f - 7.f)/2), velocity_unit));
		}
		else 
		{
			velocity_unit = Vector2f(-1,0);
			return shared_ptr<MovingEntity> (new Laser(position()  + Vector2f(-25.f, (37.f - 7.f)/2), velocity_unit));
		}
	}
	
	if (_nearest_target.unique())
	{
		_nearest_target.reset();
		return shared_ptr<MovingEntity> (nullptr);
	}
	
	if (_shoot_homing_missile)
	{
		// check that the missile has a valid target
		if (_nearest_target.unique())
		{
			_nearest_target.reset();
			return shared_ptr<MovingEntity> (nullptr);
		}
		_shoot_homing_missile = false;
		if (_number_of_homing_missiles > 0)
		{
			--_number_of_homing_missiles;
			return shared_ptr<MovingEntity> (new HomingMissile(position()  + Vector2f(75.f, (37.f - 23.f)/2), _nearest_target));
		}		
	}
	
	if (_shoot_smart_bomb)
	{
		_shoot_smart_bomb = false;
		if (_number_of_smart_bombs > 0)
		{
			std::cout<<"shooting smart bomb" << std::endl;
			--_number_of_smart_bombs;
			return shared_ptr<MovingEntity> (new SmartBomb(Vector2f(character().position().x - 400.f, 0.f)));
		}
		else return shared_ptr<MovingEntity> (nullptr);
	}

	return shared_ptr<MovingEntity> (nullptr);
	
}

void Ship::controlShooting(Events event)
{
	switch (event){
		case Events::Space_Pressed:
			_shooting = true;
			break;
		case Events::E_Pressed:
			_shoot_homing_missile = true;
			break;
		case Events::Q_Pressed:
			_shoot_smart_bomb = true;
			break;
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
	Vector2f old_position = position() ;
	auto distance = delta_time * velocity();
	if (_moving_up) movePosition(0, -distance.y);
	if (_moving_down) movePosition(0, distance.y);
	if (_moving_left) movePosition(-distance.x,0);
	if (_moving_right) movePosition(distance.x,0);
	_delta_position =  position()  - old_position;
	
	if ( (_moving_left && !_moving_right && facingRight()) || (!_moving_left && _moving_right && !facingRight()) )
	{		
		switchDirection();
	}
}

// The reason that I have made this a vitual function is that in future we might want to make the flyer and ship have differently shaped hit boxes
list<Vector2f> Ship::hitboxPoints()
{
	list<Vector2f> hitbox_points;
	Vector2f top_left_point = position() ;
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
		if (target->id() == EntityID::Flyer)
		{
			auto diff_in_x = target->position().x - position() .x;
			auto diff_in_y = target->position().y - position() .y;
			auto distance = sqrtf(diff_in_x*diff_in_x + diff_in_y*diff_in_y);
			if ( distance < minimum)
			{
				_nearest_target = target;
				minimum = distance;
			}
			
		}
	}
}
