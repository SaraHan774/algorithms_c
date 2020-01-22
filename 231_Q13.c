//
// Created by sarah on 1/22/2020.
//

#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{type tmp = x; x = y; y = tmp;} while(0)

void quick(int a[], int left, int right){

    int pl = left;
    int pr = right;
    int pivot = a[(pl + pr)/2];

    do{
        while(a[pl] < pivot){
            pl++;
        }
        while(a[pr] > pivot){
            pr--;
        }

        printf("left : %d - right : %d \n", a[left], a[right]);

        if(pl <= pr){
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
        }

    }while(pl <= pr);

    if(left < pr){
        quick(a, left, pr);
    }

    if(right > pl){
        quick(a, pl, right);
    }

}

//무슨 의도로 이런 문제를 낸건지 잘 모르겠음.
int quick_sort(int a[], int n){
    quick(a, 0, n - 1);
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

    quick_sort(a, n);

    for(int i = 0; i < n; i++){
        printf("a[%d] : %d", i, a[i]);
    }


    free(a);
}
