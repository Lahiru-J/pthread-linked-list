#ifndef _UTIL_
#define _UTIL_

#include <stdlib.h>
#include <stdio.h>

#define GET_OPERATION_ARRAY(long m, int member_count, int insert_count, int delete_count, int operation_array[]) {

	// int operation_array[m+1];
	for (int i = 0; i < m; ++i) {
	  	if (i < member_count) {
	  		operation_array[i] = 0; 

	  	} else if (i < member_count + insert_count) {
	  		operation_array[i] = 1;

	  	} else if (i < m) {
	  		operation_array[i] = 2;

	  	}
	}  
}

#endif