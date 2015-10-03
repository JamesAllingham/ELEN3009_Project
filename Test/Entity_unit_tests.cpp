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
	Ship TestShip;
	EXPECT_EQ(EntityID::Ship, TestShip.character().entityID());
}

TEST (Entity, IdFunctionCorrectlyReturnsId)
{
	Ship TestShip;
	EXPECT_EQ(EntityID::Ship, TestShip.id());
}

TEST (Entity, CharacterFunctionCorrectlyReturnsPosition)
{
	Ship TestShip;
	EXPECT_EQ(Vector2f(2400,300), TestShip.character().position());
}

TEST (Entity, PositionFunctionCorrectlyReturnsPosition)
{
	Ship TestShip;
	EXPECT_EQ(Vector2f(2400,300), TestShip.position());
}

TEST (Entity, MapLimitsCanBeSetAndCalled)
{
	Ship TestShip;
	Entity::setMapLimits(Vector2f(100,25));
	EXPECT_EQ(Vector2f(100,25), TestShip.mapLimits());
}

TEST (Entity, DestroyedMemberDataIsCorrectlyInitialisedToBeFalse)
{
	Ship TestShip;
	EXPECT_FALSE(TestShip.destroyed());
}

TEST (Entity, DestroyFunctionDestroysTheEntity)
{
	Ship TestShip;
	TestShip.destroy();
	EXPECT_TRUE(TestShip.destroyed());
}