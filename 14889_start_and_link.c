//
// Created by sarah on 2/14/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/
void combinationUtil(int arr[], int data[], int start, int end,
                     int index, int r);

// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination(int arr[], int n, int r)
{
    // A temporary array to store all combination one by one
    int data[r];

    // Print all combination using temprary array 'data[]'
    combinationUtil(arr, data, 0, n-1, 0, r);
}

/* arr[]  ---> Input Array
   data[] ---> Temporary array to store current combination
   start & end ---> Staring and Ending indexes in arr[]
   index  ---> Current index in data[]
   r ---> Size of a combination to be printed */
void combinationUtil(int arr[], int data[], int start, int end,
                     int index, int r)
{
    // Current combination is ready to be printed, print it
    if (index == r)
    {
        for (int j=0; j<r; j++){
            printf("%d ", data[j]);
        }
        printf("\n");
        return;
    }

    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}


int main(){

    int n;
    scanf("%d", &n); //n - 총 사람 수 (항상 짝수)

    if(n%2 != 0){
        perror("N must be an even number.");
        exit(0);
    }


    //능력치의 배열 필요
    int powerArr[n][n];

    int totalPower = n*(n-1)/2;
    int addPowerStart[totalPower];
    int addPowerLink[totalPower];

    int teamStart[totalPower][n/2];
    int teamLink[totalPower][n/2];

    int sub[n];

    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &powerArr[i][j]);
        }
        sub[i] = i+1;
    }




    //팀 나누기의 조합들?
//    teamStart = {
//            {1, 2, 3},
//            {2, 3, 4},
//            {3, 4, 5}, ...
//    };


    //팀을 나누었을 때 점수 계산하기

    //점수의 차가 가장 적을 때 해당 값 반환하기.


    return 0;
}