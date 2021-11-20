#include "pq.h"
#include<stdio.h>

#include <stdlib.h>

//linklist node
struct pq {
  void *value;	
  double key;
  struct pq *next;
};


struct pq *head_o = NULL; //node head


/* Allocates and initializes a new pq */
pq* pq_create()
{
  head_o = (pq*)malloc(sizeof(pq));
  head_o->next = NULL;
  return head_o;
}

void print_link(pq *head){
	printf("============\n");
	struct pq* current = head;
	while (current){
		printf("%g\n", *(double*)current->value);
		current = current->next;
		
	}
	printf("============\n");
}

void pq_push(pq *head, double key, void *value) {
	
	if(head_o->next == NULL){//list is empty
		struct pq* current = (pq*)malloc(sizeof(pq));		
		current->value = value;
		current->key = key;
		head_o->next = current;
		current->next = NULL;
	}else{//List not empty
		struct pq* new_node = (pq*)malloc(sizeof(pq));
		new_node->key = key;
		new_node->value = value;
		struct pq* current = head_o->next;
		struct pq* temp = head_o;
		//not sure why can't compare nodes, make new variables
		double node = new_node->key;
		double curr = current->key;
		
		while(node > curr){
		//if new node > current now, go to next
			temp = current;
			current = current->next;
			if(current== NULL){
		//current is null -> the new node is larger than all nodes
				curr = node +1;
			}else{
		//current not null, change key to compare
				curr = current->key;
			}
		} 
		//insertion sort(?
		if(temp==head_o){ //new_node is smallest
			new_node->next = current;
			head_o->next = new_node;
			
		}else if(current== NULL){ //new_node is largest
			struct pq* now = (pq*)malloc(sizeof(pq));
			now = head_o;
			while(now->next!=NULL){
				now = now->next;
			}
			now->next = new_node;
			now = now->next;
			now->next = NULL;
		}else{ //new node is somewhere in the list
			new_node->next = current;
			temp->next = new_node;
		}
	}
}




/* Returns value from pq having the minimum key */
void* pq_pop(pq *head)
{
  void *p = head->next->value;
  *head = *head->next;
  return p;
}



/* Deallocates (frees) pq. Shallow destruction,
meaning nodes in the pq are not recursively freed. */

void pq_destroy(pq *head)
{
  free(head);
}






//just for complie void main(){}

