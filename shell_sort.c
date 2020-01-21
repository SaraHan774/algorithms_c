//
// Created by sarah on 1/21/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "testing.h"
#include <time.h>

void print_array(int a [], int n){
    for(int i = 0; i < n; i++){
        printf("a[%d] : %d\n", i, a[i]);
    }
}

int shell_sort(int a[], int n){

    //배열 간격 h 만큼
    int h, j, i;
    //배열 간격 h가 n/2 에서 1이 될때까지 수행
    for(h = n/2; h > 0; h /= 2){
        //Loop 1 : 배열의 간격을 줄여나간다.
        for(i = h; i < n; i++){
            //Loop 2 : 간격을 사이에 두고 한칸씩 이동하며 tmp 를 정한다.
            int tmp = a[i];
            for(j = i - h; j >= 0 && a[j] > tmp; j-= h){
                //Loop 3 : 배열 자리를 옮긴다
                a[j+h] = a[j];
            }
            a[j + h] = tmp;
        }
    }
}

int shell_more_efficient(int a[], int n){

    int i, j, h;
    for(h = 1; h < n/9; h = h * 3 + 1)
        ;
    //h의 초기값을 구한다. 1부터 시작해 값을 3배하고 1을 더하면서
    // n/9를 넘지 않는 가장 큰 값을 h에 대입한다.

    for(; h > 0; h /= 3){
        // h의 값을 3으로 나누며 값을 변화시킨다.

        for(i = h; i < n; i++){
            int tmp = a[i];
//            printf("tmp = %d\n", a[i]);
            for(j = i - h; j >=0 && a[j] > tmp; j-= h){
                a[j + h] = a[j];
            }
            a[j + h] = tmp;
        }

    }

}

int main(){

    int * a;
    int n = 100000;
    clock_t start, end;
    double cpu_time_used;

    //generate_int(100000, "C://Users/sarah/CLionProjects/algorithms_c/random_int_100000.txt");

    FILE * fp = fopen("./random_int_100000.txt", "r");

    a = calloc(n, sizeof(int));

    for(int i = 0; i < n; i++){
        fscanf(fp, "%d", &a[i]);
    }


    //10_000 개 인풋으로 측정해본 알고리즘 시간 비교
    start = clock();
    //shell_more_efficient(a, n); //CPU TIME USED : 0.003000
    shell_sort(a, n); //CPU TIME USED : 0.005000
    end = clock();


    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("CPU TIME USED : %lf", cpu_time_used);

//    for(int i = 0; i < n; i++){
//        printf("a[%d] : %d\n", i, a[i]);
//    }

    free(a);

    return 0;
}