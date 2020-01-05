//
// Created by sarah on 1/5/2020.
//

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{ type t = x; x = y; y = t; } while(0)

void bubble(int a[], int n){
    int i, j;
    // i = number of pass
    // j = index for finding min from the end of the array
    for(i = 0; i < n -1; i++){
        for(j = n - 1; j > i; j--){
            //from end of the array
            if(a[j-1] > a[j]){
                //if left is larger than right, then swap.
                swap(int, a[j-1], a[j]);
            }
        }
    }
    printf("Total number of passes : %d \n", i);
}

int main(){

    int i, nx;
    int *x; //array declaration

    puts("Bubble Sort");
    printf("Number of elements : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    //entering the elements of the array x
    for(i = 0; i < nx; i++){
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }


    bubble(x, nx); //do a bubble sort on array x with nx elements

    puts("sorted in ascending order. ");

    for(i = 0; i < nx; i++){
        //print the elements in the array.
        printf("x[%d] = %d \n", i, x[i]);
    }

    //free the array
    free(x);

    return 0;
}