#include "pq.h"
#include<stdio.h>

#include <stdlib.h>

//linklist node
struct pq {
  void *value;	
  double key;
  //ptr->next
  pq *next;
};


//struct pq *head_n = NULL; //node head


/* Allocates and initializes a new pq */
pq* pq_create()
{
  //struct pq* test= NULL;
  struct pq* head_n = (pq*)malloc(sizeof(pq));
  head_n->next = NULL;
  return head_n;
}


void pq_push(pq *head, double key, void *value) {
	struct pq* new_node = (pq*)malloc(sizeof(pq));
	new_node->key = key;
	new_node->value = value;
	struct pq* current = head;
	while(current->next){
		current = current->next;
	}
	current->next = new_node;
	
}

void InsertionSort(pq* head)
{   
		if(!head || !head->next) return;
        // Initialize sorted linked list
        struct pq *sort= NULL;
        struct pq* current = head->next;
        // Traverse the given linked list and insert every
        // node to sorted
        while (current != NULL) {
            // Store next for next iteration
            struct pq* next = current->next;
            // insert current in sorted linked list
            
            if (sort == NULL || sort->key >= current->key) {
            current->next = sort;
            sort = current;
            head->next = sort;
        }
        else {
            struct pq* newcurrent = sort;
          
            
            while (newcurrent->next != NULL && newcurrent->next->key < current->key) {
                newcurrent = newcurrent->next;
            }
            current->next = newcurrent->next;
            newcurrent->next = current;
        }
        	//printf("%g\n", current->key);
            // Update current
            current = next;
        }
        // Update head to point to sorted linked list
        head = sort;
}
void print_link(pq *head){
	struct pq* current = head;
	while (current->next){
		current = current->next;
		printf("%g\n", *(double*)current->value);
	}
}
/* Returns value from pq having the minimum key */
void* pq_pop(pq *head)
{
  struct pq *p = head->value;
  head = head->next;
  return p;
}



/* Deallocates (frees) pq. Shallow destruction,
meaning nodes in the pq are not recursively freed. */

void pq_destroy(pq *head)
{
  free(head);
}






//just for complie void main(){}

