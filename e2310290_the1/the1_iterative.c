#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "the1_iterative.h"

#define MAX_CUST_REQUIREMENT 1000
#define MAX_SHIP_TYPE_COUNT 10
#define MAX_CUST_COUNT 10

int min_ships_required_iterative(int ship_types[], int ship_type_count, int customer_requirement) {
    int arr[1000] = {0, 1};
    int index, min, i, j;
    for(i = 2; i < customer_requirement+1; i++){
        arr[i] = customer_requirement+1;
    }
    for(i = 2; i < customer_requirement+1; i++){
            for(j = 0; j < ship_type_count; j++){
                index = i-ship_types[j];
                if(index > 0){
                    if(arr[index]+1<arr[i]){
                        arr[i] = arr[index]+1;
                }
            }
        }
    }
    return arr[customer_requirement];
}
