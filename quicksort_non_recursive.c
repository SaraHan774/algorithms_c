//
// Created by sarah on 1/22/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"
#define swap(type, x, y) do{type tmp = x; x = y; y = tmp;} while(0)

void quick(int a[], int left, int right){

    IntStack lStack;//나눌 첫 요소 인덱스를 담는 스택
    IntStack rStack;//나눌 끝 요소 인덱스를 담는 스택

    Initialize(&lStack, right - left + 1);
    Initialize(&lStack, right - left + 1);
    //stack 을 생성한다.

    Push(&lStack, left);
    Push(&rStack, right); //인덱스를 알맞은 스택에 Push 한다.

    while(!IsEmpty(&lStack)){

        int pl = (Pop(&lStack, &left), left);
        int pr = (Pop(&rStack, &right), right);
        int x = a[(left + right)/2]; //pivot 은 가운데 요소

        do{
            while(a[pl] < x){
                pl++;
            }
            while(a[pr] > x){
                pr--;
            }

            if(pl <= pr){
                swap(int, a[pr], a[pl]);
                pl++;
                pr--;
            }

        }while(pl <= pr);

        if(left < pr){
            //왼쪽 그룹 범위의 인덱스를 Push 한다.
            Push(&lStack, left);
            Push(&rStack, pr);
        }

        if(pl < right){
            Push(&lStack, pl);
            Push(&rStack, right);
        }
    }

    Terminate(&lStack);
    Terminate(&rStack);

}