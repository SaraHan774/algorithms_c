//
// Created by sarah on 11/16/2019.
//

#include "IntStack.h"
#include <stdlib.h>

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
        item = (s -> stack)[s -> ptr--];
        return item;
    }
    perror("Stack Underflow");
    return -1;
}

int Peek(const IntStack *s, int *item){
    if(s -> ptr != -1){
        item = (s -> stack)[s -> ptr];
        return item;
    }
    perror("Nothing in the Stack");
    return -1;
}

void Clear(IntStack *s){

}

int Size(const IntStack *s){

}

int IsEmpty(const IntStack *s){

}

int IsFull(const IntStack *s){

}

int Search(const IntStack *s, int item){

}

void Print(const IntStack *s){

}
