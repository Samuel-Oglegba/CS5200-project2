#include "pq.h"

#include <stdlib.h>

//linklist node
struct pq {
  int value;	
  double key;
  //ptr->next
  struct pq *next;
};


struct pq *head_n = NULL; //node head


/* Allocates and initializes a new pq */
pq* pq_create()
{
  return (pq*)malloc(sizeof(pq));
}

/* Adds value to pq based on numerical order of key */
void pq_push(pq *head, double key, void *value)
{
	head->key=key;
  	head->value=&value;
  	//if list is empty
  	if(head_n==NULL){
  		head_n = head;
  		head_n->next = NULL;
	}else{
	//if something in the list
		struct pq *current = head_n;
		struct pq *temp = NULL;
		//finding the place (small -> large) till current=NULL
	    while((head->value > current->value) && current!=NULL) {
	    	temp = current; //tracking old node for replacing
	    	current = current->next;
	    	}
		//push value is the largest in the list
		if(current == NULL){
			current = head;
			current->next = NULL;
		}else if(current==head_n){
		//push value is the smallest in the list
			head->next=current;	//new node become the head
			head_n=head;	
		}else{
		//something between the list
			head->next = current;
			temp->next = head;	
		}
		
	}
		
  //if (head && !(head->ptr)) head->ptr = value;
}

/* Returns value from pq having the minimum key */
void* pq_pop(pq *head)
{
  struct pq *p = head_n;
  head_n = head->next;
  return p;
}

/* Deallocates (frees) pq. Shallow destruction,
meaning nodes in the pq are not recursively freed. */
void pq_destroy(pq *head)
{
  free(head);
}

//just for complie void main(){}
