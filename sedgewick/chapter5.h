//
// Created by sarah on 11/30/2019.
// Practice Questions from 'Algorithms in C' (Robert Sedgewick)
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//5.1
int factorial(int N){
    if(N == 0){
        return  1;
    }
    return N * factorial(N-1);
}

int computeLog(int N){
    return  log10((double_t)factorial(N));
}


//5.3
int puzzle(int N){
    if(N == 1){
        return 1;
    }
    if(N%2 == 0){
        return puzzle(N/2);
    } else{
        return puzzle(3*N+1);
    }
}


int gcd_recursive(int x, int y){
    if(y == 0){
        return x;
    }
    return gcd_recursive(y, x%y);
}




