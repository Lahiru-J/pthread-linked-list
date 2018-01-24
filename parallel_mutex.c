#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include "linked_list.h"
#include "timer.h"
#include "util.h"

long node_count;
long thread_count;
list_node *head;
long m;
float m_member, m_insert, m_delete;
int member_count, insert_count, delete_count;
int curr_op;
pthread_t *thread_handles;
pthread_mutex_t lock, timeLock;
int *ops_order;

double total_time;

void get_args();
void init_linked_list();
void *perform_op(void *param);

/* main */

int main(int argCount, char *args[])
{
  srand(time(NULL));
  get_args(argCount, args);

  printf("Node count: %ld\nTotal Operations: %ld\nMember Operations: %d\nInsert Operations: %d\nDelete Operations: %d\n\n",
         node_count, m, member_count, insert_count, delete_count);

  ops_order = malloc(sizeof(int) * m);
  GET_OPERATION_ARRAY(m, member_count, insert_count, delete_count, ops_order);

  init_linked_list();

  pthread_mutex_init(&lock, NULL);
  pthread_mutex_init(&timeLock, NULL);

  curr_op = 0;

  thread_handles = malloc(thread_count * sizeof(pthread_t));

  int thread;

  for (thread = 0; thread < thread_count; thread++)
  {
    pthread_create(&thread_handles[thread], NULL,
                   perform_op, NULL);
  }

  for (thread = 0; thread < thread_count; thread++)
  {
    pthread_join(thread_handles[thread], NULL);
  }

  printf("Average time: %f\n", (total_time / m));

  free(thread_handles);
  free(ops_order);

  return 1;
}

void get_args(int argc, char *argv[])
{
  node_count = strtol(argv[1], NULL, 10);
  thread_count = strtol(argv[2], NULL, 10);
  m = strtol(argv[3], NULL, 10);
  m_member = atof(argv[4]);
  m_insert = atof(argv[5]);
  m_delete = atof(argv[6]);

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

void *perform_op(void *param)
{

  int proceed = 1;

  while (proceed)
  {
    double start, finished;

    pthread_mutex_lock(&lock);

    GET_TIME(start);

    printf("curr_op: %d, ops order[curr_op]: %d\n", curr_op, ops_order[curr_op]);

    if (curr_op < m)
    {

      switch (ops_order[curr_op])
      {

      case 0: // Member Operation
      {
        Member(rand() % 65536, head);
      }
      break;

      case 1: // Insert Operation
      {
        Insert(rand() % 65536, &head);
      }
      break;

      case 2: // Delete Operation
      {
        Delete(rand() % 65536, &head);
      }
      break;
      default:
        printf("An error occured.");
      }

      

      curr_op++; 
    }
    
    GET_TIME(finished);

    pthread_mutex_unlock(&lock);

    if (curr_op >= m)
    {
      proceed = 0;
    }

    pthread_mutex_lock(&timeLock);
    total_time += (finished - start);
    pthread_mutex_unlock(&timeLock);
  }
}
