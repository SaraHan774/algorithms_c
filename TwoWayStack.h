//
// Created by sarah on 11/24/2019.
//

#ifndef ALGORITHMS_C_TWOWAYSTACK_H
#define ALGORITHMS_C_TWOWAYSTACK_H

#include "IntStack.h"

typedef enum {LEFT, RIGHT} position_t;

typedef struct {
    //기존의 인덱스 관리를 세분화
    int leftIdx;
    int rightIdx;
    int max;
    int * arr;
}two_way_arr_t;


int init_stack_array(two_way_arr_t * twoWayArr, int max);
int push(two_way_arr_t * twoWayArr, int item, position_t pos);
int pop(two_way_arr_t * twoWayArr, position_t pos);
int peek(two_way_arr_t * twoWayArr, position_t pos);
void clear(two_way_arr_t * twoWayArr, position_t pos);
int is_full(two_way_arr_t * twoWayArr);
int size(two_way_arr_t * twoWayArr, position_t pos);
int capacity(two_way_arr_t * twoWayArr);
void print_arr(two_way_arr_t * twoWayArr);
void terminate(two_way_arr_t * twoWayArr);




#endif //ALGORITHMS_C_TWOWAYSTACK_H
