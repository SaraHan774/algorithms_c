//
// Created by sarah on 11/24/2019.
//

#include "IntQueue.h"
#include <stdio.h>
#include <stdlib.h>

int Initialize(IntQueue *q, int max){
    q->num = q->front = q->rear = 0;
    if((q->que = calloc(max, sizeof(int))) == NULL){
        q->max = 0; //0으로 초기화 했다는건 배열 초기화에 실패한 경우 ? 왜 굳이 ?
        return -1;
    }

    q->max = max; //그다음에 인자로 넘겨받은 max 로 초기화
    return 0;
}


int Enque(IntQueue *q, int x){
    if(q->num >= q->max){
        //만약 큐가 가득 찬 상태라면
        return -1;
    }
    else{
        //총 요소 개수 1증가, 요소 rear 에 추가하기,rear 변수를 1 증가
        q->num++;
        q->que[q->rear++] = x;
        //ring buffer 구현 rear 인덱스가 max 에 다다르면, 0으로 초기화한다.
        if(q->rear == q->max){
            q->rear = 0;
        }
        return 0;
    }
}


int Deque(IntQueue *q, int *x){
    if(q->num <= 0){
        //만약 삭제할 요소가 없다면 -1을 반환
        return -1;
    }
    else{
        q->num--; //총 요소 개수를 감소시킨다
        *x = q->que[q->front++]; //맨 앞의 값을 x에 저장한 후 front++
        if(q->front == q-> max){ //만약 max 값과 front 가 같다면
            q->front = 0; //front 는 0 이 된다
        }
        return 0;
    }
}


int Peek(const IntQueue *q, int *x){
    if(q->num <= 0){
        //만약 큐가 비어있다면 return -1
        return -1;
    }
    *x = q->que[q->front]; //반환할 값을 x에 저장한다.
    return 0;
}


void Clear(IntQueue *q){
    //총 개수와 front, rear 값을 0으로 설정한다.
    q->num = q->front = q->rear = 0;
}


int Capacity(const IntQueue *q){
    //요소의 최대 개수를 반환한다.
    return q->max;
}


int Size(const IntQueue *q){
    //현재 총 요소의 개수를 반환한다.
    return q->num;
}


int isEmpty(const IntQueue *q){
    return q->num <= 0;
}


int isFull(const IntQueue *q){
    //총 요소의 개수가 최대 요소 개수보다 같거나 많은지 비교
    return q->num >= q->max;
}


int Search(const IntQueue *q, int x){
    int i, idx;
    for(i = 0; i < q->num ; i++){
        if(q->que[idx = (i + q->front) % q->max] == x){
            return idx;
        }
    }
    return -1;
}


void Print(const IntQueue *q){
    int i;
    for(i = 0; i < q->num; i++){
        printf("%d ", q->que[(i+q->front)%q->max]);
    }
    putchar('\n');
}


void Terminate(IntQueue *q){
    if(q->que != NULL){
        free(q->que);
    }
    //메모리 공간에 할당한 배열을 해제한다.
    q->max = q->num = q->front = q->rear = 0;
}