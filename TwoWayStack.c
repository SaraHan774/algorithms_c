//
// Created by sarah on 11/24/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "TwoWayStack.h"
#include <stdbool.h>

int item;

int init_stack_array(two_way_arr_t * twoWayArr, int max){
    if(twoWayArr -> arr == NULL){
        twoWayArr -> arr = calloc(max, sizeof(int));

        //maximum num of elements in the array
        twoWayArr -> max = max;

        //left side of the array
        twoWayArr -> leftIdx = -1;

        //right side of the array
        twoWayArr -> rightIdx = max;
        return 0;
    }
    return -1;
}


int push(two_way_arr_t * twoWayArr, int data, position_t pos){

    //각각의 스택이 서로를 침범하지 않는지 검사 후 push 진행
    if(is_full(twoWayArr) == true){
        perror("No room for insertion!");
        return -1;
    }

    switch(pos){
        case LEFT :
            twoWayArr -> arr[++(twoWayArr -> leftIdx)] = data;
            break;

        case RIGHT :
            twoWayArr -> arr[--(twoWayArr -> rightIdx)] = data;
            break;
    }

    printf("pushed item %d \n", data);
}


int pop(two_way_arr_t * twoWayArr, position_t pos){

    switch(pos){
        case LEFT :
            if(twoWayArr -> leftIdx <= -1){
                perror("Left side of the array is empty !");
                return -1;
            }else{
                item = twoWayArr -> arr[(twoWayArr -> leftIdx)];
                twoWayArr -> arr[(twoWayArr -> leftIdx)--] = 0;
                break;
            }

        case RIGHT :
            if(twoWayArr -> rightIdx >= capacity(twoWayArr)){
                perror("Right side of the array is empty !");
                return -1;
            }else{
                item = twoWayArr -> arr[(twoWayArr -> rightIdx)];
                twoWayArr -> arr[(twoWayArr -> rightIdx)--] = 0;
                break;
            }
    }
    printf("popped item %d \n", item);
    return 0;
}


int peek(two_way_arr_t * twoWayArr, position_t pos){
    switch(pos){
        case LEFT :
            if(twoWayArr -> leftIdx <= -1){
                perror("Left side of the array is empty !");
                return -1;
            }else{
                item = twoWayArr -> arr[twoWayArr -> leftIdx];
                break;
            }

        case RIGHT :
            if(twoWayArr -> rightIdx >= capacity(twoWayArr)){
                perror("Right side of the array is empty !");
                return -1;
            }else{
                item = twoWayArr -> arr[twoWayArr -> rightIdx];
                break;
            }
    }

    printf("peeked item %d \n", item);
    return 0;
}


void clear(two_way_arr_t * twoWayArr, position_t pos){
    switch(pos){
        case LEFT :
            for(int i = 0; i <= twoWayArr -> leftIdx; i++){
                twoWayArr -> arr[i] = 0;
            }
            twoWayArr -> leftIdx = -1;
            break;

        case RIGHT :
            for(int i = twoWayArr -> max; i >= twoWayArr -> rightIdx; i--){
                twoWayArr -> arr[i] = 0;
            }
            twoWayArr -> rightIdx = capacity(twoWayArr);
            break;
    }

    puts("cleared data\n");
}


int size(two_way_arr_t * twoWayArr, position_t pos){
    switch(pos){
        case LEFT :
            return twoWayArr -> leftIdx;

        case RIGHT :
            return capacity(twoWayArr) - (twoWayArr -> rightIdx);
    }
}


int capacity(two_way_arr_t * twoWayArr){
    return twoWayArr -> max;
}

int is_full(two_way_arr_t * twoWayArr){
    return twoWayArr -> leftIdx >=  twoWayArr -> rightIdx ? true : false;
}


void print_arr(two_way_arr_t * twoWayArr){
    for(int i = 0; i < twoWayArr -> max; i++){
        printf("%d ", twoWayArr -> arr[i]);
    }
    puts("\n");
}


void terminate(two_way_arr_t * twoWayArr){
    if(twoWayArr -> arr!= NULL){
        free(twoWayArr -> arr);
    }
    twoWayArr -> max = twoWayArr -> leftIdx = twoWayArr -> rightIdx = 0;

}