#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "timer.h"

node generate_node();
node init_linked_list(int n);
node insert(node head, int value);
int member(node head, int value);
node delete(node head, int value);

typedef struct Node {
	int value;
	struct Node * next;
} node;

/* 
 * Function:	generate_node
 * Purpose:		generates a new node
 * Returns:		a new node
 */
node generate_node() {
	node new_node;
	new_node = (node) malloc(sizeof(node));
	new_node->next = NULL;

	return new_node;
}

/* 
 * Function:	init_linked_list
 * Purpose:		initialize the linked list
 * Returns:		head of the linked list
 */
node init_linked_list(int n) {
	int i = 0;
	srand(time(NULL));
	node head = insert(NULL, rand());

	for (i = 0; i < n; i++) {
		int rand_num = rand();
		// If number does not exists in the linked list
		while (member(head, rand_num)) {
			rand_num = rand();
		}

		insert(head, rand_num);
	}

	return head;
}

/* 
 * Function:	insert
 * Purpose:		insert a new node at the end of the linked 
 				list with the specified <code>value</code>
 * Returns:		head of the linked list
 */ 
node insert(node head, int value) {
	node tmp_node = generate_node();
	tmp_node->value = value;

	if (head == NULL) {
		head = tmp_node;

	} else {
		node current_node = head;

		while (current_node->next != NULL) {
			current_node = current_node->next;
		}
		current_node->next = tmp_node;
	}

	return head;
}

/* 
 * Function:	member
 * Purpose:		check whether the <code>value</code> exists 
 				or not in the linkded list
 * Returns:		1 if value present or 0 otherwise
 */ 
int member(node head, int value) {
	node current_node = head;

	while (current_node != NULL) {

		if (current_node->value == value) {
			return 1;
		}
		current_node = current_node->next;
	}

	return 0;
}


/* 
 * Function:	delete
 * Purpose:		delete the node which contains the <code>value</code>
 * Returns:		head of the linked list if not null or <code>NULL</code> otherwise
 */ 
node delete(node head, int value) {

	if (head != NULL) {
		if (head->value == value) {
			*head = *(head->next);
			free(head);

		} else {
			node current_node = head;
			while (current_node->next != NULL) {

				if (current_node->next->value == value) {
					node tmp = current_node->next->next;
					free(current_node->next);
					current_node->next = tmp;

					break;
				}
				current_node = current_node->next;
			}
		}

		return head;
	}

	return NULL;
}