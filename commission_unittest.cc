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

TEST(CommisionMonthTest, WeakNormalFirstRankSale ) {
	// total = 200
	EXPECT_DOUBLE_EQ( 20.0, get_commission_month(2, 2, 2) );
	
	// total = 995
	EXPECT_DOUBLE_EQ( 99.5, get_commission_month(8, 12, 11) );
	
	// total = 1000
	EXPECT_DOUBLE_EQ( 100.0, get_commission_month(10, 10, 10) );
}
