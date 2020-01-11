#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "the1_recursive.h"

#define MAX_CUST_REQUIREMENT 1000
#define MAX_SHIP_TYPE_COUNT 10
#define MAX_CUST_COUNT 10

int min_ships_required_recursive(int ship_types[], int ship_type_count, int customer_requirement) {
    return helper(ship_types, ship_type_count, customer_requirement, 0, customer_requirement+1);
}

int helper(int ship_types[], int ship_type_count, int customer_requirement, int count, int min) {
    int i, tmpr_count,min_new;
    min_new = min;
    if(customer_requirement == 0){
        return count;
    }
    if(customer_requirement < 0){
        return -1;
    }

    for(i = 0; i < ship_type_count; i++){
        tmpr_count = helper(ship_types, ship_type_count, customer_requirement - ship_types[i], count + 1, min_new);
        if(tmpr_count == -1){
            continue;
        }
        printf("%d %d %d\n",  customer_requirement,tmpr_count, count);
        if(tmpr_count < min_new){
            min_new = tmpr_count;
        }
    }
    return min_new ;
}
