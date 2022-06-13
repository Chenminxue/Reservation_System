#include "pch.h"
#include <gtest/gtest.h>
#include "../Reservation_System/Login.h"

TEST(LoginFileCheck, LoginTest) {
	
	EXPECT_EQ("Error! File doesn't exist!", Login("TEST", 1));
	EXPECT_TRUE(true);
}

