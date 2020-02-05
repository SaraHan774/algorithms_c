//
// Created by sarah on 2/4/2020.
//

#ifndef ALGORITHMS_C_INTSET_H
#define ALGORITHMS_C_INTSET_H

typedef struct {
    int max;
    int num;
    int * setPtr;
}IntSet;

//집합 초기화
int Initialize(IntSet * set, int max);

int IsMember(const IntSet * set, int n);

void Add(IntSet * set, int n);

void Remove(IntSet * set, int n);

int Capacity(const IntSet * set);

int Size(const IntSet * set);

//집합 S2 를 S1 에 대입
void Assign(IntSet * set1, const IntSet * set2);

//집합 두개가 같은지 확인
int Equal(const IntSet * set1, const IntSet * set2);

//집합 S2 와 S3 의 합집합을 S1 에 대입
IntSet * Union(IntSet * set1, const IntSet * set2, const IntSet * set3);

//집합 S2 에서 S3 을 뺀 결과를 S1 에 대입
IntSet * Intersection(IntSet * set1, const IntSet * set2, const IntSet * set3);

IntSet * Difference(IntSet * set1, const IntSet * set2, const IntSet * set3);

//집합 S 의 모든 원소들을 출력
void Print(const IntSet * set);

//집합 종료
void Terminate(IntSet * set);


#endif //ALGORITHMS_C_INTSET_H
