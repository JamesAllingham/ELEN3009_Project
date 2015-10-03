#include "Ship.h"
#include "Powerup.h"
#include "ShootingMovingEntity.h"
#include "Events.h"
#include "Laser.h"
#include "HomingMissile.h"
#include "EntityHolder.h"
#include "EntityID.h"
#include "Vector2f.h"

#include "gtest/gtest.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <list>
using std::prev;

TEST (Ship, ShipInitialisesAllRelevantStatusInformationCorrectly)
{
	Ship TestShip;
	TestShip.setMapLimits(Vector2f(4800,600));
	list<int> test_ship_status = TestShip.status();
	EXPECT_EQ(3,test_ship_status.front()); //3 lives
	EXPECT_EQ(2, *prev(test_ship_status.end(),2)); //2 smart bombs
	EXPECT_EQ(0,test_ship_status.back()); //0 homing missiles
}

TEST (Ship, ShipInitialisesItsPositionToTheCentreOfTheMap)
{
	Ship TestShip;
	TestShip.setMapLimits(Vector2f(4800,600));
	EXPECT_EQ(Vector2f(Entity::mapLimits().x/2,Entity::mapLimits().y/2), TestShip.position());
}

TEST (Ship, ShipCanMoveTheDesiredDistance)
{
	Ship TestShip;
	TestShip.setMapLimits(Vector2f(4800,600));
	TestShip.controlMovement(Events::D_Pressed); // move right
	TestShip.move( .1f );
	EXPECT_EQ(Vector2f(2400 + 30, 300), TestShip.position());
	TestShip.controlMovement(Events::D_Released);
	TestShip.controlMovement(Events::A_Pressed);	// move left
	TestShip.move( .1f );
	EXPECT_EQ(Vector2f(2400 + 30 - 30, 300), TestShip.position());
	TestShip.controlMovement(Events::A_Released);
	TestShip.controlMovement(Events::W_Pressed);	// move up
	TestShip.move( .1f );
	EXPECT_EQ(Vector2f(2400 + 30 - 30, 300 - 30), TestShip.position());
	TestShip.controlMovement(Events::W_Released);
	TestShip.controlMovement(Events::S_Pressed);	// move down
	TestShip.move( .1f );
	EXPECT_EQ(Vector2f(2400 + 30 - 30, 300 - 30 + 30), TestShip.position());
}

TEST (Ship, ShipCanSwitchDirectionItsFacing)
{
	Ship TestShip;
	TestShip.setMapLimits(Vector2f(4800,600));
	TestShip.controlMovement(Events::D_Pressed);
	TestShip.move( 0.03f );
	EXPECT_TRUE(TestShip.facingRight());
	TestShip.controlMovement(Events::D_Released);
	TestShip.controlMovement(Events::A_Pressed);
	TestShip.move( 0.03f );
	EXPECT_FALSE(TestShip.facingRight());
}

TEST (Ship, ShipCanShootALaser)
{
	Ship TestShip;
	TestShip.setMapLimits(Vector2f(4800,600));
	TestShip.controlShooting(Events::Space_Pressed);
	shared_ptr<Entity> shooting_ptr = TestShip.shoot(0.03f );
	EXPECT_FALSE(shooting_ptr == nullptr);
}

TEST (Ship, ShipCanAddMoreHomingMissilesWhenPowerUpIsPickedUp)
{
	Ship TestShip;
	TestShip.setMapLimits(Vector2f(4800,600));
	shared_ptr<Entity> powerup_ptr = make_shared<Powerup>();
	TestShip.collide(powerup_ptr); //adds 3 homing missiles
	list<int> test_ship_status = TestShip.status();
	EXPECT_EQ(3,test_ship_status.back());
}

TEST (Ship, ShipCanShootAHomingMissileAndItShowsInTheStatus)
{
	Ship TestShip;
	TestShip.setMapLimits(Vector2f(4800,600));
	shared_ptr<Entity> powerup_ptr = make_shared<Powerup>();
	TestShip.collide(powerup_ptr); //adds 3 homing missiles
	TestShip.controlShooting(Events::E_Pressed);
	TestShip.shoot(0.03f );
	list<int> test_ship_status = TestShip.status();
	EXPECT_EQ(2,test_ship_status.back()); //1 homing missile lost to shooting
}

TEST (Ship, ShipCannotShootAHomingMissileWhenItHasNone)
{
	Ship TestShip;
	TestShip.setMapLimits(Vector2f(4800,600));
	TestShip.controlShooting(Events::E_Pressed);
	TestShip.shoot(0.03f );
	list<int> test_ship_status = TestShip.status();
	EXPECT_EQ(0,test_ship_status.back()); //doesn't become -1
}

TEST (Ship, ShipCanShootASmartBombAndItShowsInTheStatus)
{
	Ship TestShip;
	TestShip.setMapLimits(Vector2f(4800,600));
	TestShip.controlShooting(Events::Q_Pressed);
	TestShip.shoot(0.03f );
	list<int> test_ship_status = TestShip.status();
	EXPECT_EQ(1, *prev(test_ship_status.end(),2)); //lost 1 smart bomb to shooting
}

