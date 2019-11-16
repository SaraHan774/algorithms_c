//
// Created by sarah on 11/16/2019.
//

#include <stdio.h>
#include "115_Q3.h"
#include <stdlib.h>

int main(){
    int arr_size;
    int * a = calloc(arr_size, sizeof(int));

    printf("Enter Number of Elements : ");
    scanf("%d", &arr_size);

    printf("\nEnter Each Elements ... \n");
    for(int i = 0; i < arr_size; i++){
        printf("a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    int key;
    printf("\nEnter the Key to search for : ");
    scanf("%d", &key);

    int * idx = calloc(arr_size, sizeof(int)); //탐색 대상의 배열과 같은 크기의 공간 할당 ?

    int idx_size = search_idx(a, arr_size, key, idx);

    printf("The size of idx is : %d", idx_size);
    return 0;
}
