//
// Created by sarah on 1/23/2020.
//

#include <stdio.h>
#include <stdlib.h>

//int형 비교함수 (오름차순 정렬에 사용)
int int_comp_asc(const int * a, const int * b){

    if(*a < *b){
        return -1;
    }else if(*a > *b){
        return 1;
    }else{
        return 0;
    }
}

//내림차순일 경우엔 리턴 값을 다르게 해야한다.
int int_comp_desc(const int * a, const int * b){

    if(*a < *b){
        //-1 에서 1로 리턴값을 바꾸었다.
        return 1;
    }else if(*a > *b){
        //1 에서 -1로 리턴값을 바꾸었다.
        return -1;
    }else{
        return 0;
    }
}



int main(){
    int * array;
    int num, i;

    puts("using qsort()");

    printf("Enter Num of Elements : ");
    scanf("%d", &num);

    array = calloc(num, sizeof(int));

    for(i = 0; i < num; i++){
        printf("Enter array[%d] : ", i);
        scanf("%d", &array[i]);
    }

    qsort(array, num, sizeof(int), (int (*)(const void *, const void *)) int_comp_asc);
    puts("Sorted in Ascending order ");

    for(i = 0; i < num; i++){
        printf("array[%d] : %d\n", i, array[i]);
    }

    qsort(array, num, sizeof(int), (int (*)(const void *, const void *)) int_comp_desc);
    puts("Sorted in Descending order ");

    for(i = 0; i < num; i++){
        printf("array[%d] : %d\n", i, array[i]);
    }


    free(array);

    return 0;
}