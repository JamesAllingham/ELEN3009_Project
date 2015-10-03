#include "EntityHolder.h"
#include "Ship.h"
#include "Flyer.h"
#include "gtest/gtest.h"

using std::next;
using std::make_shared;

TEST(EntityHolder, doesntAddANullPointer)
{
	EntityHolder testEntityHolder;
	
	testEntityHolder.addEntity(nullptr);
	
	EXPECT_EQ(testEntityHolder.numberOfEntities(),0);
}

TEST(EntityHolder, succesfullyAddsAValidEntity)
{
	EntityHolder testEntityHolder;
	
	testEntityHolder.addEntity(make_shared<Flyer> ());
	
	EXPECT_EQ(testEntityHolder.numberOfEntities(),1);
	
	testEntityHolder.addEntity(make_shared<Flyer> ());
	
	EXPECT_EQ(testEntityHolder.numberOfEntities(),2);
}

TEST(EntityHolder, succesfullyEraseAnEntityAtStartOFContainer)
{
	EntityHolder testEntityHolder;
	
	testEntityHolder.addEntity(make_shared<Ship> ());	
	
	testEntityHolder.eraseEntity(testEntityHolder.begin());
	
	EXPECT_EQ(testEntityHolder.numberOfEntities(),0);
}

TEST(EntityHolder, succesfullyEraseAnEntityAtAnAribitraryPositionInContainer)
{
	EntityHolder testEntityHolder;
	
	testEntityHolder.addEntity(make_shared<Flyer> ());	
	testEntityHolder.addEntity(make_shared<Flyer> ());
	testEntityHolder.addEntity(make_shared<Flyer> ());
	
	testEntityHolder.eraseEntity(next(testEntityHolder.begin()));
	
	EXPECT_EQ(testEntityHolder.numberOfEntities(),2);
}

TEST(EntityHolder, succesfullyEraseAllEntitesInContainer)
{
	EntityHolder testEntityHolder;
	
	testEntityHolder.addEntity(make_shared<Flyer> ());	
	testEntityHolder.addEntity(make_shared<Flyer> ());
	testEntityHolder.addEntity(make_shared<Flyer> ());
	
	for (auto entity_itr = testEntityHolder.begin(); entity_itr != testEntityHolder.end(); )
	{
		entity_itr = testEntityHolder.eraseEntity(entity_itr);
	}
	
	EXPECT_EQ(testEntityHolder.numberOfEntities(),0);
}