#include "Powerup.h"

Powerup::Powerup() : Entity{EntityID::Power_Up, Vector2f(Entity::randomPosition(mapLimits().x), Entity::randomPosition(mapLimits().y)), Vector2f(0.f,0.f)}
{
	_powerup_on_the_map = true;
};

Powerup::~Powerup()
{
	_powerup_on_the_map = false;
}

void Powerup::collide(shared_ptr<Entity> collider) 
{
	//std::cout << "Collide powerup" << std::endl;	
	switch (collider->id())
	{		
		case EntityID::Ship:
			//std::cout << "Powerup destroy" << std::endl;	
			destroy();
			break;
		default:
			break;
	}	
}

list<Vector2f> Powerup::hitboxPoints()
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

bool Powerup::PowerupOnTheMap()
{
	return _powerup_on_the_map;
}

bool Powerup::_powerup_on_the_map = false;