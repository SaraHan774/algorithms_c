//
// Created by sarah on 2/2/2020.
//

#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_ENTRIES 3
#define swap(type, x, y)do{type tmp = x; x = y; y = tmp;} while(0)

static void downheap(int a[], int left, int right){

    int temp = a[left];
    int child;
    int parent;

    for(parent = left; parent < (right + 1)/2; parent = child){
        int cl = parent * 2 + 1;
        int cr = cl + 1;
        child = (cr <= right && a[cr] > a[cl]) ? cr : cl;

        if(temp >= a[child]){
            break;
        }
        a[parent] = a[child];
    }
    a[parent] = temp;
}

void heapsort(int a[], int n){
    int i;
    for(i = (n-1)/2; i >=0; i--){
        downheap(a, i, n-1);
    }
    for(i = n-1; i > 0; i--){
        swap(int, a[0], a[i]);
        downheap(a, 0, i-1);
    }
}

int main (){

    //시도 1 : Heap 을 복습할 겸 사용해 보았다 ...
//    int a, b, c;
//    int * arr;
//    scanf("%d %d %d", &a, &b, &c);
//
//    arr = malloc(sizeof(int) * NUM_OF_ENTRIES);
//
//    arr[0] = a;
//    arr[1] = b;
//    arr[2] = c;
//
//    heapsort(arr, NUM_OF_ENTRIES);
//
//    for(int i = 0; i < NUM_OF_ENTRIES; i++){
//        printf("%d ", arr[i]);
//    }

    //시도 2 : 다른 사람의 코드
//    int A[NUM_OF_ENTRIES];
//    int i, j, tmp;
//
//    for(i = 0; i < NUM_OF_ENTRIES; i++){
//        //이렇게 순차적으로 받아도 되는구나 !
//        scanf("%d", &A[i]);
//    }
//
//
//    for(j = 0; j < NUM_OF_ENTRIES - 1; j++){
//        if(A[j] > A[j + 1]){
//            swap(int, A[j], A[j+1]);
//        }
//    }
//
//    for(int i = 0; i < NUM_OF_ENTRIES; i++){
//        printf("%d", A[i]);
//    }



    //시도 3 : 오른쪽 숫자와 왼쪽 숫자 비교
    int a[3], i, j, m;

    for(i = 0; i < 3; i++){
        scanf("%d", &a[i]);
    }

    for(i = 0; i < 2; i++){

        for(j = i + 1; j < 3; j++){

            if(a[i] > a[j]){
                m =  a[i];
                a[i] = a[j];
                a[j] = m;
            }
        }
    }

    printf("%d %d %d\n", a[0], a[1], a[2]);

    return 0;
}