//
// Created by sarah on 1/21/2020.
//

#include "testing.h"

#include <stdio.h>
#include <stdlib.h>


void generate_int(int num, char * fileName){

    int * buffer;
    FILE * file = NULL;

    file = fopen(fileName, "w");

    if(file == NULL){
        printf("fopen error");
        exit(0);
    }

    buffer = calloc(num, sizeof(int));

    for(int i = 1; i <= num;i++){
        int n = rand() % num + 1;
        buffer[i] = n;
        fprintf(file, "%d\n", buffer[i]);
    }

    fclose(file);
}

void read_int(char * fileName){

}