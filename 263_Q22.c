//
// Created by sarah on 2/1/2020.
//

//263페이지 문제 22번
//down_heap 함수가 호출될 때마다 배열의 값을 트리 형식으로 출력하는 프로그램을 작성하라.


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int ** tree;
    int arr [] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n; //number of elements

    printf("Enter num of elements : ");
    scanf("%d", &n);


    int height = (int)(log(n)/log(2)); //밑이 2인 로그 구하기

    printf("%d\n", height);

    int row = height + 1;
    int col = (int)(pow(2, row) - 1);

    printf("Column : %d \n", col);

    //make a 2D array of row x col
    tree = calloc(row, sizeof(int *));
    for(int i = 0; i < row; i++){
        tree[i] = calloc(col, sizeof(int));
    }



    //printing tree
//    int row_idx = 0, arr_idx = 0;
//
//    int m = col;
//    int c = col/2;
//
//    int arr_size = sizeof(arr)/ sizeof(int);
//    while(row_idx < row){
//        tree[row_idx][c/m] = arr[arr_idx++];
//
//        //arr_idx = 2 -> 3 일때 줄 바꿔야
//        if(arr_idx == pow(2, row_idx)){
//            m = col/(row_idx + 1);
//            row_idx++;
//        }
//    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", tree[i][j]);
        }
        printf("\n");
    }


    for(int i = 0; i < row; i++){
        free(tree[i]);
    }
    free(tree);

    return 0;
}