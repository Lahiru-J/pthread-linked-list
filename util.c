#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(int *a, int *b);
void randomize(int arr[], int n);

void GET_OPERATION_ARRAY(long m, int member_count, int insert_count, int delete_count, int *operation_array) {

	int i;
	// int operation_array[m+1];
	for (i = 0; i < m; ++i) {
	  	if (i < member_count) {
	  		operation_array[i] = 0; 

	  	} else if (i < member_count + insert_count) {
	  		operation_array[i] = 1;

	  	} else if (i < m) {
	  		operation_array[i] = 2;

	  	}
	}

	randomize(operation_array, m);

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void randomize(int arr[], int n) {
    srand(time(NULL));
    int i;
    for(i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}