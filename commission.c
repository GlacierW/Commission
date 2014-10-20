#include "commission.h"

const int	 SALE_RANK_THRESHOLD[SALE_RANKS] = { 0, 1000, 1800 };
const double SALE_COMMISSION_PERCENT[SALE_RANKS] = { 0.1, 0.15, 0.2 };

double get_commission_month( int nb_lock, int nb_stock, int nb_barrel ) {
	
	// validate the input sale
	if(
		nb_lock   < NB_LOCK_MIN
	||	nb_stock  < NB_STOCK_MIN
	||	nb_barrel < NB_BARREL_MIN
	||	nb_lock	  > NB_LOCK_MAX
	||	nb_stock  > NB_STOCK_MAX
	||	nb_barrel > NB_BARREL_MAX
	) {
		return ERR_INVALID_SALE;
	}
	
	return (double)0xdeadbeef;
}
