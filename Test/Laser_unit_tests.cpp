#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <iostream> // For testing purposes

#include "Laser.h"
#include "Flyer.h"
#include "Missile.h"


#include "gtest/gtest.h"

TEST (Laser, constructorCorectlyPlacesLaserWithCorrectVelocityDirection)
{
	Laser test_laser1(Vector2f(1.f,1.f),Vector2f(0.f,1.f));
	EXPECT_TRUE(Vector2f(1.f,1.f) == test_laser1.position());
	EXPECT_TRUE(Vector2f(0.f,1.f) == test_laser1.velocity().unitVector());
	
	Laser test_laser2(Vector2f(100.f,0.f),Vector2f(-1.f,0.f));
	EXPECT_TRUE(Vector2f(100.f,0.f) == test_laser2.position());
	EXPECT_TRUE(Vector2f(-1.f,0.f) == test_laser2.velocity().unitVector());
}

TEST (Laser, LaserGetsDestryedWhenCollidingWithFlyer)
{
	Laser test_laser(Vector2f(1.f,1.f),Vector2f(0.f,1.f));
	shared_ptr<Flyer> test_flyer_ptr = make_shared<Flyer>();
	
	test_laser.collide(test_flyer_ptr);
	EXPECT_TRUE(test_laser.destroyed());
}

TEST (Laser, LaserGetsDestryedWhenCollidingWithMissile)
{
	Laser test_laser1(Vector2f(1.f,1.f),Vector2f(0.f,1.f));
	shared_ptr<Missile> test_missile_ptr = make_shared<Missile>(Vector2f(100.f,0.f),Vector2f(0.f,1.f));
	
	test_laser1.collide(test_missile_ptr);
	EXPECT_TRUE(test_laser1.destroyed());
}

TEST (Laser, LaserHitboxIsTheCorrectShape)
{
	//testing for a box
	Laser test_laser(Vector2f(1.f,1.f),Vector2f(0.f,1.f));
	list<Vector2f> hitbox = test_laser.hitboxPoints();
	//test top section = bottom section
	Vector2f top_length = *next(hitbox.begin()) - hitbox.front();
	Vector2f bottom_length = *prev(hitbox.end(),2) - hitbox.back();
	EXPECT_TRUE(top_length == bottom_length);
	//test left section == right section
	Vector2f left_length = hitbox.back() - hitbox.front();
	Vector2f right_length = *prev(hitbox.end(),2) - *next(hitbox.begin());
	EXPECT_TRUE(left_length == right_length);
}

TEST (Laser, LaserHitboxIsAlwaysTheSameAreaRegardlessOfPositionOnMap)
{
	//test dependent on random position generation for the flyers
	Laser test_laser1(Vector2f(1.f,1.f),Vector2f(0.f,1.f));
	list<Vector2f> hitbox1 = test_laser1.hitboxPoints();
	Vector2f top_length = *next(hitbox1.begin()) - hitbox1.front();
	Vector2f bottom_length = *prev(hitbox1.end(),2) - hitbox1.back();
	Vector2f left_length = hitbox1.front() - hitbox1.back();
	Vector2f right_length = *next(hitbox1.begin()) - *prev(hitbox1.end(),2);
	auto area1 = top_length * left_length;
	auto area1_again = bottom_length*right_length;
	Laser test_laser2(Vector2f(100.f,0.f),Vector2f(-1.f,0.f));
	list<Vector2f> hitbox2 = test_laser2.hitboxPoints();
	Vector2f top_length2 = *next(hitbox2.begin()) - hitbox2.front();
	Vector2f bottom_length2 = *prev(hitbox2.end(),2) - hitbox2.back();
	Vector2f left_length2 = hitbox2.front() - hitbox2.back();
	Vector2f right_length2 = *next(hitbox2.begin()) - *prev(hitbox2.end(),2);
	auto area2 = top_length2*left_length2;
	auto area2_again = bottom_length2*right_length2;
	EXPECT_FLOAT_EQ(area1, area1_again);
	EXPECT_FLOAT_EQ(area2, area2_again);
	EXPECT_FLOAT_EQ(area1, area2);
}

TEST (Laser, moveFunctionMovesLaserInCorrectDirection)
{
	Laser test_laser1(Vector2f(1.f,1.f),Vector2f(0.f,1.f));
	
	test_laser1.move(10.f);
	
	auto change_in_position = test_laser1.position() - Vector2f(1.f,1.f);
	EXPECT_TRUE(Vector2f(0.f,1.f) == change_in_position.unitVector());
	
	Laser test_laser2(Vector2f(20.f,20.f),Vector2f(-1.f,0.f));
	
	test_laser2.move(13.f);
	
	change_in_position = test_laser2.position() - Vector2f(20.f,20.f);
	EXPECT_TRUE(Vector2f(-1.f,0.f) == change_in_position.unitVector());
}