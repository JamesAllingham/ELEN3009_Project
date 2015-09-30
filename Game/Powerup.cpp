#include "Powerup.h"

Powerup::Powerup() : Entity{EntityID::Power_Up, Vector2f(randomPosition(mapLimits().x), randomPosition(mapLimits().y))}
{
	_powerup_on_the_map = true;
};

Powerup::~Powerup()
{
	_powerup_on_the_map = false;
}

float Powerup::randomPosition (float max_positon) {
	// This function needs to take into account the size of the flyer so that they don't spawn half off of the screen
	// Need to fix this static call to seed the random function
	int rand_num;
	int tmp = static_cast<int>(max_positon);
	rand_num = rand()%tmp;
	return static_cast<float>(rand_num);
}

void Powerup::collide(shared_ptr<Entity> collider) 
{	
	switch (collider->id())
	{		
		case EntityID::Ship:	
			destroy();
			break;
		default:
			break;
	}	
}

list<Vector2f> Powerup::hitboxPoints()
{
	list<Vector2f> hitbox_points;
	Vector2f top_left_point = position();
	// Add the points in a clockwise direction
	hitbox_points.push_back(Vector2f(top_left_point.x, top_left_point.y));
	hitbox_points.push_back(Vector2f(top_left_point.x + _POWER_UP_WIDTH, top_left_point.y));
	hitbox_points.push_back(Vector2f(top_left_point.x + _POWER_UP_WIDTH, top_left_point.y - _POWER_UP_HEIGHT));
	hitbox_points.push_back(Vector2f(top_left_point.x, top_left_point.y - _POWER_UP_HEIGHT));
	return hitbox_points;
}

bool Powerup::PowerupOnTheMap()
{
	return _powerup_on_the_map;
}

bool Powerup::_powerup_on_the_map = false;