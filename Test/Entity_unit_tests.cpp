#include "gtest/gtest.h"

#include "Ship.h"
#include "Powerup.h"
#include "ShootingMovingEntity.h"
#include "Events.h"
#include "Laser.h"
#include "HomingMissile.h"
#include "EntityHolder.h"
#include "EntityID.h"
#include "Vector2f.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <list>
using std::prev;

TEST (Entity, CharacterFunctionCorrectlyReturnsId)
{	
	Ship test_ship;
	EXPECT_EQ(EntityID::Ship, test_ship.character().entityID());
}

TEST (Entity, IdFunctionCorrectlyReturnsId)
{
	Ship test_ship;
	EXPECT_EQ(EntityID::Ship, test_ship.id());
}

TEST (Entity, CharacterFunctionCorrectlyReturnsPosition)
{
	Entity::setMapLimits(Vector2f(4800.f,600.f));
	Laser test_laser(Vector2f(2400.f,300.f), Vector2f(0.f,0.f));
	EXPECT_EQ(Vector2f(2400.f,300.f), test_laser.character().position());
}

TEST (Entity, PositionFunctionCorrectlyReturnsPosition)
{
	Entity::setMapLimits(Vector2f(4800.f,600.f));
	Laser test_laser(Vector2f(2400.f,300.f), Vector2f(0.f,0.f));
	EXPECT_EQ(Vector2f(2400.f,300.f), test_laser.position());
}

TEST (Entity, MapLimitsCanBeSetAndCalled)
{
	Ship test_ship;
	Entity::setMapLimits(Vector2f(100,25));
	EXPECT_EQ(Vector2f(100,25), test_ship.mapLimits());
}

TEST (Entity, DestroyedMemberDataIsCorrectlyInitialisedToBeFalse)
{
	Ship test_ship;
	EXPECT_FALSE(test_ship.destroyed());
}

TEST (Entity, DestroyFunctionDestroysTheEntity)
{
	Ship test_ship;
	test_ship.destroy();
	EXPECT_TRUE(test_ship.destroyed());
}