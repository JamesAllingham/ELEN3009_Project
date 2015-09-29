#include <ctime>
#include <cmath>
#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <iostream> // For testing purposes

#include "Flyer.h"

#include "gtest/gtest.h"

TEST(Flyer, NumberOfFlyersIncreasesWithNewlyCreatedFlyers)
{
	shared_ptr<Flyer> Flyer1 (new Flyer);
	shared_ptr<Flyer> Flyer2 (new Flyer);
	shared_ptr<Flyer> Flyer3 (new Flyer);
	
	EXPECT_EQ(3, Flyer::numberOfFlyers());
}
