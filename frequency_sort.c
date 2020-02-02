//
// Created by sarah on 2/2/2020.
//

#include <stdio.h>
#include <stdlib.h>

void fsort(int a[], int n, int max){
    //도수 정렬 함수. 배열의 요소값은 0이상 max 이하이다.
    int i;
    int * f = calloc(max + 1, sizeof(int)); //도수 분포표를 만들 배열
    int * b = calloc(n, sizeof(int)); //정렬 결과를 담을 보조 배열


    puts("Frequency Array");

    int arr_max = a[0]; //도수 분포를 출력하기 위해 배열의 최대값 찾기

    for(i = 0; i < n; i++){
        if(arr_max < a[i]){
            arr_max = a[i];
        }
        f[a[i]]++; //a[i] 가 나타나는 빈도수만큼 배열 f에 저장된다.
    }

    for(int j = 0; j < arr_max; j++){
        //도수 분포를 출력한다.
        printf("f[%d] : %d \n", j, f[j]);
    }

    puts("Accumulated Frequency Array");
    for(i = 1; i <= arr_max; i++){
        f[i] += f[i-1]; //누적 도수 분포를 만드는 작업
        printf("f[%d] : %d \n", i, f[i]);
    }

    puts("Sorting from Accumulated Frequency Array");
    for(i = n-1; i >= 0; i--){
        b[--f[a[i]]] = a[i]; //정렬을 위한 작업
    }

    for(int j = 0; j < n; j++){
        printf("b[%d] : %d \n", j, b[j]);
    }

    for(i = 0; i < n; i++){
        a[i] = b[i]; //정렬 결과를 다시 a에 담는다.
        printf("a[%d] : %d, b[%d] : %d \n", i, a[i], i, b[i]);
    }

    free(b);
    free(f);
}

int main(){

    int i, nx;
    int * x;
    const int max = 100;

    printf("Enter num of elements : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    printf("Enter numbers from 0 ~ %d : \n", max);

    for(i = 0; i < nx; i++){
        do{
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        }while(x[i] < 0 || x[i] > max);
    }

    fsort(x, nx, max);
    puts("Sorted in ascending order ... ");

    for(i = 0; i < nx; i++){
        printf("x[%d] : %d \n", i, x[i]);
    }

    free(x);

    return 0;
}