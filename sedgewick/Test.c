//
// Created by sarah on 11/30/2019.
//

#include <stdio.h>
#include "chapter5.h"

int main(){

    //5.1
    puts("Log N factorial Test");
    printf("Result : %ld", computeLog(10));
    printf("\nFactorial result : %d ", factorial(10));


    //5.3
    puts("\n\npuzzle Test");
    for(int i = 1; i < 11; i++){
        printf("\npuzzle %d : %d ", i, puzzle(i));
    }

    return 0;
}