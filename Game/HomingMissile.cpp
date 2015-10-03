#include "HomingMissile.h"

HomingMissile::HomingMissile(const Vector2f& position, const shared_ptr<Entity>& nearest_target) : MovingEntity{EntityID::Homing_Missile, position, Vector2f(_HOMING_MISSILE_SPEED,_HOMING_MISSILE_SPEED)}, _target(nearest_target)
{
	
};

void HomingMissile::collide(const shared_ptr<Entity>& collider) 
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
	Vector2f top_left_point = position();
	// Add the points in a clockwise direction
	hitbox_points.push_back(Vector2f(top_left_point.x, top_left_point.y));
	hitbox_points.push_back(Vector2f(top_left_point.x + _HOMING_MISSILE_WIDTH, top_left_point.y));
	hitbox_points.push_back(Vector2f(top_left_point.x + _HOMING_MISSILE_WIDTH, top_left_point.y - _HOMING_MISSILE_HEIGHT));
	hitbox_points.push_back(Vector2f(top_left_point.x, top_left_point.y - _HOMING_MISSILE_HEIGHT));
	return hitbox_points;
}

void HomingMissile::move(float delta_time) 
{	
	if(_target->destroyed())
	{		
		_target.reset();
		this->destroy();
	}
	else 
	{
		Vector2f velocity_unit = Vector2f(_target->position() - position()).unitVector();
		movePosition(velocity().x*delta_time*velocity_unit.x, velocity().y*delta_time*velocity_unit.y);
	}
}
