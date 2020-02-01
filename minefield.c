//
// Created by sarah on 1/27/2020.
//

#include <stdio.h>
#include <stdlib.h>
#define DELTA 8

int main(){

    int dx []= {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy [] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int m, n;
    int row_size = m;
    int col_size = n;
    //행렬의 크기 입력받기 m x n 행렬
    scanf("%d", &m);
    scanf("%d", &n);


    char **matrix = malloc(sizeof(char *) *m);
    for(int i = 0; i < m; i++){
        matrix[i] = malloc(sizeof(char) * (n+1));
    }
    //행렬의 가로 공간에는 문자열이 들어감. 따라서 가로크기 + 1만큼 할당해야.

    // * 은 지뢰이고 . 은 지뢰가 아니다. 지뢰가 아닌 요소에는
    //인접한 지뢰의 개수를 출력하는 프로그램을 만들어라.
    for(int i = 0; i < m; i++){
        scanf("%s", matrix[i]);
    }


    int ** ret_matrix = malloc(sizeof(int*) * m);
    for(int k = 0; k < m; k++){
        ret_matrix[k] = calloc(n, sizeof(int));
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){

            if(matrix[i][j] == '*'){
                ret_matrix[i][j] = -1;

                //시도 2
                for(int k = 0; k < DELTA; k++){

                    printf("DEBUG : dx[%d] = %d, dy[%d] = %d \n", k, dx[k], k, dy[k]);
                    printf("DEBUG : i = %d, j = %d\n", i, j);

                    if((i + dx[k] > row_size || i + dx[k] < 0) || (j + dy[k] > col_size || j + dy[k] < 0)){
                        continue;
                    }

                    if(matrix[i + dx[k]][j + dy[k]] != '*'){
                        puts("DEBUG : ret_matrix++");
                        ret_matrix[i + dx[k]][j + dy[k]]++;
                    }
                }

                //시도 1 :
//                if(i <= m-1 && j <= n-1 && matrix[i+1][j+1] != '*'){
//                    ret_matrix[i+1][j+1]++;
//                }
//                if(i >= 1 && j >= 1 && matrix[i-1][j-1] != '*'){
//                    ret_matrix[i-1][j-1]++;
//                }
//                if(i <= m-1 && matrix[i+1][j] != '*'){
//                    ret_matrix[i+1][j]++;
//                }
//                if(j <= n-1 && matrix[i][j+1] != '*'){
//                    ret_matrix[i][j+1]++;
//                }
//                if(i >= 1 && matrix[i-1][j] != '*'){
//                    ret_matrix[i-1][j]++;
//                }
//                if(j >= 1 && matrix[i][j-1] != '*'){
//                    ret_matrix[i][j-1]++;
//                }
//                if(i >= 1 && j <= n - 1 && matrix[i-1][j+1] != '*'){
//                    ret_matrix[i-1][j+1]++;
//                }
//                if(i <= m-1 && j >= 1 && matrix[i+1][j-1] != '*'){
//                    ret_matrix[i+1][j-1]++;
//                }
            }
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(ret_matrix[i][j] == -1){
                printf("%c", matrix[i][j]);
            }
            else{
                printf("%d", ret_matrix[i][j]);
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