
#include <stdio.h>
#include <stdlib.h>


typedef struct  {
    int data;
    struct list_node* next;
} list_node ;


int Member(int value, struct list_node * head_p){
    struct list_node* curr_p = head_p;

    while (curr_p != NULL && curr_p->data < value)
        curr_p = curr_p->next;
    
    if (curr_p == NULL || curr_p->data>value){
        return 0;
    } else{
        return 1;
    }
}

int Insert(int value, struct list_node** head_pp){
    list_node * curr_p = *head_pp;
    list_node * pred_p = NULL;
    list_node * temp_p;

    while (curr_p != NULL && curr_p->data < value){
        pred_p = curr_p;
        curr_p = curr_p->next;
    }

    if(curr_p==NULL || curr_p->data > value){
        temp_p = malloc(sizeof(struct list_node));
        temp_p->data = value;
        temp_p->next = curr_p;
        if (pred_p == NULL)
            *head_pp = temp_p;
        else
            pred_p->next = temp_p;
        return 1;
    } else{
        return 0;
    }
}

int Delete (int value, struct list_node** head_pp) {
    struct list_node* curr_p = *head_pp;
    struct list_node* pred_p = NULL;

    while (curr_p != NULL && curr_p->data < value){
        pred_p = curr_p;
        curr_p = curr_p-> next;
    }

    if (curr_p != NULL && curr_p->data < value){
        if(pred_p==NULL){
            *head_pp = curr_p->next;
            free(curr_p);
        }else{
            pred_p->next = curr_p->next;
            free(curr_p);
        }
        return 1;
    }else{
        return 0;
    }
}




