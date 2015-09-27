#include "SmartBomb.h"

SmartBomb::SmartBomb(const Vector2f& position, const list<shared_ptr<Entity>>& targets) : Entity{TextureID::Smart_Bomb, Vector2f(Entity::randomPosition(mapLimits().x), Entity::randomPosition(mapLimits().y)), Vector2f(0.f,0.f)}, _targets(targets)
{
	//std::cout << "Create SmartBomb" << std::endl;
	//std::cout << "Velocity x " << velocity_unit.x << " y " << velocity_unit.y  << std::endl;
};

SmartBomb::~SmartBomb()
{
	//std::cout << "SmartBomb destructor" << std::endl;
}

list<Vector2f> SmartBomb::hitboxPoints()
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

virtual shared_ptr<Entity> shoot(float delta_time) 
{
	
	return shared_ptr<Entity> (nullptr);
}