#include "Collisions.h"
#include "Ship.h"
#include "Flyer.h"

#include "Vector2f.h"

#include "gtest/gtest.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <iostream> // For testing purposes

// All needs to be redone based on the new Collision class, which handles more of the functionality than it used to, I'll do this soon.
/*
TEST(Collision, doesntGiveFalsePositiveForNonCollisions)
{
	Collision collision;
	
	//Set the map limits to control the spawning of the Ship and Flyer for testing purposes
	Entity::setMapLimits(Vector2f(1.f,1.f));
	shared_ptr<Flyer> flyer_ptr = make_shared<Flyer>();
	
	//Create a Ship and take advantage of the fact that it spawns at the centre of the MAP_LIMITS to position it
	Entity::setMapLimits(Vector2f(2.f,100.f));
	shared_ptr<Ship> ship_ptr1 = make_shared<Ship>();
	
	//Test for a false positive when there is an overlap on one axis
	EXPECT_FALSE(collision.collision(flyer_ptr,ship_ptr1));
	
	//Create a Ship and take advantage of the fact that it spawns at the centre of the MAP_LIMITS to position it
	Entity::setMapLimits(Vector2f(200.f,2.f));
	shared_ptr<Ship> ship_ptr2 = make_shared<Ship>();
	
	//Test for a false positive when there is an overlap on one axis
	EXPECT_FALSE(collision.collision(flyer_ptr,ship_ptr2));
	
	//Create a Ship and take advantage of the fact that it spawns at the centre of the MAP_LIMITS to position it
	Entity::setMapLimits(Vector2f(200.f,100.f));
	shared_ptr<Ship> ship_ptr3 = make_shared<Ship>();
	
	//Test for a false positive when there is an overlap on no axes
	EXPECT_FALSE(collision.collision(flyer_ptr,ship_ptr3));
	
}


TEST(Collision, givePositiveForCollisions)
{
	Collision collision;
	
	// Create a Ship and take advantage of the fact that it spawns at the center of the MAP_LIMITS to position it
	Entity::setMapLimits(Vector2f(100.f,10.f));
	shared_ptr<Ship> ship_ptr1 = make_shared<Ship>();
	// std::cout << "Ship " << ship_ptr1->character().position.x << " " << ship_ptr1->character().position.y << std::endl; 
	
	// Set the map limits to control the spawning of the Flyer for testing purposes, force it to spawn randomly within the  
	Entity::setMapLimits(Vector2f(50.f,5.f));
	shared_ptr<Flyer> flyer_ptr = make_shared<Flyer>();
	// std::cout << "Flyer " << flyer_ptr->character().position.x << " " << flyer_ptr->character().position.y << std::endl; 
	
	
	// Test for a collision when there is an overlap
	EXPECT_TRUE(collision.collision(flyer_ptr,ship_ptr1));	
}
*/