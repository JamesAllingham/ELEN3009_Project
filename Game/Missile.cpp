#include "Missile.h"

Missile::Missile(const Vector2f& position, const Vector2f& velocity_unit) : Entity{TextureID::Missile, position, velocity_unit*90.f}
{
	//std::cout << "Create Missile" << std::endl;
	//std::cout << "Velocity x " << velocity_unit.x << " y " << velocity_unit.y  << std::endl;
};

Missile::~Missile()
{
	//std::cout << "Missile destructor" << std::endl;
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
	//std::cout << "Missile Moving" << std::endl;
	moveCharacter(velocity().x*delta_time, velocity().y*delta_time);
	//std::cout << sqrtf(character().position.x*character().position.x + character().position.y*character().position.y) << std::endl;
	//std::cout << "Position x " << character().position.x << " y " << character().position.y << std::endl;
}

shared_ptr<Entity> Missile::shoot(float delta_time) 
{
	return shared_ptr<Entity> (nullptr);
}