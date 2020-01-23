//
// Created by sarah on 1/23/2020.
//

//qsort 함수를 사용해 아래 두 배열을 오름차순으로 정렬하는 프로그램을 작성하라.
//정렬하는 부분의 코드는 각각 독립적인 함수로 구현하라.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COL 7

/*--- 문자열 배열(n1 × n2의 2차원 배열)을 오름차순으로 정렬 ---*/
void sort_2dstr(char *p, int n1, int n2)
{
    //4개의 요소가 있고, 각 요소의 사이즈는 7이다.
	qsort(p, n1, n2, (int(*)(const void *, const void *))strcmp);
}

/*--- x, y가 가리키는 문자열 비교 함수 ---*/
static int pstrcmp(const void *x, const void *y)
{
	return strcmp(*(const char **)x, *(const char **)y);
}

/*--- 문자열을 가리키는 p를 오름차순으로 정렬 ---*/
void sort_pvstr(char *p[], int n)
{
	qsort(p, n, sizeof(char *), pstrcmp);
}


void print_2d_arr(char arr[][COL], int m){
    int i, j;
    for(i = 0; i < m; i++){
        for(j = 0; j < COL; j++){
            printf("a[%d][%d] : %c \n", i, j, arr[i][j]);
        }
    }
}

void print_arr(char ** a, int m){
    for(int i = 0; i < m; i++){
        printf("%s\n", a[i]);
    }
}

int main(){

    char a[][7] = {
            "LISP",
            "C",
            "Ada",
            "Pascal"
    };

    char *p[] = {
            "LISP",
            "C",
            "Ada",
            "Pascal"
    };

//    sort_2dstr(a, 4, 7);
//    print_2d_arr(a, 4);

    sort_pvstr(p, 4);
    print_arr(p, 4);


    return 0;
}