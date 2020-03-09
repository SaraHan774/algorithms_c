//
// Created by sarah on 3/9/2020.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>




typedef struct Node{
    int data;
    struct Node * next_node;
}node_t;

typedef struct SinglyLinkedList{
    node_t * head;
    node_t * tail;
}linked_list_t;


linked_list_t *  linked_list_init(){
    linked_list_t * list = calloc(1, sizeof(linked_list_t));
    list -> head = NULL;
    list -> tail = NULL;

    return list;
}

bool is_list_empty(linked_list_t * list){
    if(list -> head == NULL && list -> tail == NULL){
        return true;
    }
    return false;
}

node_t * create_node(linked_list_t * list, int data){

    node_t * new_node = calloc(1, sizeof(node_t));
    new_node -> data = data;
    new_node -> next_node = NULL;

    return new_node;
}


//주어진 data 를 담은 노드를 만들고 리스트의 tail 부분에 연결한다.
void insert_node(linked_list_t * list, int data){

    node_t * new_node = create_node(list, data);

    if(is_list_empty(list)){
        list -> head = list -> tail = new_node;
    }
    else{
        //맨 마지막 노드의 next 를 새로운 노드를 가리키게 하고
        list -> tail -> next_node = new_node;
        //새로운 노드를 tail 로 설정한다.
        list -> tail = new_node;
    }
}


//인풋으로 들어온 data 와 일치하는 값을 갖는 노드의 포인터를 반환한다.
node_t * search_node(linked_list_t * list, int data){

    if(is_list_empty(list)){
       return NULL;
    }

    node_t * node_ptr = list -> head;

    while(node_ptr != NULL){
        if(node_ptr -> data == data){
            //데이터가 일치하는 노드를 찾으면 해당 노드의 포인터를 반환한다.
            printf("Search result : %d \n", node_ptr -> data);
            return node_ptr;
        }
        node_ptr = node_ptr -> next_node;
    }

    return NULL;
}


int delete_node(linked_list_t * list, int data){

    node_t * node = search_node(list, data);

    if(node == NULL){
        perror("Delete Failed : Node does not exist!");
        return -1;
    }

    if(list -> head -> data == data){
        list -> head = node -> next_node;
        return 1;
    }

    node_t * prev_node = list -> head;
    while(prev_node -> next_node != node){
        prev_node = prev_node -> next_node;
    }
    //이전의 노드의 next 를 지우고자 하는 노드의 next 와 연결시킨다.
    printf("deleted %d \n", data);

    prev_node -> next_node = node -> next_node;
    return 1;
}


void print_list(linked_list_t * list){
    if(is_list_empty(list)){
        perror("the list is empty! please insert a new data. ");
    }
    else{
        //노드를 순회하며 Data 값들을 출력한다.
        node_t * node_ptr = list -> head;

        printf("{");
        do{
            printf("%d, ", node_ptr -> data);
            node_ptr = node_ptr -> next_node;
        }
        while(node_ptr != NULL);

        printf("}\n");
    }
}


void reverse_list(linked_list_t * list){

}

void free_list(linked_list_t * list){
    free(list);
}


int main(){

    linked_list_t * list = linked_list_init();


    int user_input;
    int data;
    while(true){
        printf("\nMENU : \n 0 : insert node\n 1 : delete node\n 2: print list\n 3 : end program\n");
        printf("Enter Menu Number : ");
        scanf("%d", &user_input);

        switch (user_input){
            case 0:
                printf("\nInsert Node (Enter Integer data) : ");
                scanf("%d", &data);
                insert_node(list, data);
                break;
            case 1:
                printf("\nDelete Node (Enter Integer data) : ");
                scanf("%d", &data);
                int result = delete_node(list, data);

                if(result > 0){
                    printf("\ndelete successful!\n");
                }else{
                    printf("\ndelete failed!\n");
                }
                break;
            case 2:
                printf("\nprinting list ... \n");
                print_list(list);
                break;
            case 3:
                free_list(list);
                exit(0);
        }
    }

}
