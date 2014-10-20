#include <gtest/gtest.h>
#include "commission.h"

TEST(CommisionMonthTest, NormalBoundarySale ) {
	EXPECT_DOUBLE_EQ( 10.0, get_commission_month(1, 1, 1) );
	EXPECT_DOUBLE_EQ( 1420.0, get_commission_month(NB_LOCK_MAX, NB_STOCK_MAX, NB_BARREL_MAX) );
}

