//
// Created by sarah on 2/2/2020.
//

#ifndef ALGORITHMS_C_SIMPLEHEAP_H
#define ALGORITHMS_C_SIMPLEHEAP_H

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HeapData;
typedef int Priority;

typedef struct _heapElement{ //값이 작을수록 높은 우선순위
    Priority priority;
    HeapData data;
}HeapElement;

typedef struct _heap{
    int numOfData;
    HeapElement heapElementArr[HEAP_LEN];
}Heap;

void HeapInit(Heap * heap);
int IsHeapEmpty(Heap * heap);

void HeapInsert(Heap * heap, HeapData data, Priority priority);
HeapData HeapDelete(Heap * heap);

#endif //ALGORITHMS_C_SIMPLEHEAP_H
