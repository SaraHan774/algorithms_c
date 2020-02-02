//
// Created by sarah on 2/2/2020.
//

#include "SimpleHeap.h"

void HeapInit(Heap * heap){
    heap -> numOfData = 0;
}

int IsHeapEmpty(Heap * heap){
    if(heap -> numOfData == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

int GetParentIndex(int index){
    return index/2;
}

int GetLeftChildIndex(int index){
    //배열 인덱스의 0인 요소는 비워두므로 노드의 고유번호가 노드가 저장되는 배열의 인덱스 값과 일치함
    return index*2;
}

int GetRightChildIndex(int index){
    return GetLeftChildIndex(index) + 1;
}

int GetHighPriorityChildIndex(Heap * heap, int index){
    //Heap 이 비워져 있는 경우 ?
    if(GetLeftChildIndex(index) > heap -> numOfData){
        return 0;
    }
    else if(GetLeftChildIndex(index) == heap -> numOfData){
        return GetLeftChildIndex(index);
    }
    else{
        if(heap -> heapElementArr[GetLeftChildIndex(index)].priority
        > heap -> heapElementArr[GetRightChildIndex(index)].priority){
            return GetRightChildIndex(index);
        }else{
            return GetLeftChildIndex(index);
        }
    }
}

void HeapInsert(Heap * heap, HeapData data, Priority priority){
    int index = heap -> numOfData + 1;

    //Struct 초기화
    HeapElement element = {
            priority,
            data
    };

    while(index != 1){
        if(priority < (heap -> heapElementArr[GetParentIndex(index)].priority)){
            heap -> heapElementArr[index] = heap -> heapElementArr[GetParentIndex(index)];
            index = GetParentIndex(index);
        }else{
            //부모의 우선순위가 더 낮은 경우 while 문에서 나온다.
            break;
        }
    }

    heap -> heapElementArr[index] = element;
    heap -> numOfData += 1;
}


HeapData HeapDelete(Heap * heap){
    HeapData returnData = (heap -> heapElementArr[1]).data;
    HeapElement lastElement = heap -> heapElementArr[heap -> numOfData];

    int parentIndex = 1;
    int childIndex;

    while(childIndex = GetHighPriorityChildIndex(heap, parentIndex)){
        if(lastElement.priority <= heap -> heapElementArr[childIndex].priority){
            break;
        }
        heap -> heapElementArr[parentIndex] = heap -> heapElementArr[childIndex];
        parentIndex = childIndex;
    }

    heap -> heapElementArr[parentIndex] = lastElement;
    heap -> numOfData -= 1;
    return returnData;
}

