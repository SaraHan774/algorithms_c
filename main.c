#include <stdio.h>
#include <stdlib.h>
#include "bin_search.h"
#include "search_sen.h"

int main() {

    int i, nx, ky, idx;
    int *x; //배열의 첫번째 요소에 대한 포인터

    puts("Binary Search");
    printf("Number of elements : ");
    scanf("%d", &nx); //요소의 개수를 정한다

    x = calloc(nx, sizeof(int)); //#include <stdlib.h>

    printf("Enter in ascending order... \n");
    printf("x[0] : ");
    scanf("%d", &x[0]); //배열의 첫번째 요소를 입력받는다.

    for(i = 1; i < nx; i++){
        do{
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        }while(x[i] < x[i - 1]); //입력이 오름차순인 것을 보장해준다.
    }

    printf("Number to search for ... : ");
    scanf("%d", &ky);
    idx = bin_search(x, nx, ky);

    if(idx == -1){
        puts("Search Failed");
    }
    else{
        printf("%d is at x[%d] ! ", ky, idx);
    }


    search(x, 5, 10);

    return 0;
}