//
// Created by sarah on 11/24/2019.
//

#include <stdio.h>
#include "IntStack.h"

int main(void){
    IntStack s;

    if(Initialize(&s, 64) == -1){
        puts("Failed to initialize the stack.");
        return -1;
    }

    while(1){
        int menu, x;
        printf("Current num of data : %d / %d \n", Size(&s), Capacity(&s));
        printf("(1)push, (2)pop, (3)peek, (4)print, (0)terminate : \n ");
        scanf("%d", &menu);

        if(menu == 0){
            break;
        }
        switch (menu){
            case 1 :
                printf("data : ");
                scanf("%d", &x);
                if(Push(&s, x) == -1){
                    puts("\a error : push failed. ");
                }
                break;

            case 2:
                if(Pop(&s, &x) == -1){
                    puts("\a error : Pop failed.");
                }else {
                    printf("popped data is %d \n", x);
                }
                break;

            case 3 :
                if(Peek(&s, &x) == -1){
                    puts("\a error : peek failed.");
                }else{
                    printf("peeked data is %d \n", x);
                }
                break;

            case 4 :
                Print(&s);
                break;

        }
    }

    Terminate(&s);

    return 0;
}
