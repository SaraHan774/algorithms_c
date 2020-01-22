//
// Created by sarah on 1/22/2020.
//

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{ type tmp = x; x = y; y = tmp;} while(0)

//배열을 나누는 함수
void partition(int a[], int n){
    //pivot 이상의 그룹과 이하의 그룹으로 나누는 프로그램

    int pivot = n/2;
    int pl = 0;
    int pr = n - 1;

    do{
        while(a[pl] < a[pivot]){
            pl++;
        }
        while(a[pr] > a[pivot]){
            pr--;
        }

        if(pl <= pr){
            swap(int, a[pr], a[pl]);
            pl++;
            pr--;
        }

        //인덱스가 서로 교차하지 않을 동안
    }while(pl <= pr);


    for(int i = 0; i < n; i++){
        if(i == pivot){
            printf("(PIVOT) a[%d] : %d \n", i, a[i]);
        }else{
            printf("a[%d] : %d \n", i, a[i]);
        }
    }
}

int main(){

    int * a;
    int n;

    printf("Enter Num of Elements : ");
    scanf("%d", &n);
    a = calloc(n, sizeof(int));

    for(int i = 0; i < n; i++){
        printf("a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    partition(a, n);


    return 0;
}