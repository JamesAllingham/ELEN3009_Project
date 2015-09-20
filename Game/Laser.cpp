#include "Laser.h"

Laser::Laser(const Vector2f& position, const Vector2f& velocity_unit) : Entity{TextureID::Laser, position, velocity_unit*300.f}
{
	//std::cout << "Create Laser" << std::endl;
	//std::cout << "Velocity x " << velocity_unit.x << " y " << velocity_unit.y  << std::endl;
};

Laser::~Laser()
{
	//std::cout << "Laser destructor" << std::endl;
}

list<Vector2f> Laser::hitboxPoints()
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

void Laser::move(float delta_time) 
{
	//std::cout << "Laser Moving" << std::endl;
	moveCharacter(velocity().x*delta_time, velocity().y*delta_time);
	//std::cout << "Position x " << character().position.x << " y " << character().position.y << std::endl;
}

shared_ptr<Entity> Laser::shoot(float delta_time) 
{
	return shared_ptr<Entity> (nullptr);
}