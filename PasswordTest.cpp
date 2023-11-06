/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};


TEST(PasswordTest, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, letters_repeated_at_end)
{
    Password my_password;
	ASSERT_EQ(1,my_password.count_leading_characters("Zoo"));
}

TEST(PasswordTest, spaces)//checks to see if spaces count as characters
{
    Password my_password;
	ASSERT_EQ(1,my_password.count_leading_characters(" "));
}

TEST(PasswordTest, later_repeating_character)//checks to see if characters repeat more than once non-consecutively
{
    Password my_password;
	ASSERT_EQ(1,my_password.count_leading_characters("abaab"));
}

TEST(PasswordTest, empty_string)//checks to see if empty string is acceptable
{
    Password my_password;
	ASSERT_EQ(1,my_password.count_leading_characters(""));
}

TEST(PasswordTest, mixed_case)
{
	Password my_password;
	ASSERT_EQ(true, my_password.has_mixed_case("Abba"));

}

TEST(PasswordTest, not_mixed_case)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("abba"));

}
