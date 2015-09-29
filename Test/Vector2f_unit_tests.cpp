#include <ctime>
#include <cmath>
#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <iostream> // For testing purposes

#include "Vector2f.h"

#include "gtest/gtest.h"

TEST(Vector2f, AutomaticInitialisingReturnsCorrectValues)
{
	Vector2f Test;
	
	EXPECT_EQ(0.f, Test.x);
	EXPECT_EQ(0.f, Test.y);
}

TEST(Vector2f, CanCorrectlyInitializeDataMembersUsingRelevantConstructor)
{
	Vector2f Test(2.f, 5.f);
	
	EXPECT_EQ(2.f, Test.x);
	EXPECT_EQ(5.f, Test.y);
}

TEST(Vector2f, EqualSignWorksWithoutBeingOverloaded)
{
	Vector2f Test(2.f, 5.f);
	Vector2f Test2 = Test;
	
	EXPECT_EQ(2.f, Test2.x);
	EXPECT_EQ(5.f, Test2.y);
}

TEST(Vector2f, EquivalenceOperatorReturnsTrueForTwoEquvalentVectors)
{
	Vector2f Test(2.f, 5.f);
	Vector2f Test2 = Test;
	
	EXPECT_TRUE(Test == Test2);
}

TEST(Vector2f, PlusOperatorHasBeenOverloadedCorrectly)
{
	Vector2f Test(2.f, 5.f);
	Vector2f Test2 = Test;
	Vector2f Test3 = Test + Test2;
	EXPECT_TRUE(Vector2f(4.f,10.f) == Test3);
}

TEST(Vector2f, MinusOperatorHasBeenOverloadedCorrectly)
{
	Vector2f Test(2.f, 5.f);
	Vector2f Test2(3.f,4.f);
	Vector2f Test3 = Test - Test2;
	EXPECT_TRUE(Vector2f(-1.f,1.f) == Test3);
}

TEST(Vector2f, DotProductOperatorHasBeenOverloadedCorrectly)
{
	Vector2f Test(2.f, 5.f);
	Vector2f Test2(3.f,4.f);
	Vector2f Test3 = Test * Test2;
	EXPECT_TRUE(Vector2f(6.f,20.f) == Test3);
}

TEST(Vector2f, CanMultiplyAVectorByAScalar)
{
	Vector2f Test(2.f,5.f);
	Vector2f Test2 = 5.f * Test;
	EXPECT_TRUE(Vector2f(10.f,25.f) == Test2);
}

// | x1 y1 |
// | x2 y2 | = (x1*y2 - y1*x2, y1*x2 - y2*x1
TEST(Vector2f, CrossProductFunctionWorksCorrectly)
{
	Vector2f Test(2.f, 5.f);
	Vector2f Test2(3.f,4.f);
	Vector2f Test3 = Test3.CrossProduct(Test, Test2);
	EXPECT_TRUE(Vector2f(-7.f,7.f) == Test3);
	
}

