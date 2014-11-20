#include "commission.h"

const double SALE_RANK_THRESHOLD[SALE_RANKS] = { 0.0, 1000.0, 1800.0 };
const double SALE_COMMISSION_PERCENT[SALE_RANKS] = { 0.1, 0.15, 0.2 };

double get_commission_month( int nb_lock, int nb_stock, int nb_barrel ) {
	
	int i, rank = 0;
	double sale = 0.0,
		   commission = 0.0;
	
	// validate the input sale
	if( nb_lock < NB_LOCK_MIN || nb_stock < NB_STOCK_MIN || nb_barrel < NB_BARREL_MIN || nb_lock > NB_LOCK_MAX || nb_stock > NB_STOCK_MAX || nb_barrel > NB_BARREL_MAX ) 
		return ERR_INVALID_SALE;
	
	sale = PRICE_LOCK   * nb_lock 
		 + PRICE_STOCK  * nb_stock
		 + PRICE_BARREL * nb_barrel;
		
	// decide rank 
	for( i = 0; i < SALE_RANKS; ++i ) 
		if( sale > SALE_RANK_THRESHOLD[i] ) 
			rank = i;
			
	// calculate commission
	for( i = rank; i >= 0; --i ) {
		commission = commission + ((sale - SALE_RANK_THRESHOLD[i]) * SALE_COMMISSION_PERCENT[i]);
		sale = SALE_RANK_THRESHOLD[i];
	}
	
	return commission;
}
