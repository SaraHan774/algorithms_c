//
// Created by sarah on 1/23/2020.
//

#include <stdio.h>
#include <stdlib.h>

static int * buff; //작업용 배열

static void __mergesort(int a[], int left, int right){
    if(left < right){
        int center = (left + right)/2;
        int p = 0;
        int i;
        int j = 0; //버퍼의 커서
        int k = left; //배열 a의 커서
        __mergesort(a, left, center); //앞부분에 대한 병합 정렬
        __mergesort(a, center + 1, right); //뒷부분에 대한 병합 정렬

        for(i = left; i <= center; i++){
            //왼쪽부터 center 까지 a의 값들을 buff에 복사한다.
            buff[p++] = a[i];
        }

        //i는 left 의 첫 요소 인덱스
        while(i <= right && j < p){
            //배열의 뒷부분 a[center + 1] ~ a[right] 와 buff로 복사한 배열의 앞부분 p개를 병합한 결과를
            //배열 a에 저장한다.
            a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
        }

        while(j < p){
            //buff 에 남아있는 요소를 배열 a로 복사한다.
            a[k++] = buff[j++];
        }
    }
}

int mergesort(int a[], int n){
    //최초로 배열을 나눌 때 이 함수로 __mergesort 를 호출함.
    buff = calloc(n, sizeof(int));
    if(buff == NULL){
        return -1;
    }
    __mergesort(a, 0, n-1);
    free(buff);
    return 0;
}