//
// Created by sarah on 1/14/2020.
//

#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y)do{type t = x; x = y; y = t;} while(0)

void bidirection_bubble_sort(int a [], int n){

    int pass = 0;
    int k = 0;
    int count = 0;
    while(pass < n-1){
        int last = 0;

        if(pass % 2 == 0){
            for(int j = 0; j < (n - 1) - k; j++){
                if(a[j] > a[j + 1]){
                    swap(int, a[j], a[j + 1]);
                    count++;
                }
                last = j;
            }
            pass++;
        }else{
            for(int j = n - 1; j > k; j--){
                if(a[j] < a[j - 1]){
                    swap(int, a[j], a[j - 1]);
                    count++;
                }
                last = j;
            }
            pass++;
        }
        k = last;

        printf("pass : %d \n", pass);
        printf("k : %d \n", k);
    }

    printf("count : %d ", count);
}

int main(){

    int * a;
    int n;

    printf("Enter num of elements : ");
    scanf("%d", &n);

    a = calloc(n, sizeof(int));

    for(int i = 0; i < n; i++){
        printf("Enter a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    printf("Bidirection bubble sort result : \n");
    bidirection_bubble_sort(a, n);

    for(int i = 0; i < n; i++){
        printf("Element a[%d] : %d \n", i, a[i]);
    }

    free(a);

    return 0;
}

