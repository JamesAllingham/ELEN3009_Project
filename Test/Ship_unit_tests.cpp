#include "Ship.h"
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

TEST (Ship, ShipCanSwitchDirectionItsFacing)
{
	Ship TestShip;
	TestShip.controlMovement(Events::D_Pressed);
	TestShip.move( 0.03f );
	EXPECT_TRUE(TestShip.facingRight());
	TestShip.controlMovement(Events::D_Released);
	TestShip.controlMovement(Events::A_Pressed);
	TestShip.move( 0.03f );
	EXPECT_FALSE(TestShip.facingRight());
}

TEST (Ship, ShipInitialisesAllRelevantStatusInformationCorrectly)
{
	Ship TestShip;
	list<int> test_ship_status = TestShip.status();
	EXPECT_EQ(3,test_ship_status.front()); //3 lives
	EXPECT_EQ(2, *prev(test_ship_status.end(),2)); //2 smart bombs
	EXPECT_EQ(0,test_ship_status.back()); //0 homing missiles
}

TEST (Ship, ShipCanAddMoreHomingMissilesWhenPowerUpIsPickedUp)
{
	Ship TestShip;
	TestShip.addHomingMissiles(); //adds 3 homing missiles
	list<int> test_ship_status = TestShip.status();
	EXPECT_EQ(3,test_ship_status.back());
}

TEST(Ship, ShipCanShootAHomingMissileAndItShowsInTheStatus)
{
	Ship TestShip;
	TestShip.addHomingMissiles();
	TestShip.controlShooting(Events::E_Pressed);
	TestShip.shoot(0.03f );
	list<int> test_ship_status = TestShip.status();
	EXPECT_EQ(2,test_ship_status.back()); //1 homing missile lost to shooting
}

TEST(Ship, ShipCannotShootAHomingMissileWhenItHasNone)
{
	Ship TestShip;
	//TestShip.addHomingMissiles();
	TestShip.controlShooting(Events::E_Pressed);
	TestShip.shoot(0.03f );
	list<int> test_ship_status = TestShip.status();
	EXPECT_EQ(0,test_ship_status.back()); //doesn't become -1
}