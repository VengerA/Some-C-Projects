#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "the1_read_input.h"

#define MAX_CUST_REQUIREMENT 1000
#define MAX_SHIP_TYPE_COUNT 10
#define MAX_CUST_COUNT 10

extern int available_captain_count;
extern int ship_type_count;
extern int customer_count;
extern int ship_types[MAX_SHIP_TYPE_COUNT];
extern int customer_requirements[MAX_CUST_COUNT];

void read_input() {

    int i, j;

    scanf("%d",&available_captain_count);
    scanf("%d",&ship_type_count);

    for(i=0; i<ship_type_count; i++)
        scanf("%d",&ship_types[i]);

    scanf("%d",&customer_count);

    for(j=0; j<customer_count; j++)
        scanf("%d",&customer_requirements[j]);
}
