//
// Created by sarah on 1/20/2020.
//

#include <stdio.h>
#include <stdlib.h>

void insertion(int a[], int n){

    int i, j;

    for(i = 1; i < n; i++){
        //삽입 정렬은 두번째 요소부터 비교를 시작한다.
        int tmp = a[i];
        //비교 기준이 되는 숫자를 tmp 에 저장한다.
        for(j = i - 1; j > 0 && a[j-1] > tmp; j--){
            //a[i] 보다 앞의 요소부터 비교를 시작한다
            //j > 0 보다 커야만 하며,
            //a[j-1]가 tmp보다 작거나 같으면 비교가 중단된다.
            a[j] = a[j-1];
        }
        a[j] = tmp;
    }
}

int main(){
    int i , nx;
    int * x;
    puts("Straight Insertion Sort");

    printf("Num of Elements : " );
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for(i = 0; i < nx; i++){
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    insertion(x, nx);

    puts("Sorted in Ascending order");
    for(i = 0; i < nx; i++){
        printf("x[%d] = %d\n", i, x[i]);
    }

    free(x);

    return 0;
}