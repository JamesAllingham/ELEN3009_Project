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

TEST (SmartBomb, smartBombGetsDestryedWhenCollidingWithShip)
{
	SmartBomb testSmartBomb(0.f);
	shared_ptr<Ship> test_ship_ptr = make_shared<Ship>();
	
	testSmartBomb.collide(test_ship_ptr);
	EXPECT_TRUE(testSmartBomb.destroyed());
}

TEST (SmartBomb, smartBombGetsDestryedWhenCollidingWithFlyer)
{
	SmartBomb testSmartBomb(0.f);
	shared_ptr<Flyer> test_flyer_ptr = make_shared<Flyer>();
	
	testSmartBomb.collide(test_flyer_ptr);
	EXPECT_TRUE(testSmartBomb.destroyed());
}

TEST (SmartBomb, smartBombGetsDestryedWhenCollidingWithMissile)
{
	SmartBomb testSmartBomb(0.f);
	shared_ptr<Missile> test_missile_ptr = make_shared<Missile>(Vector2f(1.f,1.f),Vector2f(1.f,1.f));
	
	testSmartBomb.collide(test_missile_ptr);
	EXPECT_TRUE(testSmartBomb.destroyed());
}

TEST (SmartBomb, smartBombGetsDestryedWhenCollidingWithHomingMissile)
{
	SmartBomb testSmartBomb(0.f);
	shared_ptr<HomingMissile> test_homing_missile_ptr = make_shared<HomingMissile>(Vector2f(1.f,1.f),make_shared<Flyer>());
	
	testSmartBomb.collide(test_homing_missile_ptr);
	EXPECT_TRUE(testSmartBomb.destroyed());
}

TEST (SmartBomb, smartBombGetsDestryedWhenCollidingWithLaser)
{
	SmartBomb testSmartBomb(0.f);
	shared_ptr<Laser> test_laser_ptr = make_shared<Laser>(Vector2f(1.f,1.f), Vector2f(0.f,1.f));
	
	testSmartBomb.collide(test_laser_ptr);
	EXPECT_TRUE(testSmartBomb.destroyed());
}

TEST (SmartBomb, smartBombGetsDestryedWhenCollidingWithPowerup)
{
	SmartBomb testSmartBomb(0.f);
	shared_ptr<Powerup> test_powerup_ptr = make_shared<Powerup>();
	
	testSmartBomb.collide(test_powerup_ptr);
	EXPECT_TRUE(testSmartBomb.destroyed());
}

TEST (SmartBomb, smartBombGetsDestryedWhenCollidingWithSmartBomb)
{
	SmartBomb testSmartBomb(0.f);
	shared_ptr<SmartBomb> test_smartbomb_ptr = make_shared<SmartBomb>(0.f);
	
	testSmartBomb.collide(test_smartbomb_ptr);
	EXPECT_TRUE(testSmartBomb.destroyed());
}