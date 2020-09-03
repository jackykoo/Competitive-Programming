#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct Node{
    int val;
    struct Node *next;
}Node;

Node *head = NULL;
Node *curr = NULL;

Node* create(int val){
    printf("\n Creating list with headnode as [%d]\n", val);
    Node *ptr = (Node*)malloc(sizeof(Node));
    
    if(ptr == NULL){
      printf("\n Node creation failed \n");
      return NULL;
    }
    ptr->val = val;
    ptr->next = NULL;

    head = curr = ptr;
    return ptr;
}

Node* add_to_list(int val, bool add_to_end){
    if(head == NULL){
      return (create(val));
    }

    if(add_to_end)
      printf("\n Adding node to end of lisr with value [%d]\n", val);
    else
      printf("\n Adding node to beginning of list with value [%d]\n", val);

    Node *ptr = (Node*)malloc(sizeof(Node));
    if(ptr == NULL){
      printf("\n Node creation failed \n");
      return NULL;
    }
    
    ptr->val = val;
    ptr->next = NULL;

    if(add_to_end){
        curr->next = ptr;
        curr = ptr;
    }else{
      ptr->next = head;
      head = ptr;
    }
    return ptr;
}


int main(){


  return 0;
}
