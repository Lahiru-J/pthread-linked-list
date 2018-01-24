#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include "linked_list.h"
#include "timer.h"


long thread_count;
long n;
list_node * head;

const int MAX_THREADS = 1024;

int getRandomNumber();
void Get_args();

void main(int argCount, char * args[]){

  srand(time(NULL));


  Get_args(argCount, args);

  printf("Thread count: %ld\nn: %ld\n", thread_count, n);

  int i;

  for (i = 0; i < n; i++){
    int succeeded = 0;

    while (!succeeded){
        succeeded = Insert((rand()%(65535)), &head);
    }
  }
}



void Get_args(int argc, char* argv[]) {
    thread_count = strtol(argv[1], NULL, 10);  
    n = strtoll(argv[2], NULL, 10);
 }