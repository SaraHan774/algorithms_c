//
// Created by sarah on 2/2/2020.
//

#include <stdio.h>
#include "SimpleHeap.h"

int main(){

    Heap heap;
    HeapInit(&heap);


    HeapInsert(&heap, 'A', 1);
    HeapInsert(&heap, 'B', 2);
    HeapInsert(&heap, 'C', 3);
    printf("%c \n", HeapDelete(&heap));

    HeapInsert(&heap, 'A', 1);
    HeapInsert(&heap, 'B', 2);
    HeapInsert(&heap, 'C', 3);
    printf("%c \n", HeapDelete(&heap));

    while(!IsHeapEmpty(&heap)){
        printf("%c \n", HeapDelete(&heap));
    }


    return 0;
}