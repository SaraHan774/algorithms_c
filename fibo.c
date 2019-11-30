//
// Created by sarah on 11/30/2019.
//

#include <stdio.h>
#include <time.h>
#define MAX_MEMO 100

int memo[MAX_MEMO];

int fibonacci(int N){
    //base condition
    if(N <= 1){
        return N;
    }

    if(memo[N] != -1){
        return memo[N];
    }

    memo[N] = fibonacci(N-1) + fibonacci(N-2);

    return memo[N];
}

int fibonacci_raw(int N){
    //base condition
    if(N <= 1){
        return N;
    }
    return fibonacci_raw(N-1) + fibonacci_raw(N-2);
}


int main(){

    int k;
    for(k = 0; k < 100; k++){
        memo[k] = -1;
    }

    clock_t start, end;

    start = clock();
    int result = fibonacci(40); //raw : 603ms
    end = clock();
    printf("Fibonacci Result : %d , Time : %ld", result, end - start);

    return 0;
}