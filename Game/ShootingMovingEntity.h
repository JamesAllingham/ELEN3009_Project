#ifndef SHOOTING_MOVING_ENTITY
#define SHOOTING_MOVING_ENTITY

#include "IShooter.h"
#include "MovingEntity.h"

class ShootingMovingEntity: public MovingEntity, public IShooter
{
	public:
		ShootingMovingEntity(EntityID entity_ID, Vector2f position, Vector2f velocity): MovingEntity{entity_ID, position, velocity} {};
		virtual void move(float delta_time) override = 0;
		virtual shared_ptr<MovingEntity> shoot(float delta_time) override = 0;
		virtual list<Vector2f> hitboxPoints() override  = 0;
		virtual void collide(shared_ptr<Entity> collider) override = 0;
};

#endif