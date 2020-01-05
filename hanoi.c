//
// Created by sarah on 12/23/2019.
//

#include <stdio.h>

void move(int no, int x, int y){
    if(no > 1){
        move(no -1, x, 6- x- y);
    }
    printf("Moved [%d] Plate from %d poll to %d poll. \n", no, x, y);
    if(no > 1){
        move(no -1, 6 -x - y, y);
    }
}

int main(void){
    int n;
    printf("Num of Tower Plate :");
    scanf("%d", &n);
    move(n, 1, 3);

    return 0;
}