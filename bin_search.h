//
// Created by sarah on 11/14/2019.
//

#ifndef ALGORITHMS_C_BIN_SEARCH_H
#define ALGORITHMS_C_BIN_SEARCH_H

int bin_search(const int a[], int n, int key){
    int pl = 0;
    int pr = n -1;
    int pc;

    do{
        pc = (pl + pr) / 2;
        if(a[pc] == key){
            return pc;
        }
        else if(a[pc] < key){
            pl = pc + 1;
        }
        else{
            pr = pc - 1;
        }
    }while(pl <= pr);

    return -1;
}

#endif //ALGORITHMS_C_BIN_SEARCH_H
