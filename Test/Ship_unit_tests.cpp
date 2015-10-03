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
	Ship ship;
	ship.setMapLimits(Vector2f(4800,600));
	list<int> test_ship_status = ship.status();
	EXPECT_EQ(3,test_ship_status.front()); //3 lives
	EXPECT_EQ(2, *prev(test_ship_status.end(),2)); //2 smart bombs
	EXPECT_EQ(0,test_ship_status.back()); //0 homing missiles
}

TEST (Ship, ShipInitialisesItsPositionToTheCentreOfTheMap)
{
	Ship ship;
	ship.setMapLimits(Vector2f(4800,600));
	EXPECT_EQ(Vector2f(Entity::mapLimits().x/2,Entity::mapLimits().y/2), ship.position());
}

TEST (Ship, ShipCanMoveTheDesiredDistance)
{
	Ship ship;
	ship.setMapLimits(Vector2f(4800,600));
	ship.controlMovement(Events::D_Pressed); // move right
	ship.move( .1f );
	EXPECT_EQ(Vector2f(2400 + 30, 300), ship.position());
	ship.controlMovement(Events::D_Released);
	ship.controlMovement(Events::A_Pressed);	// move left
	ship.move( .1f );
	EXPECT_EQ(Vector2f(2400 + 30 - 30, 300), ship.position());
	ship.controlMovement(Events::A_Released);
	ship.controlMovement(Events::W_Pressed);	// move up
	ship.move( .1f );
	EXPECT_EQ(Vector2f(2400 + 30 - 30, 300 - 30), ship.position());
	ship.controlMovement(Events::W_Released);
	ship.controlMovement(Events::S_Pressed);	// move down
	ship.move( .1f );
	EXPECT_EQ(Vector2f(2400 + 30 - 30, 300 - 30 + 30), ship.position());
}

TEST (Ship, ShipCanSwitchDirectionItsFacing)
{
	Ship ship;
	ship.setMapLimits(Vector2f(4800,600));
	ship.controlMovement(Events::D_Pressed);
	ship.move( 0.03f );
	EXPECT_TRUE(ship.facingRight());
	ship.controlMovement(Events::D_Released);
	ship.controlMovement(Events::A_Pressed);
	ship.move( 0.03f );
	EXPECT_FALSE(ship.facingRight());
}

TEST (Ship, ShipCanShootALaser)
{
	Ship ship;
	ship.setMapLimits(Vector2f(4800,600));
	ship.controlShooting(Events::Space_Pressed);
	shared_ptr<Entity> shooting_ptr = ship.shoot(0.03f );
	EXPECT_FALSE(shooting_ptr == nullptr);
}

TEST (Ship, ShipCanAddMoreHomingMissilesWhenPowerUpIsPickedUp)
{
	Ship ship;
	ship.setMapLimits(Vector2f(4800,600));
	shared_ptr<Entity> powerup_ptr = make_shared<Powerup>();
	ship.collide(powerup_ptr); //adds 3 homing missiles
	list<int> test_ship_status = ship.status();
	EXPECT_EQ(3,test_ship_status.back());
}

TEST (Ship, ShipCanShootAHomingMissileAndItShowsInTheStatus)
{
	Ship ship;
	ship.setMapLimits(Vector2f(4800,600));
	shared_ptr<Entity> powerup_ptr = make_shared<Powerup>();
	ship.collide(powerup_ptr); //adds 3 homing missiles
	ship.controlShooting(Events::E_Pressed);
	ship.shoot(0.03f );
	list<int> test_ship_status = ship.status();
	EXPECT_EQ(2,test_ship_status.back()); //1 homing missile lost to shooting
}

TEST (Ship, ShipCannotShootAHomingMissileWhenItHasNone)
{
	Ship ship;
	ship.setMapLimits(Vector2f(4800,600));
	ship.controlShooting(Events::E_Pressed);
	ship.shoot(0.03f );
	list<int> test_ship_status = ship.status();
	EXPECT_EQ(0,test_ship_status.back()); //doesn't become -1
}

TEST (Ship, ShipCanShootASmartBombAndItShowsInTheStatus)
{
	Ship ship;
	ship.setMapLimits(Vector2f(4800,600));
	ship.controlShooting(Events::Q_Pressed);
	ship.shoot(0.03f );
	list<int> test_ship_status = ship.status();
	EXPECT_EQ(1, *prev(test_ship_status.end(),2)); //lost 1 smart bomb to shooting
}

