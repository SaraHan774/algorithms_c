//
// Created by sarah on 1/5/2020.
//

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)

void bubble_sort_improved_2(int a[], int n){
    //remember where the last comparison happened
    //get rid of meaningless comparison in a pass.

    int k = 0;
    int count = 0;

    while(k < n - 1) {
        int j;
        int last = n - 1;

        for (j = n - 1; j > k; j--) {
            //during the pass - compare & exchange.
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
                last = j;
            }
        }
        k = last;
        count++;
    }
    printf("number of pass %d \n", count);
}

int main(){
    int i, nx;
    int *x; //array declaration

    puts("Bubble Sort Improved 2 ");
    printf("Number of elements : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    //entering the elements of the array x
    for(i = 0; i < nx; i++){
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }


    bubble_sort_improved_2(x, nx); //do a bubble sort on array x with nx elements

    puts("sorted in ascending order. ");

    for(i = 0; i < nx; i++){
        //print the elements in the array.
        printf("x[%d] = %d \n", i, x[i]);
    }

    //free the array
    free(x);

    return 0;
}