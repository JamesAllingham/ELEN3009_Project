#include "gtest/gtest.h"

#include "HomingMissile.h"
#include "MovingEntity.h"
#include "Flyer.h"

#include "Vector2f.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;

TEST (HomingMissile, HomingMissileConstructsPositionCorrectly)
{
	shared_ptr<Entity> target_ptr = make_shared<Flyer>();
	HomingMissile homing_missile(Vector2f(50.f,100.f), target_ptr);
	EXPECT_TRUE(Vector2f(50.f,100.f) == homing_missile.position());
	
}

TEST (HomingMissile, HomingMissileGetsDestroyedWhenCollidingWithAFlyer)
{
	shared_ptr<Entity> target_ptr = make_shared<Flyer>();
	HomingMissile homing_missile(target_ptr->position(), target_ptr);
	homing_missile.collide(target_ptr);
	EXPECT_TRUE(homing_missile.destroyed());
}

TEST (HomingMissile, HomingMissileHitboxIsTheCorrectShape)
{
	//testing for a box
	shared_ptr<Entity> target_ptr = make_shared<Flyer>();
	HomingMissile homing_missile(Vector2f(50.f,100.f), target_ptr);
	list<Vector2f> hitbox = homing_missile.hitboxPoints();
	//test top section = bottom section
	Vector2f top_length = *next(hitbox.begin()) - hitbox.front();
	Vector2f bottom_length = *prev(hitbox.end(),2) - hitbox.back();
	EXPECT_TRUE(top_length == bottom_length);
	//test left section == right section
	Vector2f left_length = hitbox.back() - hitbox.front();
	Vector2f right_length = *prev(hitbox.end(),2) - *next(hitbox.begin());
	EXPECT_TRUE(left_length == right_length);
}

TEST (HomingMissile, HomingMissileHitboxIsAlwaysTheSameAreaRegardlessOfPositionOnMap)
{
	shared_ptr<Entity> target_ptr = make_shared<Flyer>();
	HomingMissile homing_missile1(Vector2f(50.f,100.f), target_ptr);
	list<Vector2f> hitbox1 = homing_missile1.hitboxPoints();
	Vector2f top_length = *next(hitbox1.begin()) - hitbox1.front();
	Vector2f bottom_length = *prev(hitbox1.end(),2) - hitbox1.back();
	Vector2f left_length = hitbox1.front() - hitbox1.back();
	Vector2f right_length = *next(hitbox1.begin()) - *prev(hitbox1.end(),2);
	float area1 = top_length * left_length;
	float area1_again = bottom_length*right_length;
	HomingMissile homing_missile2(Vector2f(500.f,260.f), target_ptr);
	list<Vector2f> hitbox2 = homing_missile2.hitboxPoints();
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