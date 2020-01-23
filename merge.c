//
// Created by sarah on 1/23/2020.
//

#include <stdio.h>
#include <stdlib.h>

void merge(const int a[], int na, const int b[], int nb, int c[]){
    int pa = 0;
    int pb = 0;
    int pc = 0;

    while(pa < na && pb < nb){
        c[pc++] = (a[pa] <= b[pb]) ? a[pa++] : b[pb++];
    }

    //만약 배열 b가 배열 c로의 병합이 더 빨리 끝난 경우, a를 c에 순차적으로 넣는다.
    while(pa < na){
        c[pc++] = a[pa++];
    }

    //만약 배열 a가 배열 c로의 병합이 더 빨리 끝난 경우, b를 c에 순차적으로 넣는다.
    while(pb < na){
        c[pc++] = b[pb++];
    }

}

int main(){

    int i, na, nb;
    int *a, *b, *c;

    printf("Num of Elements in a : ");
    scanf("%d", &na);

    printf("Num of Elements in b : ");
    scanf("%d", &nb);

    a = calloc(na, sizeof(int));
    b = calloc(nb, sizeof(int));
    c = calloc(na + nb, sizeof(int));


    //배열 a 의 요소들을 정렬된 상태로 입력받는다.
    printf("a[0] : ");
    scanf("%d", &a[0]);
    for(i = 1; i < na; i++){
        do{
            printf("a[%d] : ", i);
            scanf("%d", &a[i]);
        }while(a[i] < a[i - 1]);
        //배열 a가 정렬된 상태로 입력되는 것을 보장하기 위해 위와같이
        //do ~ while(a[i] < a[i - 1]) 을 한다.
    }

    //배열 b 의 요소들을 정렬된 상태로 입력받는다.
    printf("b[0] : ");
    scanf("%d", &b[0]);
    for(i = 1; i < nb; i++){
        do{
            printf("b[%d] : ", i);
            scanf("%d", &b[i]);
        }while(b[i] < b[i - 1]);
    }


    //배열 a 와 b의 요소들을 병합하여 c에 저장한다.
    merge(a, na, b, nb, c);
    puts("array a and b is merged into array c");

    for(i = 0; i < na + nb; i++){
        printf("c[%2d] = %2d\n", i, c[i]);
    }

    free(a);
    free(b);
    free(c);

    return 0;
}