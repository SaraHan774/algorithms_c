//
// Created by sarah on 11/28/2019.
//

#include <stdio.h>


int factorial(int n){
    if(n > 0){
        return n * factorial(n - 1);
    }
    return 1;
}

//170페이지 1번문제
//재귀 함수 호출을 사용하지 않고 factorial 을 구하시오
int factorial2(int n){
    int result = 1;
    while(n > 0){
        result = result * n;
        --n;
    }
    return result;
}

//170페이지 2번문제
//재귀함수 호출 사용하지 않고 gcd 구하기 (유클리드 호제법으로 구함)
int gcd(int x, int y){
    int tmp;
    if(x < y) {
    //Case 1 : make x > y
        tmp = x;
        x = y;
        y = tmp;
    }

    if(x == y){
    //Case 2 : if equal, return either x or y
        return x;
    }
    //Case 3 : x > y
    else{
        int k = x % y;
        if(k == 0){
            return y;
        }
        while(k > 0){
            x = k;
            y = y % k;
            printf("x : %d, y : %d k : %d\n", x, y, k);
            if(y == 0){
                puts("k == 0");
                return x;
            }
            k = x % y;
        }
    }
    return 1;
}

//유클리드 호제법 : direct recursion
int gcd2(int x, int y){

    if(y == 0){
        return x;
    }

    return gcd2(y, x%y);
}

//170페이지 연습문제 3번
//배열 a의 모든 요소의 최대공약수 구하기
int gcd_array(const int a[], int n){
    if(n < 2){
        printf("Array should have more than 2 elements.\n");
        return -1;
    }

    int i = 0;
    int k;
    while(i < n - 1){
        k = gcd(a[i], a[i+1]);
        i++;
    }
    return k;
}


//174페이지 문제 4번
void recur2(int n){
    //Tree 중위순회한 결과대로 n이 출력됨.
    if(n > 0){
        recur2(n-2);
        printf("%d\n", n);
        recur2(n-1);
    }
}

int main(){
//    int n;
//    printf("Factorial Test : ");
//    scanf("%d", &n);
//
//    int result = factorial2(n);
//    printf("Result : %d", result);

//    int a, b;
//    printf("\nGreatest Common Divisor Test : ");
//    scanf("%d %d", &a, &b);
//    printf("Result : %d", gcd(a, b));

//    int a[4] = {3, 12, 18, 21};
//    printf("gcd array : %d", gcd_array(a, 4));

    recur2(5);

    return 0;
}