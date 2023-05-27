#include "../common/types.h"

typedef struct Date Date;

struct Date
{
    u8 year;
    u8 month;
    u8 day;
};

Date date(u8 year, u8 month, u8 day);
