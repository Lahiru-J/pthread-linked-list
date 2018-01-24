#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include "linked_list.h"
#include "timer.h"

long node_count;
list_node * head;
long m;
float m_member, m_insert, m_delete;
int member_count, insert_count, delete_count;

void get_args();

void main(int argCount, char * args[]){
  srand(time(NULL));
  get_args(argCount, args);

  printf("Node count: %ld\nTotal Operations: %d\nMember Operations: %d\nInsert Operations: %d\nDelete Operations: %d\n\n",
   node_count, m, member_count, insert_count, delete_count);

  int i;
  int cases[] = {0, 1, 2};
  int array_length = 3;
  
  for (i = 0; i < m; ++i)
  {
      printf("Inside for loop");
      switch(cases[rand() % array_length]) {
      printf("Inside switch");
        case 0 : // Member Operation

          if (member_count > 0) {
            Member(rand() % 65536, &head);
            printf("Member Function m = %ld\n", m);
            member_count -= 1;

          } else if (array_length > 0) {
            array_length -= 1;
          }
          break;

        case 1 :  // Insert Operation

          if (insert_count > 0) {
            int succeeded;
            while (!succeeded) {
              succeeded = Insert(rand() % 65536, &head);
            }
            printf("Insert Function m = %ld\n", m);
            insert_count -= 1;

          } else if (array_length > 0){
            array_length -= 1;
          }
          break;
        
        case 2 :  // Delete Operation

          if (delete_count > 0) {
            int succeeded;
            while (!succeeded) {
              succeeded = Delete(rand() % 65536, &head);
            }
            printf("Delete Function m = %ld\n", m);
            delete_count -= 1;

          } else if (array_length > 0){
            array_length -= 1;
          }
          break;
      }
  }
}

void get_args(int argc, char* argv[]) {
    node_count = strtol(argv[1], NULL, 10);
    m = strtol(argv[2], NULL, 10);
    m_member = atof(argv[3]);
    m_insert = atof(argv[4]);
    m_delete = atof(argv[5]);

    member_count = m * m_member;
    insert_count = m * m_insert;
    delete_count = m * m_delete;
 }

 void init_linked_list() {
    int i;
    for (i = 0; i < node_count; i++){
    int succeeded = 0;

    while (!succeeded){
        succeeded = Insert((rand()%(65535)), &head);
    }
  }
 }

