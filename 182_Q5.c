//
// Created by sarah on 12/23/2019.
//

#include <stdio.h>

//해당 함수를 비 재귀적으로 구현하라
void recur3(int n){
    if(n > 0){
        recur3(n - 1);
        recur3(n - 2);
        printf("%d\n", n);
    }
}

void non_recur3(){
    
}

int main(){
    recur3(3);
    return 0;
}