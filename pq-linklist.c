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
  	head->value=value;
  	head->next = head_n;
  	head_n = head;	
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

