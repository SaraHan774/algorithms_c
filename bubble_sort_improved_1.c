//
// Created by sarah on 1/5/2020.
//

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)

void bubble_sort_improved_1(int a[], int n){
    //if no exchange happens in a pass, then break.

    int i, j, exchange;

    for(i = 0; i < n-1; i++){
        exchange = 0;
        for(j = n - 1; j > i; j--){
            //during the pass - compare & exchange.
            if(a[j-1] > a[j]){
                swap(int, a[j-1], a[j]);
                exchange++;
            }
        }
        //end of a pass
        if(exchange == 0){
            break;
        }
    }

    printf("Total number of passes : %d \n", i);
    //less number of passes compared to naive bubble sort.
}

int main(){
    int i, nx;
    int *x; //array declaration

    puts("Bubble Sort Improved 1 ");
    printf("Number of elements : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    //entering the elements of the array x
    for(i = 0; i < nx; i++){
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }


    bubble_sort_improved_1(x, nx); //do a bubble sort on array x with nx elements

    puts("sorted in ascending order. ");

    for(i = 0; i < nx; i++){
        //print the elements in the array.
        printf("x[%d] = %d \n", i, x[i]);
    }

    //free the array
    free(x);

    return 0;
}