#include "EntityHolder.h"
#include "Ship.h"
#include "Flyer.h"
#include "gtest/gtest.h"
#include "Vector2f.h"

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

TEST (EntityHolder, allCharacterIDsAreStoredWhenCallingCharacterFunction)
{
	EntityHolder testEntityHolder;
	testEntityHolder.addEntity(make_shared<Ship>());
	testEntityHolder.addEntity(make_shared<Flyer>());
	testEntityHolder.addEntity(make_shared<Laser>(Vector2f(0.f,0.f),Vector2f(0.f,0.f)));
	list<Character> character_list = testEntityHolder.characters();
	auto number_of_characters =0;
	for (auto character : character_list)
	{
		switch (character.entityID())
		{
			case EntityID::Ship:
			case EntityID::Flyer:
			case EntityID::Laser:
				number_of_characters++;
				break;
			default:
				break;
		}	
	}
	EXPECT_TRUE (testEntityHolder.numberOfEntities() == number_of_characters);
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