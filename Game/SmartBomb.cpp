#include "SmartBomb.h"

SmartBomb::SmartBomb(const Vector2f& position) : MovingEntity{EntityID::Smart_Bomb, position, Vector2f(_SMART_BOMB_SPEED,_SMART_BOMB_SPEED)}
{
	
};

void SmartBomb::collide(shared_ptr<Entity> collider) 
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

list<Vector2f> SmartBomb::hitboxPoints()
{
	list<Vector2f> hitbox_points;
	Vector2f top_left_point = character().position();
	// Add the points in a clockwise direction
	hitbox_points.push_back(Vector2f(top_left_point.x, top_left_point.y));
	hitbox_points.push_back(Vector2f(top_left_point.x + _SMART_BOMB_WIDTH, top_left_point.y));
	hitbox_points.push_back(Vector2f(top_left_point.x + _SMART_BOMB_WIDTH, top_left_point.y - _SMART_BOMB_HEIGHT));
	hitbox_points.push_back(Vector2f(top_left_point.x, top_left_point.y - _SMART_BOMB_HEIGHT));
	return hitbox_points;
}