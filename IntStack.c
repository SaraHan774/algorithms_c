//
// Created by sarah on 11/16/2019.
//

#include "IntStack.h"
#include <stdlib.h>
#include <stdio.h>

int Initialize(IntStack *s, int max){
    s -> max = max;
    s -> ptr = -1;
    s -> stack = calloc(max, sizeof(int));

    if(s -> stack == NULL){
        perror("Stack Init Failed ... ");
        return -1;
    }

    return 0;
}

int Push(IntStack *s, int item) {
    if (s->max > s->ptr) {
        //만약에 스택 최대 용량 > 현재 스택 용량인 경우
        (s->stack)[++s->ptr] = item;
        return 0;
    }
    perror("Stack Overflow");
    return -1;
}

int Pop(IntStack *s, int *item){
    if(s -> ptr != -1){
        *item = (s -> stack)[s -> ptr--];
        return *item;
    }
    perror("Stack Underflow");
    return -1;
}

int Peek(const IntStack *s, int *item){
    if(s -> ptr != -1){
        *item = (s -> stack)[s -> ptr];
        return *item;
    }
    perror("Nothing in the Stack");
    return -1;
}

void Clear(IntStack *s){
    s -> ptr = -1; //쌓여있는 데이터의 수 = 0 (새로운 데이터를 삽입할 인덱스를 0으로 셋팅)
}

int Size(const IntStack *s){
    //인덱스가 4에 있다면, 현재 0 ~ 3까지의 인덱스는 occupied.
    return (s -> ptr) + 1;
}

int Capacity(const IntStack *s){
    return s -> max;
}

int IsEmpty(const IntStack *s){
    //만약 0 혹은 0보다 작으면 true(1), 아니면 false (0)
    return s -> ptr <= 0;
}

int IsFull(const IntStack *s){
    return s -> ptr >= s -> max;
}

int Search(const IntStack *s, int item){
    //top -> bottom 까지 선형 검색
    int i ;
    for(i = s -> ptr - 1; i >= 0; i--){
        if(s -> stack[i] == item){
            return i;
        }
    }
    return -1;
}

void Print(const IntStack *s){
    int i ;
    for(i = 0; i <= s -> ptr; i++){
        printf("%d ", s -> stack[i]);
    }
    putchar('\n');
}

void Terminate(IntStack * s){
    if(s -> stack != NULL){
        free(s -> stack);
    }
    s -> max = s -> ptr = 0;
}
