/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Example "smoke test" (can be deleted)
TEST(GuesserTest, exact_matching_distance)
{
  Guesser object("ABC");
  ASSERT_EQ( 0 , object.distance("ABC);
}

TEST(GuesserTest, lower_case_distance)
{
  Guesser object("ABC");
  ASSERT_EQ( 3, object.distance("abc");
}

TEST(GuesserTest, empty_distance)
{
  Guesser object("ABC");
  ASSERT_EQ( 3, object.distace("");
}

TEST(GuesserTest, large_guess_distance)
{
  Guesser object("ABC");
  ASSERT_EQ( 3, object.distance("qwertyyuiptypou");
}

TEST(GuesserTest, numbers_special_chars_distance)
{
  Guesser object("123&$%");
  ASSERT_EQ( 4, object.distance("123&*@");
}

TEST(GuesserTest, matching_at_end_distance)
{
  Guesser object("ZXCabc");
  ASSERT_EQ( 3, object.distance("POIabc");
}

TEST(GuesserTest, large_guess_end_different_distance)
{
  Guesser object("ABCDE");
  ASSERT_EQ( 5, object.distance("ABCDEfghijkl );
}

TEST(GuesserTest, guess_end_different_distance)
{
  Guesser object("ABCDE");
  ASSERT_EQ( 1, object.distance("ABCDEf);
}
