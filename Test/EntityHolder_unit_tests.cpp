#include "EntityHolder.h"
#include "Ship.h"
#include "Flyer.h"
#include "gtest/gtest.h"

using std::next;

TEST(EntityHolder, doesntAddANullPointer)
{
	EntityHolder testEntityHolder;
	
	testEntityHolder.addEntity(nullptr);
	
	EXPECT_EQ(testEntityHolder.numberOfEntites(),0);
}

TEST(EntityHolder, succesfullyAddsAValidEntity)
{
	EntityHolder testEntityHolder;
	
	testEntityHolder.addEntity(shared_ptr<Ship> (new Ship));
	
	EXPECT_EQ(testEntityHolder.numberOfEntites(),1);
	
	testEntityHolder.addEntity(shared_ptr<Ship> (new Flyer));
	
	EXPECT_EQ(testEntityHolder.numberOfEntites(),2);
}

TEST(EntityHolder, succesfullyEraseAnEntityAtStartOFContainer)
{
	EntityHolder testEntityHolder;
	
	testEntityHolder.addEntity(shared_ptr<Ship> (new Ship));	
	
	testEntityHolder.eraseEntity(testEntityHolder.begin());
	
	EXPECT_EQ(testEntityHolder.numberOfEntites(),0);
}

TEST(EntityHolder, succesfullyEraseAnEntityAtAnAribitraryPositionInContainer)
{
	EntityHolder testEntityHolder;
	
	testEntityHolder.addEntity(shared_ptr<Ship> (new Ship));	
	testEntityHolder.addEntity(shared_ptr<Ship> (new Ship));
	testEntityHolder.addEntity(shared_ptr<Ship> (new Ship));
	
	testEntityHolder.eraseEntity(next(testEntityHolder.begin());
	
	EXPECT_EQ(testEntityHolder.numberOfEntites(),2);
}

TEST(EntityHolder, succesfullyEraseAllEntitesInContainer)
{
	EntityHolder testEntityHolder;
	
	testEntityHolder.addEntity(shared_ptr<Ship> (new Ship));	
	testEntityHolder.addEntity(shared_ptr<Ship> (new Ship));
	testEntityHolder.addEntity(shared_ptr<Ship> (new Ship));
	
	for (auto entity_itr = testEntityHolder.begin(); entity_itr != testEntityHolder.end(); )
	{
		entity_itr = testEntityHolder.eraseEntity(entity_itr);
	}
	
	EXPECT_EQ(testEntityHolder.numberOfEntites(),0);
}