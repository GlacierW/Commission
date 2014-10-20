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


TEST(CommisionMonthTest, WeakNormalSecondRankSale ) {
	// total = 1005
	EXPECT_DOUBLE_EQ( 100.75, get_commission_month(9, 10, 12) );
	
	// total = 1795
	EXPECT_DOUBLE_EQ( 219.25, get_commission_month(20, 19, 13) );
	
	// total = 1800
	EXPECT_DOUBLE_EQ( 220.0, get_commission_month(20, 20, 12) );
}

TEST(CommisionMonthTest, WeakNormalThirdRankCommission ) {
	// total = 1805
	EXPECT_DOUBLE_EQ( 221.0, get_commission_month(19, 20, 14) );
	
	// total = 7700
	EXPECT_DOUBLE_EQ( 1400.0, get_commission_month(69, 79, 89) );
}

TEST(CommisionMonthTest, WeakRobustSale ) {
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(NB_LOCK_MIN - 1, 1, 1) );
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(1, NB_STOCK_MIN - 1, 1) );
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(1, 1, NB_BARREL_MIN - 1) );
	
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(NB_LOCK_MAX + 1, 1, 1) );
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(1, NB_STOCK_MAX + 1, 1) );
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(1, 1, NB_BARREL_MAX + 1) );
}

TEST(CommisionMonthTest, StrongRobustSale ) {
	// two min - 1
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(NB_LOCK_MIN - 1, NB_STOCK_MIN - 1, 1) );
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(1, NB_STOCK_MIN - 1, NB_BARREL_MIN - 1) );
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(NB_LOCK_MIN - 1, 1, NB_BARREL_MIN - 1) );
	
	// all min - 1
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(NB_LOCK_MIN - 1, NB_STOCK_MIN - 1, NB_BARREL_MIN - 1) );
	
	/* ----------------------------------- */
	
	// two max + 1
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(NB_LOCK_MAX + 1, NB_STOCK_MAX + 1, 1) );
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(1, NB_STOCK_MAX + 1, NB_BARREL_MAX + 1) );
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(NB_LOCK_MAX + 1, 1, NB_BARREL_MAX + 1) );
	
	// all max + 1
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(NB_LOCK_MAX + 1, NB_STOCK_MAX + 1, NB_BARREL_MAX + 1) );
	
	/* ----------------------------------- */
	
	// one min-1, one max+1, one normal
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(NB_LOCK_MIN - 1, NB_STOCK_MAX + 1, 1) );
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(NB_LOCK_MAX + 1, NB_STOCK_MIN - 1, 1) );
	
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(NB_LOCK_MIN - 1, 1, NB_BARREL_MAX + 1) );
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(NB_LOCK_MAX + 1, 1, NB_BARREL_MIN - 1) );
	
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(1, NB_STOCK_MIN - 1, NB_BARREL_MAX + 1) );
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(1, NB_STOCK_MAX + 1, NB_BARREL_MIN - 1) );
	
	// one min-1, two max+1
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(NB_LOCK_MIN - 1, NB_STOCK_MAX + 1, NB_BARREL_MAX + 1) );
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(NB_LOCK_MAX + 1, NB_STOCK_MIN - 1, NB_BARREL_MAX + 1) );
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(NB_LOCK_MAX + 1, NB_STOCK_MAX + 1, NB_BARREL_MIN - 1) );
	
	// two min-1, one max+1
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(NB_LOCK_MAX + 1, NB_STOCK_MIN - 1, NB_BARREL_MIN - 1) );
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(NB_LOCK_MIN - 1, NB_STOCK_MAX + 1, NB_BARREL_MIN - 1) );
	EXPECT_DOUBLE_EQ( ERR_INVALID_SALE, get_commission_month(NB_LOCK_MIN - 1, NB_STOCK_MIN - 1, NB_BARREL_MAX + 1) );
}
