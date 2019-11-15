//
// Created by sarah on 11/15/2019.
//

#include "stack.h"

int top = -1;

int main(){

    int * arr;

    init_stack(arr);

    push(arr, 5);
    push(arr, 6);
    push(arr, 7);
    push(arr, 10);
    push(arr, 11);

    print_stack(arr);

    int result;
    pop(arr, &result);
    printf("Pop result : %d \n", result);

    print_stack(arr);

    peek(arr, &result);
    printf("Peek result : %d \n", result);

    free(arr); 
    
    return 0;
}