TEST (Ship, ShipCannotShootASmartBombWhenItHasNone)
{
	Ship TestShip;
	TestShip.setMapLimits(Vector2f(4800,600));
	TestShip.controlShooting(Events::Q_Pressed);
	TestShip.shoot(0.03f );
	list<int> test_ship_status = TestShip.status();
	EXPECT_EQ(1, *prev(test_ship_status.end(),2)); //lost 1 smart bomb to shooting
	TestShip.controlShooting(Events::Q_Pressed);
	TestShip.shoot(0.03f );
	test_ship_status = TestShip.status();
	EXPECT_EQ(0, *prev(test_ship_status.end(),2)); //lost 1 smart bomb to shooting
	TestShip.controlShooting(Events::Q_Pressed);
	TestShip.shoot(0.03f );
	test_ship_status = TestShip.status();
	EXPECT_EQ(0, *prev(test_ship_status.end(),2)); //doesn't equal -1
}

TEST (Ship, ShipLosesALifeWhenCollidingWithAFlyer)
{
	Ship TestShip;
	TestShip.setMapLimits(Vector2f(4800,600));
	shared_ptr<Entity> flyer_ptr = make_shared<Flyer>();
	TestShip.collide(flyer_ptr);
	list<int> test_ship_status = TestShip.status();
	EXPECT_EQ(2,test_ship_status.front()); //lost a life
}

TEST (Ship, ShipLosesALifeWhenCollidingWithALaser)
{
	Ship TestShip;
	TestShip.setMapLimits(Vector2f(4800,600));
	shared_ptr<Entity> missile_ptr = make_shared<Missile>(Vector2f(0,0),Vector2f(0,0));
	TestShip.collide(missile_ptr);
	list<int> test_ship_status = TestShip.status();
	EXPECT_EQ(2,test_ship_status.front()); //lost a life
}

TEST (Ship, ShipGetsDestroyedWhenAllLivesAreLost)
{
	Ship TestShip;
	TestShip.setMapLimits(Vector2f(4800,600));
	shared_ptr<Entity> flyer_ptr = make_shared<Flyer>();
	list<int> test_ship_status = TestShip.status();
	while (test_ship_status.front() != 0)
	{
		EXPECT_FALSE(TestShip.destroyed());
		TestShip.collide(flyer_ptr);
		test_ship_status = TestShip.status();
	}
	EXPECT_TRUE(TestShip.destroyed());
}

TEST (Ship, ShipHitboxIsTheCorrectShape)
{
	//testing for a box
	Ship TestShip;
	list<Vector2f> hitbox = TestShip.hitboxPoints();
	//test top section = bottom section
	Vector2f top_length = *next(hitbox.begin()) - hitbox.front();
	Vector2f bottom_length = *prev(hitbox.end(),2) - hitbox.back();
	EXPECT_TRUE(top_length == bottom_length);
	//test left section == right section
	Vector2f left_length = hitbox.back() - hitbox.front();
	Vector2f right_length = *prev(hitbox.end(),2) - *next(hitbox.begin());
	EXPECT_TRUE(left_length == right_length);
}

TEST (Ship, ShipHitboxIsAlwaysTheSameAreaRegardlessOfPositionOnMap)
{
	Ship TestShip1;
	list<Vector2f> hitbox1 = TestShip1.hitboxPoints();
	Vector2f top_length = *next(hitbox1.begin()) - hitbox1.front();
	Vector2f bottom_length = *prev(hitbox1.end(),2) - hitbox1.back();
	Vector2f left_length = hitbox1.front() - hitbox1.back();
	Vector2f right_length = *next(hitbox1.begin()) - *prev(hitbox1.end(),2);
	float area1 = top_length * left_length;
	float area1_again = bottom_length*right_length;
	Ship TestShip2;
	TestShip2.controlMovement(Events::D_Pressed);
	TestShip2.move( 0.03f );
	list<Vector2f> hitbox2 = TestShip2.hitboxPoints();
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

TEST (Ship, ShipCanDetectNearestTarget)
{
	Ship TestShip;
	EntityHolder entity_holder;
	shared_ptr<Entity> flyer_ptr1 = make_shared<Flyer>();
	entity_holder.addEntity(flyer_ptr1);
	shared_ptr<Entity> flyer_ptr2 = make_shared<Flyer>();
	entity_holder.addEntity(flyer_ptr2);
	TestShip.setNearestTarget(entity_holder);
	//check which is the nearest target
	float flyer1_x_distance_to_ship = flyer_ptr1->position().x - TestShip.position().x;
	float flyer1_y_distance_to_ship = flyer_ptr1->position().y - TestShip.position().y;
	float flyer1_distance_to_ship = sqrtf(flyer1_x_distance_to_ship*flyer1_x_distance_to_ship + flyer1_y_distance_to_ship * flyer1_y_distance_to_ship);
	float flyer2_x_distance_to_ship = flyer_ptr2->position().x - TestShip.position().x;
	float flyer2_y_distance_to_ship = flyer_ptr2->position().y - TestShip.position().y;
	float flyer2_distance_to_ship = sqrtf(flyer2_x_distance_to_ship*flyer2_x_distance_to_ship + flyer2_y_distance_to_ship * flyer2_y_distance_to_ship);
	
	if (flyer1_distance_to_ship < flyer2_distance_to_ship) EXPECT_TRUE(TestShip.nearestTarget() == flyer_ptr1);
	else if (flyer2_distance_to_ship < flyer1_distance_to_ship) EXPECT_TRUE(TestShip.nearestTarget() == flyer_ptr2);
}