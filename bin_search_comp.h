//
// Created by sarah on 11/15/2019.
//

#ifndef ALGORITHMS_C_BIN_SEARCH_COMP_H
#define ALGORITHMS_C_BIN_SEARCH_COMP_H

#include <limits.h>
#include <stdio.h>

//compare function for binary search
int bin_compare(const void * first, const void * second){
    printf("first %d, second %d \n", *(int*)first, *(int*)second);
    return *(const int*)first - *(const int*)second;
}

void *bin_search(const void *key, const void *base, size_t nmemb, size_t size, int(*bin_compare)(const void *, const void *)){
    //key : element to search for
    //base : array to sort
    //nmemb : number of elements ?
    //size : size of one element

//    for(int i = 0; i < nmemb ; i++){
//        printf("%d  ", *(int*)(base + i*size));
//    }

    int left = 0, right = nmemb - 1;

    while(left <= right){
        printf("\n Searching ... \n");
        int center = (right + left) / 2;
        printf("center : %d \n", center);

        int compare = bin_compare(base + center * size, key);
        printf("comparison result : %d \n", compare);

        if(compare > 0){ // arr[center] > key
            right = center - 1;
        }
        else if(compare < 0){ // arr[center] < key
            left = center + 1;
        }
        else if(compare == 0){ // arr[center] == key
            printf("Binary Search - Found element %d at index arr[%d]", *(int *)key, center);
            break;
        }
        printf("(Shifting index) left : %d , right : %d \n", left, right);
    }

    if(left > right){
        printf("Failed to search for key %d \n", *(int*)key);
    }

    return NULL;
}

#endif //ALGORITHMS_C_BIN_SEARCH_COMP_H
