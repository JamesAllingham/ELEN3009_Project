#include "Missile.h"

Missile::Missile(const Vector2f& position, const Vector2f& velocity_unit) : Entity{EntityID::Missile, position, velocity_unit*90.f}
{
	//std::cout << "Create Missile" << std::endl;
	//std::cout << "Velocity x " << velocity_unit.x << " y " << velocity_unit.y  << std::endl;
};

Missile::~Missile()
{
	//std::cout << "Missile destructor" << std::endl;
}

void Missile::collide(shared_ptr<Entity> collider) 
{
	switch (collider->id())
	{		
		case EntityID::Ship:
		case EntityID::Laser:			
			destroy();
			break;
		default:
			break;
	}	
}

list<Vector2f> Missile::hitboxPoints()
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

void Missile::move(float delta_time) 
{	
	movePosition(velocity().x*delta_time, velocity().y*delta_time);

	if (position().x == mapLimits().x || position().x == 0.f || position().y == mapLimits().y || position().y == 0.f)
	{
		this->destroy();
	}	
}

shared_ptr<Entity> Missile::shoot(float delta_time) 
{
	return shared_ptr<Entity> (nullptr);
}