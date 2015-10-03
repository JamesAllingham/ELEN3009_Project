#include "Collisions.h"
#include "Ship.h"
#include "Missile.h"
#include "Flyer.h"
#include "Vector2f.h"
#include "EntityHolder.h"

#include "gtest/gtest.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <iostream> // For testing purposes

TEST (Collision, succesfulyDetectsCollisionBetweenCollidingObjects)
{
	EntityHolder test_entity_holder;
	
	// Create a Ship and take advantage of the fact that it spawns at the center of the MAP_LIMITS to position it
	Entity::setMapLimits(Vector2f(100.f,10.f));
	shared_ptr<Ship> ship_ptr = make_shared<Ship>();
	// Create a Ship and take advantage of the fact that it spawns randomly within the MAP_LIMITS to position it
	Entity::setMapLimits(Vector2f(50.f,5.f));
	shared_ptr<Flyer> flyer_ptr = make_shared<Flyer>();
	
	shared_ptr<Missile> missile_ptr = make_shared<Missile>(ship_ptr->position(),Vector2f(0,0));	
	shared_ptr<SmartBomb> smartbomb_ptr = make_shared<SmartBomb>(0.f);
	
	test_entity_holder.addEntity(missile_ptr);
	test_entity_holder.addEntity(flyer_ptr);
	test_entity_holder.addEntity(smartbomb_ptr);
	
	Collision testCollision(test_entity_holder.begin(), test_entity_holder.end());
	testCollision.manageCollisions();
	for (auto entity : test_entity_holder)
	{
		EXPECT_TRUE(entity->destroyed());
	}
}

TEST (Collision, doesNotDetectCollisionBetweenSeparatedObjects)
{
	EntityHolder test_entity_holder;
	
	// Create a Ship and take advantage of the fact that it spawns at the center of the MAP_LIMITS to position it
	Entity::setMapLimits(Vector2f(1000.f,1000.f));
	shared_ptr<Ship> ship_ptr = make_shared<Ship>();
	// Create a Ship and take advantage of the fact that it spawns randomly within the MAP_LIMITS to position it
	Entity::setMapLimits(Vector2f(50.f,5.f));
	shared_ptr<Flyer> flyer_ptr = make_shared<Flyer>();
	
	test_entity_holder.addEntity(flyer_ptr);
	test_entity_holder.addEntity(ship_ptr);
	
	Collision testCollision(test_entity_holder.begin(), test_entity_holder.end());
	testCollision.manageCollisions();
	for (auto entity : test_entity_holder)
	{
		EXPECT_FALSE(entity->destroyed());
	}
}

TEST (Collision, succesfulyDetectsCollisionBetweenCollidingObjectsAndDoesNotDetectCollisionsBetweenSeparetedObjects)
{
	EntityHolder test_entity_holder;
	
	// Create a Ship and take advantage of the fact that it spawns at the center of the MAP_LIMITS to position it
	Entity::setMapLimits(Vector2f(2000.f,2000.f));
	shared_ptr<Ship> ship_ptr = make_shared<Ship>();
	// Create a Ship and take advantage of the fact that it spawns randomly within the MAP_LIMITS to position it
	Entity::setMapLimits(Vector2f(50.f,5.f));
	shared_ptr<Flyer> flyer_ptr = make_shared<Flyer>();
	
	shared_ptr<Missile> missile_ptr = make_shared<Missile>(ship_ptr->position(),Vector2f(0,0));	
	shared_ptr<SmartBomb> smartbomb_ptr = make_shared<SmartBomb>(0.f);
	
	test_entity_holder.addEntity(missile_ptr);
	test_entity_holder.addEntity(flyer_ptr);
	test_entity_holder.addEntity(smartbomb_ptr);
	test_entity_holder.addEntity(ship_ptr);
	
	Collision testCollision(test_entity_holder.begin(), test_entity_holder.end());
	testCollision.manageCollisions();
	
	for (auto entity_itr = test_entity_holder.begin(); entity_itr != prev(test_entity_holder.end()); entity_itr++)
	{
		EXPECT_TRUE((*entity_itr)->destroyed());
	}
	EXPECT_FALSE((*prev(test_entity_holder.end()))->destroyed());
}