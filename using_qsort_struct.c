//
// Created by sarah on 1/23/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[10];
    int height;
    int weight;
} Person;

//Person 형 비교함수 (이름 오름차순 정렬)
int comp_name_asc(const Person * x, const Person * y){
    return strcmp(x -> name, y -> name);
}

int comp_height_asc(const Person * x, const Person * y){
    return x -> height > y -> height ? 1 :
        x -> height < y -> height ? -1 : 0;
}

//몸무게 내림차순 정렬
int comp_weight_desc(const Person * x, const Person * y){
    return x -> weight > y -> weight ? -1 :
        x -> weight < y -> weight ? 1 : 0;
}

//사람 Num 명의 데이터를 출력
void print_person(const Person x [], int num){

    int i;
    for(i = 0; i < num; i++){
        printf("%-10s %dcm %dkg\n", x[i].name, x[i].height, x[i].weight);
    }
}

int main(){

    Person x[] = {
            {"Jay", 170, 43},
            {"Kay", 180, 42},
            {"Daisy", 169, 60},
            {"May", 150, 39}
    };

    int nx = sizeof(x) / sizeof(x[0]); //배열 x의 요소 개수

    puts("Before Sorting ");

    print_person(x, nx);

    //이름 오름차순 정렬
    qsort(x, nx, sizeof(Person), (int (*) (const void *, const void *))comp_name_asc);
    puts("Sorted by Name ASC");
    print_person(x, nx);

    //키 오름차순 정렬
    qsort(x, nx, sizeof(Person), (int (*) (const void *, const void *))comp_height_asc);
    puts("Sorted by Height ASC");
    print_person(x, nx);

    //몸무게 내림차순 정렬
    qsort(x, nx, sizeof(Person), (int (*) (const void *, const void *))comp_weight_desc);
    puts("Sorted by Weight DESC");
    print_person(x, nx);

    return 0;
}