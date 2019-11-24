//
// Created by sarah on 11/24/2019.
//

#include <stdio.h>
#include <stdbool.h>
#include "IntQueue.h"

int main(void){
    IntQueue que;

    if(Initialize(&que, 64) == -1){
        puts("failed to init queue. ");
        return -1;
    }

    while(true){
        int m, x, search_result;

        printf("Current num of data : %d / %d \n", Size(&que), Capacity(&que));
        //Search2 및 다른 함수를 사용하는 manual 추가
        printf("(1) enque (2)deque (3)peek (4)print (5)search2 (6)Clear (0)terminate : ");
        scanf("%d", &m);


        if(m == 0){
            break;
        }

        switch (m){
            case 1:
                printf("data : ");
                scanf("%d", &x);
                if(Enque(&que, x) == -1){
                    puts("\a error : enque failed.");
                }
                break;
            case 2:
                if(Deque(&que, &x) == -1){
                    puts("\a error : deque failed.");
                }else{
                    printf("deque result : %d \n", x);
                }
                break;
            case 3:
                if(Peek(&que, &x) == -1){
                    puts("\a error : peek failed.");
                }else{
                    printf("peek result : %d \n", x);
                }
                break;
            case 4:
                Print(&que);
                break;
            case 5:
                printf("\nenter number to search : ");
                scanf("%d", &x);
                search_result = Search2(&que, x);
                printf("search result : %d \n", search_result);
                break;
            case 6:
                Clear(&que);
                printf("\ncleared queue ... result : ");
                Print(&que);
                break;
        }
    }

    Terminate(&que);
    return 0;
}