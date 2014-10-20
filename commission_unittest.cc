#include <gtest/gtest.h>
#include "commission.h"

TEST(CommisionMonthTest, NormalBoundarySale ) {
	EXPECT_DOUBLE_EQ( 10.0, get_commission_month(1, 1, 1) );
	EXPECT_DOUBLE_EQ( 1420.0, get_commission_month(NB_LOCK_MAX, NB_STOCK_MAX, NB_BARREL_MAX) );
}

TEST(CommisionMonthTest, NegativeSale ) {
	// one negative
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(-1, 1, 1) );
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(1, -1, 1) );
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(1, 1, -1) );
	
	// two negative
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(-1, -1, 1) );
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(-1, 1, -1) );
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(1, -1, -1) );
	
	// all negative
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(-1, -1, -1) );
}
