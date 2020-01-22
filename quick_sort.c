//
// Created by sarah on 1/22/2020.
//

#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{type tmp = x; x = y; y = tmp;} while(0)

void quick(int a[],int left, int right){

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

//while 문 두개를 탈출한 결과
// : a[pl] 과 a[pr] 은 pivot 을 기준으로 순서가 바뀌어 있다.

        if(pl <= pr){
            //만약 pl 이 "아직" pr 보다 작은 쪽에 위치해 있다면
            //즉, 인덱스 두 개가 교차하지 않은 상태라면

            swap(int, a[pl], a[pr]);
            pr--;
            pl++;

            //swap 하고 두 개의 인덱스를 안 쪽으로 한 칸 이동한다.
        }

    }while(pl <= pr);
    //바로 위에서 한 칸 더 이동한 결과 인덱스가 교차하지 않았는지 다시 확인한다.

    //재귀 호출 과정
    if(left < pr){
        quick(a, left, pr);
    }
    if(right > pl){
        quick(a, pl, right);
    }
}

int main(){

    int i, nx;
    int * x;

    puts("quick sort");

    printf("Num of Elements : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    for(i = 0; i < nx; i++){
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    quick(x, 0, nx - 1);

    puts("Sorting in Ascending order... ");

    for(i = 0; i < nx; i++){
        printf("x[%d] = %d\n", i, x[i]);
    }

    free(x);

    return 0;
}