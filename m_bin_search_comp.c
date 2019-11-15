//
// Created by sarah on 11/15/2019.
//

#include "bin_search_comp.h"

int main(){

    int arr [] = {1, 3, 5, 6, 7, 8, 10, 11, 12, 13, 14};
    int arr_size = sizeof(arr)/ sizeof(int);
    int key = 14;

    printf("%d\n", arr_size);
    int * result = (int *)bin_search(&key, arr, arr_size, sizeof(int), bin_compare);

    if(result != NULL) {
        printf("Found : %d", *result);
    }

    return 0;
}