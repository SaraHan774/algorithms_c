//
// Created by sarah on 1/13/2020.
//

//비교 교환 과정을 출력하며 버블 정렬하는 프로그램을 작성하시오.
//교환을 수행하면 +, 수행하지 않으면 -, 정렬을 마치면 비교&교환 횟수 출력하라.

#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)


int print_array(const int * a, int n, int is_swapped, int current_pos){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
        if(i == current_pos){
            if(is_swapped == 1){
                printf("+ ");
            }else if(is_swapped == 0){
                printf("- ");
            }
        }
    }
    printf("\n");
}

//input : int array & num of elements in the array.
int print_bubble_sort(int a [], int n){
    int current_pos = 0;
    int count_comp = 0;
    int count_swap = 0;
    int is_swapped = 0;

    for(int i = 0; i < n - 1; i++){

        printf("Pass %d \n", i + 1);

        for(int j = 0; j < (n - 1) - i; j++){

            if(a[j] > a[j + 1]){
                swap(int, a[j], a[j + 1]);
                count_swap++;
                is_swapped = 1;
            }else{
                is_swapped = 0;
            }
            count_comp++;
            current_pos = j;

            print_array(a, n, is_swapped, current_pos);
        }
    }

    printf("Comparison Count : %d\n", count_comp);
    printf("Swap Count : %d \n", count_swap);
}


int main(){

    int * a;
    int n;

    printf("Enter Num of Elements : ");
    scanf("%d", &n);

    a = calloc(n, sizeof(int));

    for(int i = 0; i < n; i++){
        printf("Enter a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    printf("Sorted Result : \n");
    print_bubble_sort(a, n);

    free(a);

    return 0;
}