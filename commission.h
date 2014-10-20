#ifndef __COMMISION_H__
#define __COMMISION_H__

#define PRICE_LOCK		45
#define PRICE_STOCK		30
#define PRICE_BARREL	25

#define NB_LOCK_MIN		1
#define NB_LOCK_MAX		70

#define NB_STOCK_MIN	1
#define NB_STOCK_MAX	80

#define NB_BARREL_MIN	1
#define NB_BARREL_MAX	90

#define SALE_RANKS	3

#define ERR_INVALID_SALE 0.0

extern const int	SALE_RANK_THRESHOLD[SALE_RANKS];
extern const double	SALE_COMMISSION_PERCENT[SALE_RANKS];

extern double get_commission_month( int nb_lock, int nb_stock, int barrel );
#endif
