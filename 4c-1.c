//
// Created by sarah on 11/24/2019.
//


#include <stdio.h>
#define N 10

int main(void){
    
    int i; 
    int a[N]; 
    int cnt = 0; 
    int retry; 
    
    puts("Enter a Integer... ");
    do{
        printf("%dth Integer : ", cnt + 1); 
        scanf("%d", &a[cnt++ %N]); 
        printf("continue ? (yes : 1, no : 0) : ");
        scanf("%d", &retry); 
    }
    while(retry == 1); 
    
    i = cnt - N; 
    if(i<0){
        i = 0; 
    }
    for(; i < cnt; i++){
        printf("%2d th Integer = %d\n", i+1, a[i%N]);
    }
    return 0; 
}