//
// Created by sarah on 11/15/2019.
//

#ifndef ALGORITHMS_C_STACK_H
#define ALGORITHMS_C_STACK_H

#include <stdlib.h>
#include <stdio.h>
#define MAX_ARR_SIZE 50

extern int top;

int init_stack(const int * arr){
    arr = malloc(sizeof(int) * MAX_ARR_SIZE);

    if(arr == NULL) {
        perror("Init Stack Failed");
        return -1;
    }
    return 0;
}


/*
 * return true if top is at -1, otherwise return 0
 */
int is_stack_empty(const int * top){
    return *top == -1 ? 1 : 0;
}


int push(int * arr, int item){
    if(top >= MAX_ARR_SIZE - 1){
        perror("Stack Overflow");
        return -1;
    }
    else{
        arr[++top] = item;
    }
}

int peek(const int * arr, int * result){
    if(top < 0){
        perror("Stack Underflow");
        return -1;
    }
    else{
        result[0] = arr[top];
        return 0;
    }
}

int pop(int * arr, int * result){
    //Peek method can be reused !
    peek(arr, result);
    top--;
    return 0;
}

void print_stack(int * arr){
    for(int i = 0; i <= top; i++){
        printf("arr[%d] : %d \n", i, arr[i]);
    }
    puts("End of Array");
}



#endif //ALGORITHMS_C_STACK_H