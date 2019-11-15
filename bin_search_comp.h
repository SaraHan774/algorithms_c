//
// Created by sarah on 11/15/2019.
//

#ifndef ALGORITHMS_C_BIN_SEARCH_COMP_H
#define ALGORITHMS_C_BIN_SEARCH_COMP_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

//compare function for binary search
int bin_compare(const void * first, const void * second){
    //printf("first %d, second %d \n", *(int*)first, *(int*)second);
    return *(const int*)first - *(const int*)second;
}

void *bin_search(const void *key, const void *base, size_t nmemb, size_t size, int(*bin_compare)(const void *, const void *)){
    //key : element to search for
    //base : array to sort
    //nmemb : number of elements ?
    //size : size of one element

    //Case 1 : 배열이 비어있어서 search 를 진행할 필요가 없는 경우
    if(nmemb == 0){
        perror("Array is Empty !");
        return NULL;
    }

    //Case 2 : 배열에 요소가 하나밖에 없어서 Equality check 만 필요한 경우
    if(nmemb == 1){
        return *(int *)key == *(int *) base ? (void *) base : NULL;
    }

    //Case 3 : 배열에 요소가 2개 이상 있는 경우
    int left = 0, right = nmemb - 1;
    int center = (right + left) / 2;

    while(left <= right){
        printf("\n Searching ... \n");
        center = (right + left) / 2;
        //printf("center : %d \n", center);

        int compare = bin_compare(base + center * size, key);
        //printf("comparison result : %d \n", compare);

        if(compare > 0){ // arr[center] > key
            right = center - 1;
        }
        else if(compare < 0){ // arr[center] < key
            left = center + 1;
        }
        else if(compare == 0){ // arr[center] == key
            break;
        }
        //printf("(Shifting index) left : %d , right : %d \n", left, right);
    }

    if(left > right){
        perror("Failed to search for the key");
    }

    return (void *) base + center*size;
}

#endif //ALGORITHMS_C_BIN_SEARCH_COMP_H
