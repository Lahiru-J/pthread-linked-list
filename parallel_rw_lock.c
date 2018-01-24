#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include "linked_list.h"
#include "timer.h"

long thread_count;
long node_count;
list_node * head;

const int MAX_THREADS = 8;

int getRandomNumber();
void Get_args();

void main(int argCount, char * args[]){

  srand(time(NULL));


  Get_args(argCount, args);

  printf("Thread count: %ld\nn: %ld\n", thread_count, node_count);


}

void Get_args(int argc, char* argv[]) {
    thread_count = strtol(argv[1], NULL, 10);  
    node_count = strtoll(argv[2], NULL, 10);
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