//
// Created by sarah on 2/6/2020.
//

#include <stdio.h>
#include <limits.h>


void str_dump(const char * string){

    do{
        int i;
        printf("%c %0*X", *string, (CHAR_BIT + 3)/4, *string);

        for(i = CHAR_BIT - 1; i >= 0; i--){
            putchar(((*string >> i) & 1U) ? '1' : '0');
        }
        putchar('\n');
    }while(*string++ != '\0');
}

int main(){

    str_dump("STRING");
    return 0;
}