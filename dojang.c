//
// Created by sarah on 1/27/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int ** countNearby(char ** matrix, int m, int n){


    int ** ret_matrix = malloc(sizeof(int*) * m);
    for(int k = 0; k < m; k++){
        ret_matrix[k] = calloc(n, sizeof(int));
    }

    for(int i = 0; i < m; i++){

        for(int j = 0; j < n; j++){


            if(matrix[i][j] == '*'){

                ret_matrix[i][j] = -1;

                if(i <= m-1 && j <= n-1 && matrix[i+1][j+1] != '*'){
                    ret_matrix[i+1][j+1]++;
                }
                if(i >= 1 && j >= 1 && matrix[i-1][j-1] != '*'){
                    ret_matrix[i-1][j-1]++;
                }
                if(i <= m-1 && matrix[i+1][j] != '*'){
                    ret_matrix[i+1][j]++;
                }
                if(j <= n-1 && matrix[i][j+1] != '*'){
                    ret_matrix[i][j+1]++;
                }
                if(i >= 1 && matrix[i-1][j] != '*'){
                    ret_matrix[i-1][j]++;
                }
                if(j >= 1 && matrix[i][j-1] != '*'){
                    ret_matrix[i][j-1]++;
                }
                if(i >= 1 && j <= n - 1 && matrix[i-1][j+1] != '*'){
                    ret_matrix[i-1][j+1]++;
                }
                if(i <= m-1 && j >= 1 && matrix[i+1][j-1] != '*'){
                    ret_matrix[i+1][j-1]++;
                }
            }
        }
    }

    return ret_matrix;
}

int main(){

    //TODO(1) : Shift 연산 사용하기
//    int decimal = 0;
//    int binary[4] = {1, 1, 0 ,1};
//
//    int position = 0;
//
//    for(int i = sizeof(binary)/ sizeof(int) - 1; i >=0 ; i--){
//        if(binary[i] == 1){
//            decimal += 1 << position;
//            printf("%d \n", decimal);
//        }
//
//        position++;
//    }
//
//    printf("%d\n", decimal);


    //TODO(2) : 전치 행렬 출력하기
//    int matrix[5][5] = {
//            {1, 2, 3, 4, 5},
//            {6, 7, 8, 9, 10},
//            {11, 12, 13, 14, 15},
//            {16, 17, 18, 19, 20},
//            {21, 22, 23, 24, 25}
//    };
//
//    int col = sizeof(matrix[0])/sizeof(int);
//    int row = sizeof(matrix)/sizeof(matrix[0]);
//    int i, j;
//    for(i = 0; i < row; i++){
//
//        for(j = 0; j < col; j++){
//            printf("%d ", matrix[j][i]);
//        }
//        printf("\n");
//    }

    //TODO(3) : 포인터에 할당된 메모리를 2차원 배열처럼 사용하기
//    int **m = malloc(sizeof(int *) * 3); //배열의 세로
//
//    for(int i = 0; i < 3; i++){
//        //세로 크기만큼 반복
//        m[i] = malloc(sizeof(int) * 4); //배열의 가로
//    }
//
//    m[0][0] = 1;
//    m[2][0] = 5;
//    m[2][3] = 2;
//
//    printf("%d\n", m[0][0]);
//    printf("%d\n", m[2][0]);
//    printf("%d\n", m[2][3]);
//
//    for(int i = 0; i < 3; i++){
//        //세로 크기만큼 반복
//        free(m[i]); //2차원 배열의 가로 공간 메모리 해제
//    }
//    free(m); //2차원 배열의 세로 공간 메모리 해제



    //연습문제 38.6
    //높이 2, 세로 3, 가로 5 3차원 배열
//    long long ***m = malloc(sizeof(long long **) * 2);
//
//    for(int depth = 0; depth < 2; depth++){
//        m[depth] = malloc(sizeof(long long *) * 3);
//
//        for(int row = 0; row < 3; row++){
//            m[depth][row] = malloc(sizeof(long long) * 5);
//        }
//    }
//
//    m[1][2][4] = 100;
//
//    printf("%lld\n", m[1][2][4]);
//
//    for(int depth = 0; depth < 2; depth++){
//
//        for(int row = 0; row < 3; row++){
//            free(m[depth][row]);
//        }
//
//        free(m[depth]);
//    }
//    free(m);

    //정사각행렬 크기 입력 -> 입력 크기만큼 단위행렬 출력하기
    //단위행렬 : 주대각선 모두 1, 나머지는 0

//    int num;
//    scanf("%d", &num);
//
//    for(int i = 0; i < num; i++){
//
//        for(int j = 0; j < num; j++){
//            if(i == j){
//                printf("1 ");
//            }else{
//                printf("0 ");
//            }
//        }
//
//        printf("\n");
//    }
//
//      //방법 2 : 동적 할당된 2차원 배열 사용하기.
//    int **matrix = malloc(sizeof(int *) * num);
//    for(int i = 0; i < num; i++){
//        matrix = malloc(sizeof(int) * num);
//        memset(matrix[i], 0, sizeof(int) * num);
//    }
//
//    for(int i = 0; i < num; i++){
//        matrix[i][i] = 1;
//    }
//
//    for(int i = 0; i < num; i++) {
//        for (int j = 0; j < num; j++) {
//            printf("%d ", matrix[i][j]);
//        }
//        printf("\n");
//    }
//    free(matrix);


    int m, n;
    //행렬의 크기 입력받기 m x n 행렬
    scanf("%d", &m);
    scanf("%d", &n);

    char **matrix = malloc(sizeof(char *) *m);
    for(int i = 0; i < n; i++){
        matrix[i] = malloc(sizeof(char) * (n+1));
    }
    //행렬의 가로 공간에는 문자열이 들어감. 따라서 가로크기 + 1만큼 할당해야.

    // * 은 지뢰이고 . 은 지뢰가 아니다. 지뢰가 아닌 요소에는
    //인접한 지뢰의 개수를 출력하는 프로그램을 만들어라.
    for(int i = 0; i < m; i++){
        scanf("%s", matrix[i]);
    }

    int ** ret_matrix;
    ret_matrix = countNearby(matrix, m, n);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(ret_matrix[i][j] == -1){
                printf("%c ", matrix[i][j]);
            }
            else{
                printf("%d ", ret_matrix[i][j]);
            }
        }
        printf("\n");
    }

    for(int i = 0; i < m; i++){
        free(ret_matrix[i]);
        free(matrix[i]);
    }
    free(ret_matrix);
    free(matrix);

    return 0;
}