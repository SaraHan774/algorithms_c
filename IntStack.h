//
// Created by sarah on 11/16/2019.
//

#ifndef ALGORITHMS_C_INTSTACK_H
#define ALGORITHMS_C_INTSTACK_H

typedef struct {
    int max; //스택의 용량
    int ptr; //스택의 top
    int * stack; //스택의 첫 요소에 대한 포인터
}IntStack;

int Initialize(IntStack *s, int max);
int Push(IntStack *s, int item);
int Pop(IntStack *s, int *item);
int Peek(const IntStack *s, int *item);
void Clear(IntStack *s);
int Size(const IntStack *s);
int IsEmpty(const IntStack *s);
int IsFull(const IntStack *s);
int Search(const IntStack *s, int item);
void Print(const IntStack *s);
int Capacity(const IntStack *s); 
void Terminate(IntStack *s);

#endif //ALGORITHMS_C_INTSTACK_H
