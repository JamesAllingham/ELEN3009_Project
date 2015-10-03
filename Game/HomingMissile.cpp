#include "HomingMissile.h"

HomingMissile::HomingMissile(const Vector2f& position, const shared_ptr<Entity>& nearest_target) : MovingEntity{EntityID::Homing_Missile, position, Vector2f(_MISSILE_SPEED,_MISSILE_SPEED)}, _nearest_target(nearest_target)
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
	hitbox_points.push_back(Vector2f(top_left_point.x + _MISSILE_WIDTH, top_left_point.y));
	hitbox_points.push_back(Vector2f(top_left_point.x + _MISSILE_WIDTH, top_left_point.y - _MISSILE_HEIGHT));
	hitbox_points.push_back(Vector2f(top_left_point.x, top_left_point.y - _MISSILE_HEIGHT));
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
		Vector2f velocity_unit(_nearest_target->position() - position());
		velocity_unit /= sqrtf(velocity_unit.x*velocity_unit.x + velocity_unit.y*velocity_unit.y);
		movePosition(velocity().x*delta_time*velocity_unit.x, velocity().y*delta_time*velocity_unit.y);
	}
}
