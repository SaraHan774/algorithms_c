//
// Created by sarah on 11/24/2019.
//

#include "TwoWayStack.h"
#include <stdio.h>
#include <stdbool.h>

two_way_arr_t twoWayArr;
int max = 30;

void pick_position(int * position){
    printf("position to operate on (0) Left (1) Right : \n");
    scanf("%d", position);
    if(*position == 0){
        puts("picked position left \n");
    }else if(*position == 1){
        puts("picked position right \n");
    }else{
        puts("wrong position number. enter either 0 or 1.");
    }
}

int main(void){

    if(init_stack_array(&twoWayArr, max) == -1){
        perror("Init Failed");
        return -1;
    }
    else{
        printf("init success : max = %d \n"
               "rightIdx = %d , leftIdx = %d \n\n", twoWayArr.max, twoWayArr.rightIdx, twoWayArr.leftIdx);
    }

    //break 과 return 의 차이 기억하기.
    while(true){

        int menu, x, position;
        printf("(1)push, (2)pop, (3)peek, (4)print_arr, (5)clear,(0)terminate : \n ");

        scanf("%d", &menu);
        if(menu == 0){
            break;
        }


        switch (menu){

            case 1 :
                pick_position(&position);

                printf("data : \n");
                scanf("%d" , &x);

                if(push(&twoWayArr, x, position) == -1){
                    puts("push failed");
                }
                break;
            case 2:
                pick_position(&position);

                pop(&twoWayArr, position);
                break;
            case 3:
                pick_position(&position);

                peek(&twoWayArr, position);
                break;
            case 4:
                print_arr(&twoWayArr);
                break;
            case 5:
                pick_position(&position);
                clear(&twoWayArr, position);
        }

    }

    terminate(&twoWayArr);

    return 0;
}