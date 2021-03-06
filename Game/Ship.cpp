#include "Ship.h"


Ship::Ship() : ShootingMovingEntity{EntityID::Ship, Vector2f(mapLimits().x/2 - _SHIP_WIDTH/2, mapLimits().y/2 - _SHIP_HEIGHT/2), Vector2f(_SHIP_SPEED,_SHIP_SPEED)}, _delta_position(0,0) 
{
	
};

void Ship::collide(const shared_ptr<Entity>& collider) 
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

void Ship::controlShooting(Events event)
{
	switch (event){
		case Events::Space_Pressed:
			_shoot_laser = true;
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

shared_ptr<MovingEntity> Ship::shoot(float delta_time)
{
	if (_shoot_laser) 
	{
		_shoot_laser = false;
		Vector2f velocity_unit;
		if (facingRight()) 
		{
			velocity_unit = Vector2f(1,0);			
		}
		else 
		{
			velocity_unit = Vector2f(-1,0);
		}
		return make_shared<Laser> (position() + Vector2f(_LASER_X_OFFSET,_LASER_Y_OFFSET), velocity_unit);
	}
	
	if (_nearest_target.unique())
	{
		_nearest_target.reset();
		return shared_ptr<MovingEntity> (nullptr);
	}
	
	if (_shoot_homing_missile)
	{
		if (_nearest_target.unique())
		{
			_nearest_target.reset();
			return shared_ptr<MovingEntity> (nullptr);
		}
		_shoot_homing_missile = false;
		if (_number_of_homing_missiles > 0)
		{
			--_number_of_homing_missiles;
			return make_shared<HomingMissile> (position()  + Vector2f(_HOMING_MISSILE_X_OFFSET,_HOMING_MISSILE_Y_OFFSET), _nearest_target);
		}		
	}
	
	if (_shoot_smart_bomb)
	{
		_shoot_smart_bomb = false;
		if (_number_of_smart_bombs > 0)
		{
			--_number_of_smart_bombs;
			return make_shared<SmartBomb> (position().x + _SMART_BOMB_X_OFFSET);
		}
		else return shared_ptr<MovingEntity> (nullptr);
	}

	return shared_ptr<MovingEntity> (nullptr);
	
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
	if (_moving_down) !(position().y + distance.y + _SHIP_HEIGHT> mapLimits().y) ? movePosition(0, distance.y) : movePosition(0, mapLimits().y - _SHIP_HEIGHT - position().y);
	if (_moving_left) movePosition(-distance.x,0);
	if (_moving_right) !(position().x + distance.x + _SHIP_WIDTH> mapLimits().x) ? movePosition(distance.x,0) : movePosition(mapLimits().x - _SHIP_WIDTH - position().x,0);;
	_delta_position =  position()  - old_position;
	
	if ( (_moving_left && !_moving_right && facingRight()) || (!_moving_left && _moving_right && !facingRight()) )
	{		
		switchDirection();
	}
}

list<Vector2f> Ship::hitboxPoints()
{
	list<Vector2f> hitbox_points;
	Vector2f top_left_point = position() ;
	// Add the points in a clockwise direction
	hitbox_points.push_back(Vector2f(top_left_point.x, top_left_point.y));
	hitbox_points.push_back(Vector2f(top_left_point.x + _SHIP_WIDTH, top_left_point.y));
	hitbox_points.push_back(Vector2f(top_left_point.x + _SHIP_WIDTH, top_left_point.y - _SHIP_HEIGHT));
	hitbox_points.push_back(Vector2f(top_left_point.x, top_left_point.y - _SHIP_HEIGHT));
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
			auto distance = position().distanceBetweenVectors(target->position(), position());
			if ( distance < minimum)
			{
				_nearest_target = target;
				minimum = distance;
			}
			
		}
	}
}

list<int>& Ship::status() 
{
	_status.clear();
	_status = {_number_of_lives, _number_of_smart_bombs, _number_of_homing_missiles};
	return _status;
}