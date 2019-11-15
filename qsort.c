//
// Created by sarah on 11/15/2019.
//

#include <stdio.h>
#include <stdlib.h>

int compare(const void *first, const void *second);

int main(){
    int arr[] = {4, 3, 1, 5, 6, 7, 8, 10, 11};
    int arr_size = sizeof(arr)/ sizeof(int);
    int i;

    //before sort
    puts("Before sort\n");
    for(i = 0; i < arr_size; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n\n");

    //from stdlib.h
    qsort(arr, arr_size, sizeof(int), compare);

    //after sort
    puts("After sort\n");
    for(i = 0; i < arr_size; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");


    return 0;
}

/* prototype
 * void qsort(void *base, size_t num_el, size_t width, int(*compare)(const void *, const void *))
 * 1. 함수명 : qsort()
 * 2. 필요 헤더 : stdlib.h
 * 3. 리턴타입 : void
 * 4. 파라미터 :
 *      void * base : 정렬할 배열
 *      size_t num_el : 배열의 총 요소 개수
 *      size_t width : 배열 요소 한 개의 크기
 *      int (*compare) : 비교를 수행할 함수의 포인터
 *
 *      리턴값 : void
 *      함수 역할 : 퀵소트를 이용해 배열을 정렬한다.
 */

/* 0. Compare function 의 리턴값은 기본적으로 오름차순 정렬
 * 1. 리턴 값이 0보다 작을 경우 first < second (first - second < 0)
 * 2. 리턴 값이 0일 경우 first == second
 * 3. 리턴 값이 0보다 클 경우 first > second
 */
int compare(const void * first, const void *second){
    if(*(int *)first > *(int *)second){
        //return true if first int is larger
        return 1;
    }
    else if(*(int *)first < *(int *)second){
        //return -1 if second is larger
        return -1;
    }
    else{
        return 0;
    }
}