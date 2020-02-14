//
// Created by sarah on 2/14/2020.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_WORD_COUNT 20000


typedef struct Map{
    int key;
    char * string;
}Map;


int comparator(const void *p, const void * q){

    Map * leftMap = ((Map * ) p);
    Map * rightMap = ((Map * ) q);

    if(leftMap -> key == rightMap -> key){
        return strcmp(leftMap -> string, rightMap -> string);
    }

    return(leftMap -> key - rightMap -> key);
}

static int isDuplicate = 0;

int main(){

    int n;
    Map * mapArr;

    scanf("%d", &n); //number of strings
    if(n > MAX_WORD_COUNT){
        perror("exceeded max num of words.");
        return 0;
    }

    char ** arr; //문자열의 배열을 가리키는 포인터
    arr = calloc(n, sizeof(char *));
    mapArr = calloc(n, sizeof(Map));

    for(int i = 0; i < n; i++){
        //반드시 각 char * 마다의 사이즈를 초기화 해 주어야 한다.
        arr[i] = calloc(MAX_WORD_LEN, sizeof(char));
        scanf("%s", arr[i]);

        mapArr[i].key = strlen(arr[i]);
        mapArr[i].string = arr[i];
    }

    //sort by length while keeping alphabetical order
    qsort((void *) mapArr, n, sizeof(mapArr[0]), comparator);


    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(strcmp(mapArr[i].string, mapArr[j].string) == 0){
                //puts("duplicate found");
                isDuplicate = 1;
                break;
            }
            isDuplicate = 0;
        }
        if(isDuplicate != 1){
            printf("%s\n", mapArr[i].string);
        }
    }

    //free the 2d-array
    for(int j = 0; j < n; j++){
        free(arr[j]);
    }

    free(arr);
    free(mapArr);
}