
#include "ResourceHolder.h"
#include "gtest/gtest.h"

#include <SFML/Graphics.hpp>
using sf::Texture;
using sf::IntRect;

// Tests for ResourceHolder
// Just like regular use of classes a test should only use the public interface of the class 
TEST(ResourceHolder, loadWithTwoParametersThrowsCorrectly)
{
	enum class TestID
	{
		Test1 = 1,
		Test2
	};
	
	ResourceHolder<Texture,TestID> testTextures;
	
	EXPECT_THROW(testTextures.load(TestID::Test1, "resources/test1.jpg"),runtime_error);
	EXPECT_NO_THROW(testTextures.load(TestID::Test2, "resources/test.jpg"));
}

TEST(ResourceHolder, loadWithThreeParametersThrowsCorrectly)
{
	enum class TestID
	{
		Test1 = 1,
		Test2
	};
	
	ResourceHolder<Texture,TestID> testTextures;
	
	EXPECT_THROW(testTextures.load(TestID::Test1, "resources/test1.jpg",IntRect(10, 10, 32, 32)),runtime_error);
	EXPECT_NO_THROW(testTextures.load(TestID::Test2, "resources/test.jpg",IntRect(10, 10, 32, 32)));
}

TEST(ResourceHolder, nonConstGetFunctionReturnsCorrectResource)
{
	string file_path_and_name = "resources/test.jpg";
	
	enum class TestID
	{
		Test1 = 1,
		Test2
	};
	
	ResourceHolder<Texture,TestID> testTextures;
	
	testTextures.load(TestID::Test1, file_path_and_name);
	
	Texture testTexture;
	testTexture.loadFromFile(file_path_and_name);
	
	// This might not be a good way to test this - not sure
	EXPECT_EQ(testTexture.getSize(),testTextures.get(TestID::Test1).getSize());	
}

TEST(ResourceHolder, constGetFunctionReturnsCorrectResource)
{
	string file_path_and_name = "resources/test.jpg";
	
	enum class TestID
	{
		Test1 = 1,
		Test2
	};
	
	ResourceHolder<Texture,TestID> testTextures;	
	testTextures.load(TestID::Test1, file_path_and_name);
	const auto * const_textures_ptr = &testTextures;
	
	Texture testTexture;
	testTexture.loadFromFile(file_path_and_name);
	
	const Texture testTextureConst = const_textures_ptr->get(TestID::Test1);
	
	EXPECT_EQ(testTexture.getSize(),testTextureConst.getSize());	
}