//
// Created by sarah on 2/4/2020.
//

#include "IntSet.h"
#include <stdio.h>
#include <stdlib.h>

#define  TRUE 1;
#define FALSE 0;

//집합 초기화
int Initialize(IntSet * set, int max){

    set -> num = 0;
    //set of int.
    if((set -> setPtr = calloc(max, sizeof(int))) == NULL){
        set -> max = 0;
        return -1;
    }

    set -> max = max;
    return 0;
}

int IsMember(const IntSet * set, int n){
    int i;
    for(i = 0; i < set -> num; i++){
        if(set -> setPtr[i] == n){
            //존재하는 경우 인덱스 반환
            return i;
        }
    }
    //존재하지 않는 경우
    return -1;
}

void Add(IntSet * set, int n){
    //set 에 n이 들어있는지 확인 후, 없으면 추가한다.
    if(IsMember(set, n) == -1 && set -> num < set -> max){
        //요소를 추가하고 num 변수를 증가시킨다.
        set -> setPtr[set -> num++] = n;
    }
}

void Remove(IntSet * set, int n){
    //마지막 요소를 삭제 위치로 옮김
    int idx;

    //returns index, assigns to idx.
    if((idx = IsMember(set, n)) != -1){
        //삭제할 위치에 마지막 요소를 대입함으로써 삭제한다.
        set -> setPtr[idx] = set -> setPtr[--set->num];
    }
}

int Capacity(const IntSet * set){
    return set -> max;
}

int Size(const IntSet * set){
    return set -> num;
}

//집합 S2 를 S1 에 복사
void Assign(IntSet * set1, const IntSet * set2){
    int i;

    int n = (set1 -> max < set2 -> num) ? set1 -> max : set2 -> max;

    //S2 의 원소들을 S1 으로 복사한다.
    for(i = 0; i < n; i++){
        set1 -> setPtr[i] = set2 -> setPtr[i];
    }

    set1 -> num = n;
}

//집합 두개가 같은지 확인
int Equal(const IntSet * set1, const IntSet * set2){
    //만약 두 집합의 사이즈가 다르다면 즉각 리턴한다.
    int i, j;
    if(Size(set1) != Size(set2)){
        return FALSE;
    }

    for(i = 0; i < set1->num; i++){
        for(j = 0; j < set2-> num; j++){
            if(set1 -> setPtr[i] == set2->setPtr[j]){
                //breaks out of the inner for loop
                break;
            }
        }
        //j 의 끝까지 검사했을 경우 return
        if(j == set2->num){
            return FALSE;
        }
    }

    return TRUE;
}

//집합 S2 와 S3 의 합집합을 S1 에 대입
IntSet * Union(IntSet * set1, const IntSet * set2, const IntSet * set3){
    int i;
    Assign(set1, set2);

    for(i = 0; i < set3 ->num; i++){
        //중복된 것을 건너뛰면서 set3의 요소들을 set1 에 넣는다.
        Add(set1, set3->setPtr[i]);
    }

    return set1;
}

//집합 S2 에서 S3 을 뺀 결과를 S1 에 대입
IntSet * Intersection(IntSet * set1, const IntSet * set2, const IntSet * set3){
    int i, j;
    set1 -> num =0; //set1 을 공집합으로 만든다.
    for(i = 0; i < set2->num; i++){
        for(j = 0; j < set3->num; j++){
            if(set2->setPtr[i] == set3->setPtr[j]){
                Add(set1, set2->setPtr[i]);
            }
        }
    }
    return set1;
}

IntSet * Difference(IntSet * set1, const IntSet * set2, const IntSet * set3){
    int i, j;
    set1->num =0;
    for(i = 0; i < set2->num; i++){
        for(j = 0; j < set3->num; j++){
            if(set2->setPtr[i] == set3->setPtr[j]){
                break;
            }
        }

        if(j == set3->num){
            Add(set1, set2->setPtr[i]);
        }
    }
}

//집합 S 의 모든 원소들을 출력
void Print(const IntSet * set){

    printf("{ ");
    for(int i = 0; i < set -> num; i++){
        printf("%d ", set[i]);
    }
    printf(" }");
}

void PrintLn(const IntSet * set){
    Print(set);
    putchar('\n');
}

//집합 종료
void Terminate(IntSet * set){
    if(set->setPtr !=NULL){
        free(set->setPtr);
        set->max = set->num =0;
    }
}