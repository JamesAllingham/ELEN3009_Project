#include "gtest/gtest.h"

#include "Missile.h"
#include "MovingEntity.h"
#include "Vector2f.h"
#include "Ship.h"
#include "Laser.h"
#include "SmartBomb.h"
#include <memory>
using std::shared_ptr;
using std::make_shared;

TEST (Missile, MissilePositionIsSetCorrectly)
{
	Missile missile(Vector2f(150.f,50.f), Vector2f(0,0));
	EXPECT_TRUE(Vector2f(150.f,50.f) == missile.position());	
}

TEST (Missile, MissileGetsDestroyedWhenCollidingWithAShip)
{
	Missile missile(Vector2f(150.f,50.f), Vector2f(0,0));
	shared_ptr<Entity> ship_ptr = make_shared<Ship>();
	missile.collide(ship_ptr);
	EXPECT_TRUE(missile.destroyed());
}

TEST (Missile, MissileGetsDestroyedWhenCollidingWithALaser)
{
	Missile missile(Vector2f(150.f,50.f), Vector2f(0,0));
	shared_ptr<Entity> laser_ptr = make_shared<Laser>(Vector2f(0,0),Vector2f(0,0));
	missile.collide(laser_ptr);
	EXPECT_TRUE(missile.destroyed());
}

TEST (Missile, MissileGetsDestroyedWhenCollidingWithASmartBomb)
{
	Missile missile(Vector2f(150.f,50.f), Vector2f(0,0));
	shared_ptr<Entity> smart_bomb_ptr = make_shared<SmartBomb>(25.f);
	missile.collide(smart_bomb_ptr);
	EXPECT_TRUE(missile.destroyed());
}

TEST (Missile, MissileGetsDestroyedWhenMovingOffTheMap)
{
	//Test top
	Missile missile1(Vector2f(150.f,-1.f), Vector2f(0,0));
	missile1.move(0.1f);
	EXPECT_TRUE(missile1.destroyed());
	//Test bottom
	Missile missile2(Vector2f(150.f,601.f), Vector2f(0,0));
	missile2.move(0.1f);
	EXPECT_TRUE(missile2.destroyed());
	//Test left
	Missile missile3(Vector2f(-1.f,50.f), Vector2f(0,0));
	missile3.move(0.1f);
	EXPECT_TRUE(missile3.destroyed());
	//Test right 
	Missile missile4(Vector2f(4900.f,50.f), Vector2f(0,0));
	missile4.move(0.1f);
	EXPECT_TRUE(missile4.destroyed());
}

TEST (Missile, MissileHitboxIsTheCorrectShape)
{
	//testing for a box
	Missile missile(Vector2f(150.f,50.f), Vector2f(0,0));
	list<Vector2f> hitbox = missile.hitboxPoints();
	//test top section = bottom section
	Vector2f top_length = *next(hitbox.begin()) - hitbox.front();
	Vector2f bottom_length = *prev(hitbox.end(),2) - hitbox.back();
	EXPECT_TRUE(top_length == bottom_length);
	//test left section == right section
	Vector2f left_length = hitbox.back() - hitbox.front();
	Vector2f right_length = *prev(hitbox.end(),2) - *next(hitbox.begin());
	EXPECT_TRUE(left_length == right_length);
}

TEST (Missile, MissileHitboxIsAlwaysTheSameAreaRegardlessOfPositionOnMap)
{
	Missile missile1(Vector2f(150.f,50.f), Vector2f(0,0));
	list<Vector2f> hitbox1 = missile1.hitboxPoints();
	Vector2f top_length = *next(hitbox1.begin()) - hitbox1.front();
	Vector2f bottom_length = *prev(hitbox1.end(),2) - hitbox1.back();
	Vector2f left_length = hitbox1.front() - hitbox1.back();
	Vector2f right_length = *next(hitbox1.begin()) - *prev(hitbox1.end(),2);
	float area1 = top_length * left_length;
	float area1_again = bottom_length*right_length;
	Missile missile2(Vector2f(600.f,46.f), Vector2f(0,0));
	list<Vector2f> hitbox2 = missile2.hitboxPoints();
	Vector2f top_length2 = *next(hitbox2.begin()) - hitbox2.front();
	Vector2f bottom_length2 = *prev(hitbox2.end(),2) - hitbox2.back();
	Vector2f left_length2 = hitbox2.front() - hitbox2.back();
	Vector2f right_length2 = *next(hitbox2.begin()) - *prev(hitbox2.end(),2);
	float area2 = top_length2*left_length2;
	float area2_again = bottom_length2*right_length2;
	EXPECT_FLOAT_EQ(area1, area1_again);
	EXPECT_FLOAT_EQ(area2, area2_again);
	EXPECT_FLOAT_EQ(area1, area2);
}