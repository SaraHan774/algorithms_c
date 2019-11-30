//
// Created by sarah on 11/30/2019.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 50

char *a;
int i;

int eval(){
    int x = 0;
    while(a[i] == ' '){
        i++;
    }

    if(a[i] == '+'){
        i++;
        return eval() + eval();
    }

    if(a[i] == '*'){
        i++;
        return eval() * eval();
    }

    while((a[i] >= '0') && (a[i] <= '9')){
        x = 10 * x + (a[i++] - '0');
        return x;
    }
}


int main(){
    a = calloc(MAX_NUM, sizeof(int));

    printf("Enter operands & operators\n");

    printf("\nPrefix expression : ");
    scanf("%s", a);

    int result = eval();
    printf("\nResult : %d", result);

//Enter operands & operators
//Prefix expression :*+7**46+895
//Result : 2075

    return 0;
}