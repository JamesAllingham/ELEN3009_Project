#include <iostream> // For testing purposes

#include "Vector2f.h"

#include <cmath>

#include "gtest/gtest.h"

TEST(Vector2f, DefaultConstructorReturnsCorrectInitialisationOfMemberData)
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

TEST(Vector2f, EquivalenceOperatorReturnsFalseForTwoInequvalentVectors)
{
	Vector2f Test(2.f, 5.f);
	Vector2f Test2(2.f, 3.f);
	
	EXPECT_FALSE(Test == Test2);
}

TEST(Vector2f, InEquivalenceOperatorReturnsFalseForTwoEquvalentVectors)
{
	Vector2f Test(2.f, 5.f);
	Vector2f Test2 = Test;
	
	EXPECT_FALSE(Test != Test2);
}

TEST(Vector2f, InEquivalenceOperatorReturnsTrueForTwoInequvalentVectors)
{
	Vector2f Test(2.f, 5.f);
	Vector2f Test2(2.f, 3.f);
	
	EXPECT_TRUE(Test != Test2);
}

TEST(Vector2f, PlusOperatorVectorLvalueHasBeenOverloadedCorrectly)
{
	Vector2f Test(2.f, 5.f);
	Vector2f Test2 = Test;
	Vector2f Test3 = Test + Test2;
	EXPECT_TRUE(Vector2f(4.f,10.f) == Test3);
}

TEST(Vector2f, PlusOperatorScalarHasBeenOverloadedCorrectly)
{
	Vector2f Test(2.f, 5.f);
	Vector2f Test2 = Test + 5.f;
	EXPECT_TRUE(Vector2f(7.f,10.f) == Test2);
}

TEST(Vector2f, PlusEqualVectorOverloadWorksCorrectly)
{
	Vector2f Test(2.f, 5.f);
	Vector2f Test2(3.f,4.f);
	Test += Test2;
	EXPECT_TRUE(Vector2f(5.f,9.f) == Test);
	
}

TEST(Vector2f, PlusEqualScalarOverloadWorksCorrectly)
{
	Vector2f Test(2.f, 5.f);
	Test += 5;
	EXPECT_TRUE(Vector2f(7.f,10.f) == Test);
	
}

TEST(Vector2f, MinusOperatorVectorHasBeenOverloadedCorrectly)
{
	Vector2f Test(2.f, 5.f);
	Vector2f Test2(3.f,4.f);
	Vector2f Test3 = Test - Test2;
	EXPECT_TRUE(Vector2f(-1.f,1.f) == Test3);
}

TEST(Vector2f, MinusOperatorScalarHasBeenOverloadedCorrectly)
{
	Vector2f Test(2.f, 5.f);
	float scalar = 5.f;
	Vector2f Test2 = Test - scalar;
	EXPECT_TRUE(Vector2f(-3.f,0.f) == Test2);
}

TEST(Vector2f, MinusEqualVectorOverloadWorksCorrectly)
{
	Vector2f Test(2.f, 5.f);
	Vector2f Test2(2.f, 4.f);
	Test -= Test2;
	EXPECT_TRUE(Vector2f(0.f,1.f) == Test);
	
}

TEST(Vector2f, MinusEqualScalarOverloadWorksCorrectly)
{
	Vector2f Test(2.f, 5.f);
	Test -= 5;
	EXPECT_TRUE(Vector2f(-3.f,0.f) == Test);
	
}

TEST(Vector2f, DotProductOperatorHasBeenOverloadedCorrectly)
{
	Vector2f Test(2.f, 5.f);
	Vector2f Test2(3.f,4.f);
	float Test3 = Test * Test2;
	EXPECT_TRUE(26.f == Test3);
}

TEST(Vector2f, VectorScalarMultiplicationOperatorWorksCorrectly)
{
	Vector2f Test(2.f,5.f);
	Vector2f Test2 = Test * 5.f;
	EXPECT_TRUE(Vector2f(10.f,25.f) == Test2);
}

TEST(Vector2f, DotProductEqualOperatorHasBeenOverloadedCorrectly)
{
	Vector2f Test(2.f, 5.f);
	Vector2f Test2(3.f,4.f);
	Test *= Test2;
	EXPECT_TRUE(Vector2f(6.f,20.f) == Test);
}

TEST(Vector2f, VectorScalarMultiplicationEqualOperatorWorksCorrectly)
{
	Vector2f Test(2.f,5.f);
	Test *= 5.f;
	EXPECT_TRUE(Vector2f(10.f,25.f) == Test);
}

TEST(Vector2f, VectorScalarDivisionOperatorWorksCorrectly)
{
	Vector2f Test(2.f,5.f);
	Vector2f Test2 = Test / 2.f;
	EXPECT_TRUE(Vector2f(1.f,2.5f) == Test2);
}

TEST(Vector2f, VectorScalarDivisionEqualOperatorWorksCorrectly)
{
	Vector2f Test(2.f,5.f);
	Test /= 2.f;
	EXPECT_TRUE(Vector2f(1.f,2.5f) == Test);
}

TEST(Vector2f, CanCreateAUnitVectorUsingTheUnitVectorFunction)
{
	Vector2f Test(2.f, 5.f);
	Test = Test.unitVector();
	EXPECT_EQ(Vector2f(2.f / (sqrtf(2.f*2.f+5.f*5.f)), 5.f / (sqrtf(2.f*2.f+5.f*5.f))), Test);
}