//
// Created by sarah on 1/21/2020.
//

//Shell Sort : 요소 이동 횟수를 계산할 수 있도록 버전1과 버전2를 수정하라.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Naive 한 버전
//gap 을 n/2에서 시작하여 2로 나누어 가는 방식으로 조절한다.

void shell_version_1(int a[], int n){
    //gap 을 2로 나누어 가며 한다.

    int i, j, h;
    int count = 0;

    for(h = n/2; h > 0; h /= 2){
        for(i = h; i < n; i++){
            int tmp = a[i];
            for(j = i - h; j >= 0 && a[j] > tmp; j-= h){
                a[j + h] = a[j];
                count++;
            }
            a[j + h] = tmp;
        }
    }
    printf("(VERSION 1) Number of Element Insertions : %d \n", count);
}


//h = ..., 121, 40, 13, 4, 1 일때 h값이 서로 배수가 되지 않고,
//요소가 충분히 섞여 효율적인 정렬을 기대할 수 있다.
//또한 h의 초기값은 너무 크면 효과가 없기 때문에 배열의 요소 개수를 9로 나눈 값을
//넘지 않도록 정해야 한다.

void shell_version_2(int a[], int n){
    int i, j, h;
    int count = 0;

    for(h = 1; h < n/9; h = 3*h + 1);
    //h의 초기값을 구한다.

    //구한 h값을 이용해 Shell 정렬을 수행한다.
    //h를 3으로 나눠가면서 gap 을 줄인다.
    for(; h > 0; h /= 3) {
        for (i = h; i < n; i++) {
            int tmp = a[i];

            for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
                //왼쪽의 요소가 오른쪽의 요소(tmp) 보다 큰 경우 for 문을 만족
                a[j + h] = a[j];
                //a[i]의 자리에다가 a[j] 를 삽입한다.
                //a[i] 는 a[j]에서 gap 인 h만큼 떨어진 곳에 있는 숫자. (즉 a[j + h] 와 같다.)
                count++;
                //j를 h만큼 감소시키면서 j >=0 과 a[j] > tmp 를 만족하지 않을 때 까지 반복
            }
            a[j + h] = tmp;
        }
    }

    printf("(VERSION 2) Number of Element Insertions : %d \n", count);
}

int main(){

    int * a;
    int n = 1000;
    clock_t start, end;
    double cpu_time_used;

    FILE * fp = fopen("./random_int_1000.txt", "r");

    a = calloc(n, sizeof(int));

    for(int i = 0; i < n; i++){
        fscanf(fp, "%d", &a[i]);
    }


    start = clock();
    //shell_version_1(a, n); //(VERSION 1) Number of Element Insertions : 7619
    shell_version_2(a, n); //(VERSION 2) Number of Element Insertions : 9039
    end = clock();


    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("CPU TIME USED : %lf", cpu_time_used);

    free(a);

    return 0;
}

