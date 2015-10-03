#include <ctime>
#include <cmath>
#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <iostream> // For testing purposes

#include "Flyer.h"
#include "Ship.h"
#include "ShootingMovingEntity.h"
#include "Missile.h"
#include "EntityId.h"
#include "Vector2f.h"
//#include "HomingMissile.h"
//#include "SmartBomb.h"
//#include "Laser.h"

#include "gtest/gtest.h"

TEST (Flyer, FlyerGetsDestroyedWhenCollidingWithShip)
{
	Flyer test_flyer;
	shared_ptr<Entity> ship_ptr = make_shared<Ship>();
	test_flyer.collide(ship_ptr);
	EXPECT_TRUE(test_flyer.destroyed());
}

TEST (Flyer, FlyerGetsDestroyedWhenCollidingWithLaser)
{
	Flyer test_flyer;
	shared_ptr<Entity> Laser_ptr = make_shared<Laser>(Vector2f(0,0), Vector2f(0,0));
	test_flyer.collide(Laser_ptr);
	EXPECT_TRUE(test_flyer.destroyed());
}

TEST (Flyer, FlyerGetsDestroyedWhenCollidingWithHomingMissile)
{
	Flyer test_flyer;
	shared_ptr<Entity> nearest_target = make_shared<Flyer>();
	shared_ptr<Entity> Homing_Missile_ptr = make_shared<HomingMissile>(Vector2f(0,0), nearest_target);
	test_flyer.collide(Homing_Missile_ptr);
	EXPECT_TRUE(test_flyer.destroyed());
}

TEST (Flyer, FlyerGetsDestroyedWhenCollidingWithSmartBomb)
{
	Flyer test_flyer;
	shared_ptr<Entity> Smart_Bomb_ptr = make_shared<SmartBomb>(200.f);
	test_flyer.collide(Smart_Bomb_ptr);
	EXPECT_TRUE(test_flyer.destroyed());
}

TEST (Flyer, NumberOfFlyersIncreasesWithNewlyCreatedFlyers)
{
	Flyer flyer1;
	Flyer flyer2;
	Flyer flyer3;
	
	EXPECT_EQ(3, Flyer::numberOfFlyers());
}

TEST (Flyer, NumberOfFlyersDecreasesWithDestroyedFlyer)
{
	
	Flyer flyer1;
	Flyer flyer2;
	{
	Flyer flyer3;
	
	EXPECT_EQ(3, Flyer::numberOfFlyers());
	}
	
	EXPECT_EQ(2, Flyer::numberOfFlyers());
}

TEST (Flyer, FlyerCanShootAMissileIfTimeBetweenShotsHasBeenExceeded)
{
	Flyer test_flyer;
	shared_ptr<Entity> Laser_ptr = make_shared<Laser>(test_flyer.position(), Vector2f(0,0)); //setting a target to be within range
	test_flyer.setTarget(Laser_ptr);
	shared_ptr<Entity> shooting_ptr = test_flyer.shoot(30.f );
	EXPECT_FALSE(shooting_ptr == nullptr);
	
}

TEST (Flyer, FlyerCannotShootAMissileIfTimeBetweenShotsHasNotBeenExceeded)
{
	Flyer test_flyer;
	shared_ptr<Entity> Laser_ptr = make_shared<Laser>(test_flyer.position(), Vector2f(0,0)); //setting a target to be within range
	test_flyer.setTarget(Laser_ptr);
	shared_ptr<Entity> shooting_ptr = test_flyer.shoot(0.f );
	EXPECT_TRUE(shooting_ptr == nullptr);
}

TEST (Flyer, FlyerHitboxIsTheCorrectShape)
{
	//testing for a box
	Flyer test_flyer;
	list<Vector2f> hitbox = test_flyer.hitboxPoints();
	//test top section = bottom section
	Vector2f top_length = *next(hitbox.begin()) - hitbox.front();
	Vector2f bottom_length = *prev(hitbox.end(),2) - hitbox.back();
	EXPECT_TRUE(top_length == bottom_length);
	//test left section == right section
	Vector2f left_length = hitbox.back() - hitbox.front();
	Vector2f right_length = *prev(hitbox.end(),2) - *next(hitbox.begin());
	EXPECT_TRUE(left_length == right_length);
}

TEST (Flyer, FlyerHitboxIsAlwaysTheSameAreaRegardlessOfPositionOnMap)
{
	//test dependent on random position generation for the flyers
	Flyer test_flyer1;
	list<Vector2f> hitbox1 = test_flyer1.hitboxPoints();
	Vector2f top_length = *next(hitbox1.begin()) - hitbox1.front();
	Vector2f bottom_length = *prev(hitbox1.end(),2) - hitbox1.back();
	Vector2f left_length = hitbox1.front() - hitbox1.back();
	Vector2f right_length = *next(hitbox1.begin()) - *prev(hitbox1.end(),2);
	auto area1 = top_length * left_length;
	auto area1_again = bottom_length*right_length;
	Flyer test_flyer2;
	list<Vector2f> hitbox2 = test_flyer2.hitboxPoints();
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