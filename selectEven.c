#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
 
#include "list-selectEven.h"
 
// given a list of integers, write a function which 
// finds all even integers and constructs
// a new list containing these even integers 
// The original list should remain unmodified.
// The new list should be returned by the function.
// So if the original list is 1->55->66->4->X, the function
// should return a list 66->4->X. 
// And if the original list is 1->3->7->X, the function
// should return an empty list.
//
// Constraints:
// don't delete any nodes (i.e. do not call free())
// the order of integers in the new list should be the same as the original
// the original list should remain unmodified
//
// A function to determine the length of a list called numItems() 
// is provided. Fell free to use it but do not modify the function.
 
 
list selectEven (list sourceList) {
	link curr = sourceList->head;
	list evenList = malloc(sizeof(list));
	evenList->head = NULL;

	if (sourceList->head != NULL) {
		while (curr != NULL) {
			if (curr->value % 2 == 0) {
				link newNode = malloc(sizeof(link));
				newNode->value = curr->value;
				newNode->next = NULL;
				if (evenList->head == NULL) {
					evenList->head = newNode;
				} else {
					link evencurr = evenList->head;
					while (evencurr->next != NULL) {
						evencurr = evencurr->next;
					}
					evencurr->next = newNode;
				}
			}
			curr = curr->next;
		}
	}
	
	return evenList;
}
