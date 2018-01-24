#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int data;
    struct list_node * next;
} list_node;

int Member( int value, list_node * head_p );
int Insert( int value, list_node** head_pp );
int Delete ( int value, list_node** head_pp );




