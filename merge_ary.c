//
// Created by sarah on 1/28/2020.
//

#include <stdio.h>
#include <stdlib.h>

void merge(const int a[], int na, const int b [], int nb, int c[]){
    //세 개의 반복문을 늘어놓는 단순한 알고리즘.
    //병합에 필요한 시간 복잡도는 O(n)이다.
    int pa = 0;
    int pb = 0;
    int pc = 0;

    while(pa < na && pb < nb){
        //c 배열에 들어갈 값은 a와 b 의 요소 중 작은 것,
        //배열에 넣은 후 각 배열의 포인터들을 증가시킨다.
        c[pc++] = (a[pa] <= b[pb]) ? a[pa++] : b[pb++];
    }

    while(pa < na){
        //만약 a가 더 길다면 남아있는 a의 요소들을 c에 넣는다.
        c[pa++] = a[pa++];
    }

    while(pb < nb){
        c[pc++] = b[pb++];
    }
/*
 * 정렬을 마친 배열의 병합을 응용해 분할 정복법에 따라 정렬하는 알고리즘을 병합 정렬이라 한다.
 * */
}

int main(){

    int i, na, nb;
    int *a, *b, *c;

    printf("Num of elements in a : "); scanf("%d", &na);
    printf("Num of elements in b : "); scanf("%d", &nb);

    a = calloc(na, sizeof(int));
    b = calloc(nb, sizeof(int));
    c = calloc( na + nb, sizeof(int));


    //오름차순으로 값을 입력받는다.
    printf("a[0] : ");
    scanf("%d", &a[0]);
    for(i = 0; i < na; i++){
        do{
            printf("a[%d] : ", i);
            scanf("%d", &a[i]);
        }while(a[i] < a[i-1]);
    }

    printf("b[0] : ");
    scanf("%d", &b[0]);
    for(i = 0; i < nb; i++){
        do{
            printf("b[%d] : ", i);
            scanf("%d", &b[i]);
        }while(b[i] < b[i-1]);
    }


    //배열 a 와 b를 병합하여 c에 저장한다.
    merge(a, na, b, nb, c);

    puts("Merged a and b into c ... ");

    for(i = 0; i < na + nb; i++){
        printf("c[%2d] : %d \n", i, c[i]);
    }

    free(a);
    free(b);
    free(c);

    return 0;
}