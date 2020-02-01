//
// Created by sarah on 1/28/2020.
//

#include <stdio.h>
#include <stdlib.h>

static int * buff; //작업용 배열

static void __mergesort(int a[], int left, int right){

    if(left < right){
        int center = (left + right) / 2;

        int pointer = 0;
        int i;
        int j = 0; //buffer 의 포인터 용도
        int k = left;

        __mergesort(a, left, center);
        __mergesort(a, center + 1, right);

        for(i = left; i < center; i++){
            buff[pointer++] = a[i]; //왼쪽부터 센터까지의 요소들을 버퍼에 넣는다.
        }

        //pointer 와 i는 center - 1 에 와 있을 것이다.
        while(i <= right && j < pointer){
            //a의 왼쪽부터 센터까지를 버퍼에 담고, a의 나머지 뒷부분을 버퍼와 비교하며
            //다시 배열 a[left] 에 요소들을 담아나간다.
            a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
        }

        //만약 버퍼에 담긴 a 의 앞부분이 a의 뒷부분보다 더 길다면
        //위의 while 문을 빠져나와도 병합이 끝나지 않았을 것이다.
        while(j < pointer){
            a[k++] = buff[j++];
        }
    }
}