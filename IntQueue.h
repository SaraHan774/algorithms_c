//
// Created by sarah on 11/24/2019.
//

#ifndef ALGORITHMS_C_INTQUEUE_H
#define ALGORITHMS_C_INTQUEUE_H

typedef struct {
    int max; //큐의 최대 용량
    int num; //현재의 요소 개수
    int front; //프런트
    int rear; //맨 뒤
    int * que; //큐의 맨 앞 요소에 대한 포인터
}IntQueue;

int Initialize(IntQueue *q, int max);
int Enque(IntQueue *q, int x);
int Deque(IntQueue *q, int *x);
int Peek(const IntQueue *q, int *x);
void Clear(IntQueue *q);
int Capacity(const IntQueue *q);
int Size(const IntQueue *q);
int isEmpty(const IntQueue *q);
int isFull(const IntQueue *q);
int Search(const IntQueue *q, int x);
void Print(const IntQueue *q);
void Terminate(IntQueue *q);

//160 페이지 연습문제 4번
int Search2(const IntQueue *q, int x);

#endif //ALGORITHMS_C_INTQUEUE_H
