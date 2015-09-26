#include "HomingMissile.h"

HomingMissile::HomingMissile(const Vector2f& position, const shared_ptr<Entity>& nearest_target) : Entity{EntityID::Homing_Missile, position, Vector2f(400.f,400.f)}, _nearest_target(nearest_target)
{
	//std::cout << "created Homing Missile" << std::endl;
};

HomingMissile::~HomingMissile()
{
	//std::cout << "HomingMissile destructor" << std::endl;
}

void HomingMissile::collide(shared_ptr<Entity> collider) 
{
	switch (collider->id())
	{		
		case EntityID::Flyer:		
			destroy();
			break;
		default:
			break;
	}	
}

list<Vector2f> HomingMissile::hitboxPoints()
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

void HomingMissile::move(float delta_time) 
{	
	if(_nearest_target->destroyed())
	{		
		_nearest_target.reset();
		this->destroy();
	}
	else 
	{
		Vector2f velocity_unit(_nearest_target->character().position - character().position);
		velocity_unit /= sqrtf(velocity_unit.x*velocity_unit.x + velocity_unit.y*velocity_unit.y);
		movePosition(velocity().x*delta_time*velocity_unit.x, velocity().y*delta_time*velocity_unit.y);
	}
}

shared_ptr<Entity> HomingMissile::shoot(float delta_time) 
{
	return shared_ptr<Entity> (nullptr);
}