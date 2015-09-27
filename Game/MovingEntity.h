#ifndef MOVING_ENTITY
#define MOVING_ENTITY

#include "IMover.h"
#include "Entity.h"

class MovingEntity: public Entity, public IMover
{
	public:
		MovingEntity(EntityID entity_ID, Vector2f position, Vector2f velocity): Entity{entity_ID, position, velocity} {};
		virtual void move(float delta_time) override = 0;
		virtual list<Vector2f> hitboxPoints() override = 0;
		virtual void collide(shared_ptr<Entity> collider) override = 0;	
};

#endif