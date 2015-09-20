#include "Powerup.h"

Powerup::Powerup() : Entity{TextureID::Powerup, Vector2f(Entity::randomPosition(mapLimits().x), Entity::randomPosition(mapLimits().y)), Vector2f(0.f,0.f)}
{
	_powerup_on_the_map = true;
	//std::cout << "Create Powerup" << std::endl;
	//std::cout << "Velocity x " << velocity_unit.x << " y " << velocity_unit.y  << std::endl;
};

Powerup::~Powerup()
{
	_powerup_on_the_map = false;
	//std::cout << "Powerup destructor" << std::endl;
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

bool Powerup::PowerupOnTheMap ()
{
	return _powerup_on_the_map;
}

bool Powerup::_powerup_on_the_map = false;