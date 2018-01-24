#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include "linked_list.h"
#include "timer.h"
#include "util.h"

long node_count;
list_node *head;
long m;
float m_member, m_insert, m_delete;
int member_count, insert_count, delete_count;

double total_time;

void get_args();
void init_linked_list();

int main(int argCount, char *args[])
{
  srand(time(NULL));
  get_args(argCount, args);

  printf("Node count: %ld\nTotal Operations: %ld\nMember Operations: %d\nInsert Operations: %d\nDelete Operations: %d\n\n",
         node_count, m, member_count, insert_count, delete_count);

  int ops_order[(int) m];
  GET_OPERATION_ARRAY(m, member_count, insert_count, delete_count, &ops_order ); 

  init_linked_list();

  int i;
  int cases[] = {0, 1, 2};
  int array_length = 3;

  for (i = 0; i < m; ++i)
  {
    double start, finished;
    
    int case_now = ops_order[i];

    switch (case_now)
    {

    case 0: // Member Operation
            // printf("Member Function m = %ld\n", i);
      {
        GET_TIME(start);
        Member(rand() % 65536, head);
        GET_TIME(finished);
        member_count -= 1;
      }
      break;

    case 1: // Insert Operation
      // printf("Insert Function i = %d\n", i);
      {
        GET_TIME(start);
        Insert(rand() % 65536, &head);
        GET_TIME(finished);
        insert_count -= 1;
      }
      break;

    case 2: // Delete Operation
      // printf("Delete Function i = %d\n", i);

      {
        GET_TIME(start);
        Delete(rand() % 65536, &head);
        GET_TIME(finished);
        delete_count -= 1;
      }
      break;
    default:
      printf("default case");
    }

    total_time += (finished - start);
  }

  printf("Average time: %f\n", (total_time/m));

  return 1;
}

void get_args(int argc, char *argv[])
{
  node_count = strtol(argv[1], NULL, 10);
  m = strtol(argv[2], NULL, 10);
  m_member = atof(argv[3]);
  m_insert = atof(argv[4]);
  m_delete = atof(argv[5]);

  member_count = m * m_member;
  insert_count = m * m_insert;
  delete_count = m * m_delete;
}

void init_linked_list()
{
  int j;
  for (j = 0; j < node_count; j++)
  {
    int succeeded = 0;

    while (!succeeded)
    {
      succeeded = Insert((rand() % (65536)), &head);
    }
  }
}
