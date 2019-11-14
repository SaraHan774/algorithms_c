//
// Created by sarah on 11/14/2019.
//

#ifndef ALGORITHMS_C_SEARCH_SEN_H
#define ALGORITHMS_C_SEARCH_SEN_H

int search(int a[], int n, int key){
    //배열, 배열길이, 찾고자 하는 값을 넘겨준다.
    int i = 0;
    a[n] = key; //key 값을 배열의 끝에다가 추가한다.

    for(i; i <= n; i++){
        if(i == n){
            puts("search() : search failed \n");
            return -1;
        }
        else if(a[i] == key){
            printf("search() : Found key %d", a[i]);
            return i;
        }
    }

    return -1;
}

#endif //ALGORITHMS_C_SEARCH_SEN_H
