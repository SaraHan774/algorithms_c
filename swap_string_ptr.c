//
// Created by sarah on 2/6/2020.
//


#include <stdio.h>
#include <string.h>
#define swap_char(type, x, y) do{type tmp = x; x = y; y = tmp;} while(0)

void swap(char **x, char **y){
    char * tmp = *x;
    *x = *y;
    *y = tmp;
}


void swap_str(char *x, char *y)
{
	char *temp;
	while (*x && *y) {					/* 짧은 문자열의 끝까지 문자열을 교환 */
		char t = *x; *x++ = *y; *y++ = t;
	}
	if (*x) {							/* x가 더 긴 문자열이라면 */
		temp = x;
		while (*x) { *y++ = *x++; }		/* x의 나머지를 y로 복사 */
		*temp = *y = '\0';
	}
	else if (*y) {						/* y가 더 긴 문자열이라면 */
		temp = y;
		while (*y) { *x++ = *y++; }		/* y의 나머지를 x로 복사 */
		*temp = *x = '\0';
	}
	else {
		*x = *y = '\0';
	}
}

int main(){

    char * s1 = "ABCD";
    char * s2 = "DBMS";

    printf("pointer s1 is pointing to : %s\n", s1);
    printf("pointer s2 is pointing to : %s\n", s2);


    //swap_char(char *, s1, s2);

    swap_str(s1, s2);

    puts("swapping ... ");

    printf("pointer s1 is pointing to : %s\n", s1);
    printf("pointer s2 is pointing to : %s\n", s2);



    return 0;
}