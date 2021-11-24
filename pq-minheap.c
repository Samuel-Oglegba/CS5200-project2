#include "pq.h"

#include <stdlib.h>
#include <stdio.h>

struct dq {
    void *value;
    double key;
};

struct pq {
   struct dq** _dq;
  // Current Size of the minheap
   int size;
  // Maximum capacity of the minheap
   int capacity;
};

/* Allocates and initializes a new pq */
pq* pq_create()
{
      int capacity = 10000;
      pq * new_pq = (pq*)malloc(sizeof(pq));

      new_pq->_dq = malloc(sizeof(dq*)*capacity);

      new_pq->capacity = capacity;
      new_pq->size = 0;

      return new_pq;
}

dq* create_new_data(double key, void *value) {
    dq* new_data = (dq*) malloc(sizeof(dq));
    new_data->key = key;
    new_data->value = value;
    return new_data;
}

int parent(int i) {
    // Get the index of the parent
    return (i - 1) / 2;
}
 
int left_child(int i) {
    return (2*i + 1);
}
 
int right_child(int i) {
    return (2*i + 2);
}

double get_min(pq* minheap) {
    // Return the root node element,
    // since that's the minimum
    return minheap->_dq[0]->key;
}


pq* sortHeap(pq* head, int index) {
   


    int curr = index;
    int smallest = -1;
    int left = -1;
    int right = -1;
    // As long as you aren't in the root node, and while the
    // parent of the last element is greater than it

    while (curr < head->size) {
            // Swap
        smallest = curr;
        left = left_child(curr);
        right = right_child(curr);
        if (left < head->size && head->_dq[left]->key < head->_dq[curr]->key) smallest = left;
        if (right < head->size && head->_dq[right]->key < head->_dq[smallest]->key) smallest = right;
        if (smallest == curr) break;

        dq* temp = head->_dq[smallest];
        head->_dq[smallest] = head->_dq[curr];
        head->_dq[curr] = temp;
        // Update the current index of element
        curr = smallest;

    }
                 
 
    return head;
}


void print_heap(pq* heap) {
    // Simply print the array. This is an
    // inorder traversal of the tree
    printf("Min Heap:\n");
    int MAX_SIZE = heap->size;

    for (int i=0; i<MAX_SIZE; i++) {
        //printf("%g -> ", heap->key[i]);

         double left = left_child(i)<MAX_SIZE ? heap->_dq[left_child(i)]->key : 0;
         double right = right_child(i)<MAX_SIZE ? heap->_dq[right_child(i)]->key : 0;
        printf("Parent: %g, -> left: %g, -> right: %g \n", heap->_dq[i]->key, left, right);
    }
    printf("\n");
}





/* Adds value to pq based on numerical order of key */
void pq_push(pq *head, double key, void *value)
{
      
    if (head && head->size >= head->capacity) return;

              
    head->size++;
    head->_dq[head->size - 1] = create_new_data(key,value);

    // Keep swapping until we reach the root
    int curr = head->size - 1;
    // As long as you aren't in the root node, and while the
    // parent of the last element is greater than it

    while (curr > 0 && head->_dq[parent(curr)]->key > head->_dq[curr]->key) {
        // Swap
        dq* temp = head->_dq[parent(curr)];
        head->_dq[parent(curr)] = head->_dq[curr];
        head->_dq[curr] = temp;
        // Update the current index of element
        curr = parent(curr);
    }

        
}

/* Returns value from pq having the minimum key */
void* pq_pop(pq *head)
{ 
       /*
        void *p = head->ptr;
        head->ptr = NULL;
        return p;
        */
     //  printf("aa -> %g\n", head->key[0]);
     // Deletes the minimum element, at the root
    if (!head || head->size == 0)
          return head;
 
        void *p = head->_dq[0]->value;
        int size = head->size;
        //printf("size -> %g\n", head->key[0]);

        dq* last_element = head->_dq[size-1];
        // Update root value with the last element
        head->_dq[0] = last_element;
        // Now remove the last element, by decreasing the size
      
        head->size--;
        // We need to call sortHeap(), to maintain the min-heap
        // property
         head = sortHeap(head, 0);
           // Making sure that heap property is also satisfied
      
       
        //return head;
        //printf("tt -> %g\n", head->key[0]);        
        
        return p;

}


/* Deallocates (frees) pq. Shallow destruction,
meaning nodes in the pq are not recursively freed. */
void pq_destroy(pq *head)
{
  free(head);
}



