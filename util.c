#include <stdlib.h>
#include <stdio.h>

void shuffle(int *array, int n);

void GET_OPERATION_ARRAY(long m, int member_count, int insert_count, int delete_count, int *operation_array) {

	// int operation_array[m+1];
	for (int i = 0; i < m; ++i) {
	  	if (i < member_count) {
	  		operation_array[i] = 0; 

	  	} else if (i < member_count + insert_count) {
	  		operation_array[i] = 1;

	  	} else if (i < m) {
	  		operation_array[i] = 2;

	  	}

	  	shuffle(operation_array, (int) m/2);
	}
}

void shuffle(int *array, int n)
{
    if (n > 1) 
    {
        int i;
        for (i = 0; i < n - 1; i++) 
        {
          int j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}  