TEST (Ship, ShipCannotShootASmartBombWhenItHasNone)
{
	Ship ship;
	ship.setMapLimits(Vector2f(4800,600));
	ship.controlShooting(Events::Q_Pressed);
	ship.shoot(0.03f );
	list<int> test_ship_status = ship.status();
	EXPECT_EQ(1, *prev(test_ship_status.end(),2)); //lost 1 smart bomb to shooting
	ship.controlShooting(Events::Q_Pressed);
	ship.shoot(0.03f );
	test_ship_status = ship.status();
	EXPECT_EQ(0, *prev(test_ship_status.end(),2)); //lost 1 smart bomb to shooting
	ship.controlShooting(Events::Q_Pressed);
	ship.shoot(0.03f );
	test_ship_status = ship.status();
	EXPECT_EQ(0, *prev(test_ship_status.end(),2)); //doesn't equal -1
}

TEST (Ship, ShipLosesALifeWhenCollidingWithAFlyer)
{
	Ship ship;
	ship.setMapLimits(Vector2f(4800,600));
	shared_ptr<Entity> flyer_ptr = make_shared<Flyer>();
	ship.collide(flyer_ptr);
	list<int> test_ship_status = ship.status();
	EXPECT_EQ(2,test_ship_status.front()); //lost a life
}

TEST (Ship, ShipLosesALifeWhenCollidingWithALaser)
{
	Ship ship;
	ship.setMapLimits(Vector2f(4800,600));
	shared_ptr<Entity> missile_ptr = make_shared<Missile>(Vector2f(0,0),Vector2f(0,0));
	ship.collide(missile_ptr);
	list<int> test_ship_status = ship.status();
	EXPECT_EQ(2,test_ship_status.front()); //lost a life
}

TEST (Ship, ShipGetsDestroyedWhenAllLivesAreLost)
{
	Ship ship;
	ship.setMapLimits(Vector2f(4800,600));
	shared_ptr<Entity> flyer_ptr = make_shared<Flyer>();
	list<int> test_ship_status = ship.status();
	while (test_ship_status.front() != 0)
	{
		EXPECT_FALSE(ship.destroyed());
		ship.collide(flyer_ptr);
		test_ship_status = ship.status();
	}
	EXPECT_TRUE(ship.destroyed());
}

TEST (Ship, ShipHitboxIsTheCorrectShape)
{
	//testing for a box
	Ship ship;
	list<Vector2f> hitbox = ship.hitboxPoints();
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
	Ship ship1;
	list<Vector2f> hitbox1 = ship1.hitboxPoints();
	Vector2f top_length = *next(hitbox1.begin()) - hitbox1.front();
	Vector2f bottom_length = *prev(hitbox1.end(),2) - hitbox1.back();
	Vector2f left_length = hitbox1.front() - hitbox1.back();
	Vector2f right_length = *next(hitbox1.begin()) - *prev(hitbox1.end(),2);
	float area1 = top_length * left_length;
	float area1_again = bottom_length*right_length;
	Ship ship2;
	ship2.controlMovement(Events::D_Pressed);
	ship2.move( 0.03f );
	list<Vector2f> hitbox2 = ship2.hitboxPoints();
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
	Ship ship;
	EntityHolder entity_holder;
	shared_ptr<Entity> flyer_ptr1 = make_shared<Flyer>();
	entity_holder.addEntity(flyer_ptr1);
	shared_ptr<Entity> flyer_ptr2 = make_shared<Flyer>();
	entity_holder.addEntity(flyer_ptr2);
	ship.setNearestTarget(entity_holder);
	//check which is the nearest target
	float flyer1_x_distance_to_ship = flyer_ptr1->position().x - ship.position().x;
	float flyer1_y_distance_to_ship = flyer_ptr1->position().y - ship.position().y;
	float flyer1_distance_to_ship = sqrtf(flyer1_x_distance_to_ship*flyer1_x_distance_to_ship + flyer1_y_distance_to_ship * flyer1_y_distance_to_ship);
	float flyer2_x_distance_to_ship = flyer_ptr2->position().x - ship.position().x;
	float flyer2_y_distance_to_ship = flyer_ptr2->position().y - ship.position().y;
	float flyer2_distance_to_ship = sqrtf(flyer2_x_distance_to_ship*flyer2_x_distance_to_ship + flyer2_y_distance_to_ship * flyer2_y_distance_to_ship);
	
	if (flyer1_distance_to_ship < flyer2_distance_to_ship) EXPECT_TRUE(ship.nearestTarget() == flyer_ptr1);
	else if (flyer2_distance_to_ship < flyer1_distance_to_ship) EXPECT_TRUE(ship.nearestTarget() == flyer_ptr2);
}