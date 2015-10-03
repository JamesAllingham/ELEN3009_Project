#include <iostream> // For testing purposes

#include "Vector2f.h"

#include <cmath>

#include "gtest/gtest.h"

TEST(Vector2f, DefaultConstructorReturnsCorrectInitialisationOfMemberData)
{
	Vector2f test;
	
	EXPECT_EQ(0.f, test.x);
	EXPECT_EQ(0.f, test.y);
}

TEST(Vector2f, CanCorrectlyInitializeDataMembersUsingRelevantConstructor)
{
	Vector2f test(2.f, 5.f);
	
	EXPECT_EQ(2.f, test.x);
	EXPECT_EQ(5.f, test.y);
}

TEST(Vector2f, AssignmentWorksWithoutBeingOverloaded)
{
	Vector2f test(2.f, 5.f);
	Vector2f test2 = test;
	
	EXPECT_EQ(2.f, test2.x);
	EXPECT_EQ(5.f, test2.y);
}

// ==

TEST(Vector2f, EquivalenceOperatorReturnsTrueForTwoEquivalentVectors)
{
	Vector2f test(2.f, 5.f);
	Vector2f test2 = test;
	
	EXPECT_TRUE(test == test2);
}

TEST(Vector2f, EquivalenceOperatorReturnsFalseForTwoInequvalentVectors)
{
	Vector2f test(2.f, 5.f);
	Vector2f test2(2.f, 3.f);
	
	EXPECT_FALSE(test == test2);
}

TEST(Vector2f, InEquivalenceOperatorReturnsFalseForTwoEquvalentVectors)
{
	Vector2f test(2.f, 5.f);
	Vector2f test2 = test;
	
	EXPECT_FALSE(test != test2);
}

TEST(Vector2f, InEquivalenceOperatorReturnsTrueForTwoInequvalentVectors)
{
	Vector2f test(2.f, 5.f);
	Vector2f test2(2.f, 3.f);
	
	EXPECT_TRUE(test != test2);
}

TEST(Vector2f, PlusOperatorOnTwoVectorsWorksCorrectly)
{
	Vector2f test(2.f, 5.f);
	Vector2f test2 = test;
	Vector2f test3 = test + test2;
	EXPECT_TRUE(Vector2f(4.f,10.f) == test3);
}

TEST(Vector2f, PlusOperatorOnVectorPlusScalarWorksCorrectly)
{
	Vector2f test(2.f, 5.f);
	Vector2f test2 = test + 5.f;
	EXPECT_TRUE(Vector2f(7.f,10.f) == test2);
}

TEST(Vector2f, PlusEqualOperatorOnTwoVectorsWorksCorrectly)
{
	Vector2f test(2.f, 5.f);
	Vector2f test2(3.f,4.f);
	test += test2;
	EXPECT_TRUE(Vector2f(5.f,9.f) == test);
	
}

TEST(Vector2f, PlusEqualVectorPlusScalarWorksCorrectly)
{
	Vector2f test(2.f, 5.f);
	test += 5;
	EXPECT_TRUE(Vector2f(7.f,10.f) == test);
	
}

// -

TEST(Vector2f, MinusOperatorVectorMinusVectorHasBeenOverloadedCorrectly)
{
	Vector2f test(2.f, 5.f);
	Vector2f test2(3.f,4.f);
	Vector2f test3 = test - test2;
	EXPECT_TRUE(Vector2f(-1.f,1.f) == test3);
}

TEST(Vector2f, MinusOperatorVectorMinusScalarHasBeenOverloadedCorrectly)
{
	Vector2f test(2.f, 5.f);
	float scalar = 5.f;
	Vector2f test2 = test - scalar;
	EXPECT_TRUE(Vector2f(-3.f,0.f) == test2);
}

TEST(Vector2f, MinusEqualVectorMinusVectorHasBeenOverloadedCorrectly)
{
	Vector2f test(2.f, 5.f);
	Vector2f test2(2.f, 4.f);
	test -= test2;
	EXPECT_TRUE(Vector2f(0.f,1.f) == test);
	
}

TEST(Vector2f, MinusEqualVectorMinusScalarHasBeenOverloadedCorrectly)
{
	Vector2f test(2.f, 5.f);
	test -= 5;
	EXPECT_TRUE(Vector2f(-3.f,0.f) == test);
	
}

// *

TEST(Vector2f, DotProductBetweenTwoVectorsOperatorHasBeenOverloadedCorrectly)
{
	Vector2f test(2.f, 5.f);
	Vector2f test2(3.f,4.f);
	float test3 = test * test2;
	EXPECT_TRUE(26.f == test3);
}

TEST(Vector2f, VectorScalarMultiplicationOperatorHasBeenOverloadedCorrectly)
{
	Vector2f test(2.f,5.f);
	Vector2f test2 = test * 5.f;
	EXPECT_TRUE(Vector2f(10.f,25.f) == test2);
}

TEST(Vector2f, ScalarVectorMultiplicationOperatorHasBeenOverloadedCorrectly)
{
	Vector2f test(2.f,5.f);
	Vector2f test2 = 5.f * test;
	EXPECT_TRUE(Vector2f(10.f,25.f) == test2);
}

TEST(Vector2f, DotProductEqualOperatorHasBeenOverloadedCorrectly)
{
	Vector2f test(2.f, 5.f);
	Vector2f test2(3.f,4.f);
	test *= test2;
	EXPECT_TRUE(Vector2f(6.f,20.f) == test);
}

TEST(Vector2f, VectorScalarMultiplicationEqualOperatorHasBeenOverloadedCorrectly)
{
	Vector2f test(2.f,5.f);
	test *= 5.f;
	EXPECT_TRUE(Vector2f(10.f,25.f) == test);
}

// /

TEST(Vector2f, VectorScalarDivisionOperatorHasBeenOverloadedCorrectly)
{
	Vector2f test(2.f,5.f);
	Vector2f test2 = test / 2.f;
	EXPECT_TRUE(Vector2f(1.f,2.5f) == test2);
}

TEST(Vector2f, VectorScalarDivisionEqualOperatorHasBeenOverloadedCorrectly)
{
	Vector2f test(2.f,5.f);
	test /= 2.f;
	EXPECT_TRUE(Vector2f(1.f,2.5f) == test);
}

TEST(Vector2f, CanCreateAUnitVectorUsingTheUnitVectorFunction)
{
	Vector2f test(2.f, 5.f);
	test = test.unitVector();
	EXPECT_EQ(Vector2f(2.f / (sqrtf(2.f*2.f+5.f*5.f)), 5.f / (sqrtf(2.f*2.f+5.f*5.f))), test);
}

TEST (Vector2f, CanCalculateDistanceBetweenTwoVectorsUsingtheDistanceBetweenVectorsFunction)
{
	Vector2f test(2.f, 5.f);
	Vector2f test2 (4.f, 3.f);
	EXPECT_FLOAT_EQ(sqrtf(8), test.distanceBetweenVectors(test, test2));
}