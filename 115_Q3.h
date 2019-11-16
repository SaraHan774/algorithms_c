//
// Created by sarah on 11/16/2019.
//

#ifndef ALGORITHMS_C_115_Q3_H
#define ALGORITHMS_C_115_Q3_H

/* 배열 a의 요소 개수 n , 찾고자 하는 요소 key.
 * key를 찾은 위치를 idx 배열에 저장,
 * 배열 idx 의 길이를 반환하는 함수.
 */
int search_idx(const int a[], int n, int key, int idx[]){
    int j = 0; //idx 의 인덱스

    for(int i = 0; i < n; i++){
        if(a[i] == key){
            idx[j++] = i;
        }
    }
    return j;
}

#endif //ALGORITHMS_C_115_Q3_H
