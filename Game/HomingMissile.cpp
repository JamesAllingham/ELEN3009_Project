#include "HomingMissile.h"

HomingMissile::HomingMissile(const Vector2f& position, const shared_ptr<Entity>& nearest_target) : Entity{TextureID::Homing_Missile, position, Vector2f(400.f,400.f)}, _nearest_target(nearest_target)
{
	std::cout << "created Homing Missile" << std::endl;
};

HomingMissile::~HomingMissile()
{
	//std::cout << "HomingMissile destructor" << std::endl;
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
	//std::cout << "HomingMissile Moving" << std::endl;
	if(_nearest_target->destroyed())
	{
		std::cout << "target destroyed" << std::endl;
		destroy();
	}
	else 
	{
		//std::cout << "Homing in on target" << std::endl;
		Vector2f velocity_unit(_nearest_target->character().position - character().position);
		velocity_unit /= sqrtf(velocity_unit.x*velocity_unit.x + velocity_unit.y*velocity_unit.y);
		moveCharacter(velocity().x*delta_time*velocity_unit.x, velocity().y*delta_time*velocity_unit.y);
		//std::cout << "Homed on target" << std::endl;
	}
	//std::cout << sqrtf(character().position.x*character().position.x + character().position.y*character().position.y) << std::endl;
	//std::cout << "Position x " << character().position.x << " y " << character().position.y << std::endl;
}

shared_ptr<Entity> HomingMissile::shoot(float delta_time) 
{
	return shared_ptr<Entity> (nullptr);
}