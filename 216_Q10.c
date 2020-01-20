//
// Created by sarah on 1/20/2020.
//

#include <stdio.h>
#include <stdlib.h>



//int binary_search(int a[], int target, int low, int high){
//    int l, h, m; //low, high, middle
//
//    l = low;
//    h = high;
//
//    int pos = 0;
//
//    while(l < h){
//        m = (l + h)/2;
//        if(target == a[m]){
//            //return where target should be inserted
//            return m + 1;
//        }else if(target < a[m]){
//            h = m - 1;
//        }
//        else{
//            l = m + 1;
//        }
//        pos = l;
//    }
//
//    return pos;
//}


//From https://www.geeksforgeeks.org/binary-insertion-sort/

int binarySearch(int a[], int item, int low, int high)
{
    if (high <= low)
        return (item > a[low])?  (low + 1): low;

    int mid = (low + high)/2;

    if(item == a[mid])
        return mid+1;

    if(item > a[mid])
        return binarySearch(a, item, mid+1, high);
    return binarySearch(a, item, low, mid-1);
}

int binary_insertion_sort(int a[], int n){

    int i, j;

    for(i = 1; i < n; i++){
        int tmp = a[i];
        j = i - 1;
        //이미 정렬이 된 부분을 이진검색을 통해 삽입 위치를 더 빠르게 알아낸다.
        int pos = binarySearch(a, tmp, 0, j); //insertion position for tmp

        printf("pos : %d\n", pos);

        while(j >= pos){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmp;
    }
}


int main(){
    int * a;
    int n;

    printf("Enter Num of Elements : ");
    scanf("%d", &n);

    a = calloc(n, sizeof(int));

    for(int i = 0; i < n; i++){
        printf("Enter a[%d] : ", i);
        scanf("%d", &a[i]);
    }


    binary_insertion_sort(a, n);

    for(int i = 0; i < n; i++){
        printf("a[%d] : %d \n", i, a[i]);
    }

    free(a);
    return 0;
}