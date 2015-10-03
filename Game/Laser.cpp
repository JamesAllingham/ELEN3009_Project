#include "Laser.h"

Laser::Laser(const Vector2f& position, const Vector2f& velocity_unit) : MovingEntity{EntityID::Laser, position, velocity_unit*_LASER_SPEED}
{
	
};

void Laser::collide(const shared_ptr<Entity>& collider)
{
	switch (collider->id())
	{		
		case EntityID::Flyer:
		case EntityID::Missile:			
			destroy();
			break;
		default:
			break;
	}	
}	

list<Vector2f> Laser::hitboxPoints()
{
	list<Vector2f> hitbox_points;
	Vector2f top_left_point = position();
	// Add the points in a clockwise direction
	hitbox_points.push_back(Vector2f(top_left_point.x, top_left_point.y));
	hitbox_points.push_back(Vector2f(top_left_point.x + _LASER_WIDTH, top_left_point.y));
	hitbox_points.push_back(Vector2f(top_left_point.x + _LASER_WIDTH, top_left_point.y - _LASER_HEIGHT));
	hitbox_points.push_back(Vector2f(top_left_point.x, top_left_point.y - _LASER_HEIGHT));
	return hitbox_points;
}

void Laser::move(float delta_time) 
{	
	movePosition(velocity().x*delta_time, velocity().y*delta_time);
	if (position().x == mapLimits().x || position().x == 0.f || position().y == mapLimits().y || position().y == 0.f)
	{
		destroy();
	}
}