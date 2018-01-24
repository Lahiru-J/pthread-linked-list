
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/*
 * Function:    Member
 * Purpose:     check whther the <code>value</code> is available
 * In args:     value and head
 * Returns:     1 if value exists or 0 otherwise
 */
int Member( int value, list_node * head_p ){
    list_node * curr_p = head_p;

    while ( curr_p != NULL && curr_p->data < value )
        curr_p = curr_p->next;
    
    if ( curr_p == NULL || curr_p->data>value ){
        return 0;
    } else {
        return 1;
    }
}

/*
 * Function:    Insert
 * Purpose:     insert a new node to the linked list with given <code>value</code>
 * In args:     value should be inserted and head
 * Returns:     1 if insertion success and 0 if fails
 */
int Insert( int value, list_node** head_pp ){
    list_node * curr_p = *head_pp;
    list_node * pred_p = NULL;
    list_node * temp_p;

    while ( curr_p != NULL && curr_p->data < value ){
        pred_p = curr_p;
        curr_p = curr_p->next;
    }

    if ( curr_p == NULL || curr_p->data > value ) {
        temp_p = malloc(sizeof(list_node));
        temp_p->data = value;
        temp_p->next = curr_p;
        if ( pred_p == NULL )
            *head_pp = temp_p;
        else
            pred_p->next = temp_p;
        // printf("Added value: %d\n", value);
        return 1;
    } else {
        return 0;
    }
}

/*
 * Function:    Delete
 * Purpose:     delete an element from the linked list
 * In args:     value should deleted and head
 * Returns:     1 if delete success or 0 otherwise
 */
int Delete ( int value, list_node** head_pp ) {
    list_node * curr_p = *head_pp;
    list_node * pred_p = NULL;

    while ( curr_p != NULL && curr_p->data < value ){
        pred_p = curr_p;
        curr_p = curr_p-> next;
    }

    if ( curr_p != NULL && curr_p->data < value ){
        if ( pred_p==NULL ) {
            *head_pp = curr_p->next;
            free(curr_p);
        } else {
            pred_p->next = curr_p->next;
            free(curr_p);
        }
        return 1;
    } else {
        return 0;
    }
}




