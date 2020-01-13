//
// Created by sarah on 1/13/2020.
//

//버블정렬의 각 패스에서 비교, 교환은 처음부터 수행해도 됨. 각 패스에서
//가장 큰 값의 요소가 끝으로 옮겨짐. 그렇게 수정한 프로그램을 작성하라.

#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{ type tmp = x; x = y; y = tmp;} while(0)


//input : array & num of elements in the array.
int bubble_sort_from_front(int a [], int n){
   int k = n - 1; //a[k] 보다 뒤쪽의 요소는 정렬을 마친 상태

   while(k > 0){
       int last;
       for(int i = 0; i < k; i++){
           if(a[i] > a[i + 1]){
               swap(int, a[i], a[i+1]);
               last = i;
           }
       }
       k = last;
   }
}

int main(){

    int * a;
    int n;

    printf("Enter Num of Elements : ");
    scanf("%d", &n);

    a = calloc(n, sizeof(int));

    for(int i = 0; i< n; i++){
        printf("Enter a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    printf("Sorted Result \n");
    bubble_sort_from_front(a, n);

    for(int i = 0; i < n; i++){
        printf("a[%d] : %d \n", i, a[i]);
    }

    free(a);

    return 0;
}