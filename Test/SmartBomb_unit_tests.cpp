#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <iostream> // For testing purposes

#include "SmartBomb.h"
#include "Ship.h"
#include "Flyer.h"
#include "Laser.h"
#include "Missile.h"
#include "Powerup.h"
#include "HomingMissile.h"


#include "gtest/gtest.h"

TEST (SmartBomb, constructorSuccesfullyPlacesSmartBomb)
{
	SmartBomb testSmartBomb1(0.f);
	EXPECT_FLOAT_EQ(testSmartBomb1.position().x, 0.f);
	EXPECT_FLOAT_EQ(testSmartBomb1.position().y, 600.f);
	
	SmartBomb testSmartBomb2(100.f);
	EXPECT_FLOAT_EQ(testSmartBomb2.position().x, 100.f);
	EXPECT_FLOAT_EQ(testSmartBomb2.position().y, 600.f);
}

TEST (SmartBomb, SmartBombGetsDestryedWhenCollidingWithShip)
{
	SmartBomb testSmartBomb(0.f);
	shared_ptr<Ship> test_ship_ptr = make_shared<Ship>();
	
	testSmartBomb.collide(test_ship_ptr);
	EXPECT_TRUE(testSmartBomb.destroyed());
}

TEST (SmartBomb, SmartBombGetsDestryedWhenCollidingWithFlyer)
{
	SmartBomb testSmartBomb(0.f);
	shared_ptr<Flyer> test_flyer_ptr = make_shared<Flyer>();
	
	testSmartBomb.collide(test_flyer_ptr);
	EXPECT_TRUE(testSmartBomb.destroyed());
}

TEST (SmartBomb, SmartBombGetsDestryedWhenCollidingWithMissile)
{
	SmartBomb testSmartBomb(0.f);
	shared_ptr<Missile> test_missile_ptr = make_shared<Missile>(Vector2f(1.f,1.f),Vector2f(1.f,1.f));
	
	testSmartBomb.collide(test_missile_ptr);
	EXPECT_TRUE(testSmartBomb.destroyed());
}

TEST (SmartBomb, SmartBombGetsDestryedWhenCollidingWithHomingMissile)
{
	SmartBomb testSmartBomb(0.f);
	shared_ptr<HomingMissile> test_homing_missile_ptr = make_shared<HomingMissile>(Vector2f(1.f,1.f),make_shared<Flyer>());
	
	testSmartBomb.collide(test_homing_missile_ptr);
	EXPECT_TRUE(testSmartBomb.destroyed());
}

TEST (SmartBomb, SmartBombGetsDestryedWhenCollidingWithLaser)
{
	SmartBomb testSmartBomb(0.f);
	shared_ptr<Laser> test_laser_ptr = make_shared<Laser>(Vector2f(1.f,1.f), Vector2f(0.f,1.f));
	
	testSmartBomb.collide(test_laser_ptr);
	EXPECT_TRUE(testSmartBomb.destroyed());
}

TEST (SmartBomb, SmartBombGetsDestryedWhenCollidingWithPowerup)
{
	SmartBomb testSmartBomb(0.f);
	shared_ptr<Powerup> test_powerup_ptr = make_shared<Powerup>();
	
	testSmartBomb.collide(test_powerup_ptr);
	EXPECT_TRUE(testSmartBomb.destroyed());
}

TEST (SmartBomb, SmartBombGetsDestryedWhenCollidingWithSmartBomb)
{
	SmartBomb testSmartBomb(0.f);
	shared_ptr<SmartBomb> test_smartbomb_ptr = make_shared<SmartBomb>(0.f);
	
	testSmartBomb.collide(test_smartbomb_ptr);
	EXPECT_TRUE(testSmartBomb.destroyed());
}

TEST (SmartBomb, SmartBombHitboxIsTheCorrectShape)
{
	//testing for a box
	SmartBomb test_smartbomb(0.f);
	list<Vector2f> hitbox = test_smartbomb.hitboxPoints();
	//test top section = bottom section
	Vector2f top_length = *next(hitbox.begin()) - hitbox.front();
	Vector2f bottom_length = *prev(hitbox.end(),2) - hitbox.back();
	EXPECT_TRUE(top_length == bottom_length);
	//test left section == right section
	Vector2f left_length = hitbox.back() - hitbox.front();
	Vector2f right_length = *prev(hitbox.end(),2) - *next(hitbox.begin());
	EXPECT_TRUE(left_length == right_length);
}

TEST (SmartBomb, SmartBombHitboxIsAlwaysTheSameAreaRegardlessOfPositionOnMap)
{
	//test dependent on random position generation for the flyers
	SmartBomb test_smartbomb1(0.f);
	list<Vector2f> hitbox1 = test_smartbomb1.hitboxPoints();
	Vector2f top_length = *next(hitbox1.begin()) - hitbox1.front();
	Vector2f bottom_length = *prev(hitbox1.end(),2) - hitbox1.back();
	Vector2f left_length = hitbox1.front() - hitbox1.back();
	Vector2f right_length = *next(hitbox1.begin()) - *prev(hitbox1.end(),2);
	auto area1 = top_length * left_length;
	auto area1_again = bottom_length*right_length;
	SmartBomb test_smartbomb2(100.f);
	list<Vector2f> hitbox2 = test_smartbomb2.hitboxPoints();
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

TEST (SmartBomb, moveDoesNotChangeSmartBombPossition)
{
	SmartBomb testSmartBomb1(0.f);
	EXPECT_FLOAT_EQ(testSmartBomb1.position().x, 0.f);
	EXPECT_FLOAT_EQ(testSmartBomb1.position().y, 600.f);
	testSmartBomb1.move(100.f);
	EXPECT_FLOAT_EQ(testSmartBomb1.position().x, 0.f);
	EXPECT_FLOAT_EQ(testSmartBomb1.position().y, 600.f);
}