#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include "linked_list.h"
#include "timer.h"
#include "util.h"

long node_count;                              // total number of nodes in linked list
list_node *head;
long m, thread_count;                         // total number of operations and threads
float m_member, m_insert, m_delete;
int member_count, insert_count, delete_count;
pthread_rwlock_t rwlock;
pthread_mutex_t lock;
double total_time;
int *cases;
int curr_op;

void get_args();
void init_linked_list();
void* Perform_Operations(void* rank);

int main(int argCount, char *args[])
{
  srand(time(NULL));
  long thread;  
  pthread_t* thread_handles;
  init_linked_list();

  get_args(argCount, args);
  cases = malloc(sizeof(int) * m);
  GET_OPERATION_ARRAY(m, member_count, insert_count, delete_count, cases);
  thread_handles = (pthread_t*) malloc (thread_count*sizeof(pthread_t)); 

  printf("Node count: %ld\nTotal Operations: %ld\nMember Operations: %d\nInsert Operations: %d\nDelete Operations: %d\n\n",
         node_count, m, member_count, insert_count, delete_count);

  pthread_mutex_init(&lock, NULL);
  pthread_rwlock_init(&rwlock, NULL);
  curr_op = 0;

  for (thread = 0; thread < thread_count; thread++) {
      pthread_create(&thread_handles[thread], NULL,
        Perform_Operations, (void*)thread);  
  } 

  double start, finished;

  GET_TIME(start);

  for (thread = 0; thread < thread_count; thread++) {
    pthread_join(thread_handles[thread], NULL); 
  }

  GET_TIME(finished);

  free(thread_handles);
  free(cases);

  total_time = (finished - start);
  printf("Total time: %f\n", total_time);

  return 1;
}

void* Perform_Operations(void* rank) {
  int proceed = 1;

  while (curr_op < m)
  {
    int tmp_position;

    pthread_mutex_lock(&lock);
    tmp_position = curr_op;
    curr_op++;
    pthread_mutex_unlock(&lock);
    
    if(tmp_position >= m){
      break;
    }
    
    int case_now = cases[tmp_position];
    // printf("tem %d\n", case_now);

    switch (case_now) {

      case 0: // Member Operation
          
          pthread_rwlock_rdlock(&rwlock);
          Member(rand() % 65536, head);
          pthread_rwlock_unlock(&rwlock);
          // printf("read\n");        

        break;

      case 1: // Insert Operation
          pthread_rwlock_wrlock(&rwlock);
          Insert(rand() % 65536, &head);
          pthread_rwlock_unlock(&rwlock);
          // printf("insert\n");
        break;

      case 2: // Delete Operation;
          pthread_rwlock_wrlock(&rwlock);
          Delete(rand() % 65536, &head);
          pthread_rwlock_unlock(&rwlock);
          // printf("delete\n");
        break;

      default:
        printf("default case");
    }
    
  }

  return NULL;
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
