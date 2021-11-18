#include "pq.h"

#include <stdlib.h>
#include <stdio.h>


struct pq {
   double *ptr;
  // Current Size of the minheap
   int size;
  // Maximum capacity of the minheap
   int capacity;
};


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
    return minheap->ptr[0];
}


pq* heapify(pq* head, int index) {
    // Rearranges the heap as to maintain
    // the min-heap property
    if (head->size <= 1)
        return head;
     
    int left = left_child(index); 
    int right = right_child(index); 
 
    // Variable to get the smallest element of the subtree
    // of an element an index
    int smallest = index; 
     
    // If the left child is smaller than this element, it is
    // the smallest
    if (left < head->size && head->ptr[left] < head->ptr[index]) 
        smallest = left; 
     
    // Similarly for the right, but we are updating the smallest element
    // so that it will definitely give the least element of the subtree
    if (right < head->size && head->ptr[right] < head->ptr[smallest]) 
        smallest = right; 
 
    // Now if the current element is not the smallest,
    // swap with the current element. The min heap property
    // is now satisfied for this subtree. We now need to
    // recursively keep doing this until we reach the root node,
    // the point at which there will be no change!
    if (smallest != index) 
    { 
        int temp = head->ptr[index];
        head->ptr[index] = head->ptr[smallest];
        head->ptr[smallest] = temp;
        head = heapify(head, smallest); 
    }
 
    return head;
}


pq* delete_element(pq* head, int index) {
    // Deletes an element, indexed by index
    // Ensure that it's lesser than the current root
    head->ptr[index] = get_min(head) - 1;
     
    // Now keep swapping, until we update the tree
    int curr = index;
    while (curr > 0 && head->ptr[parent(curr)] > head->ptr[curr]) {
        int temp = head->ptr[parent(curr)];
        head->ptr[parent(curr)] = head->ptr[curr];
        head->ptr[curr] = temp;
        curr = parent(curr);
    }
 
    // Now simply delete the minimum element 
  //  head = delete_minimum(head);
    head = pq_pop(head);
    return head;
}


void print_heap(pq* heap) {
    // Simply print the array. This is an
    // inorder traversal of the tree
    printf("Min Heap:\n");
    int MAX_SIZE = heap->size;

    for (int i=0; i<MAX_SIZE; i++) {
        //printf("%g -> ", heap->ptr[i]);

         double left = left_child(i)<MAX_SIZE ? heap->ptr[left_child(i)] : 0;
         double right = right_child(i)<MAX_SIZE ? heap->ptr[right_child(i)] : 0;
        printf("Parent: %g, -> left: %g, -> right: %g \n", heap->ptr[i], left, right);
    }
    printf("\n");
}

/* Allocates and initializes a new pq */
pq* pq_create()
{
      int n = 10000;
      pq * new_pq = (pq*)malloc(sizeof(pq));

      new_pq->ptr = malloc(sizeof(double)*n);

      new_pq->capacity = n;
      new_pq->size = 0;
      
      return new_pq;
}

/* Adds value to pq based on numerical order of key */
void pq_push(pq *head, double key, void *value)
{
      
     // if (head && !(head->ptr)) head->ptr = value;
      if (head){
                if (head->size == head->capacity) {

                    printf("Cannot insert %g. minheap is already full!\n", key);

                    //return head;
                    return;
                }

            head->size++;
            head->ptr[head->size - 1] = key;
        
                // Keep swapping until we reach the root
                  int curr = head->size - 1;
                  // As long as you aren't in the root node, and while the 
                  // parent of the last element is greater than it

                while (curr > 0 && head->ptr[parent(curr)] > head->ptr[curr]) {
                        // Swap
                        double temp = head->ptr[parent(curr)];
                        head->ptr[parent(curr)] = head->ptr[curr];
                        head->ptr[curr] = temp;
                        // Update the current index of element
                        curr = parent(curr);
                  }
      }
        
}

/* Returns value from pq having the minimum key */
void* pq_pop(pq *head)
{
 /* void *p = head->ptr;
  head->ptr = NULL;
  return p;
  */
   // Deletes the minimum element, at the root
    if (!head || head->size == 0)
        return head;
 
    int size = head->size;
    double last_element = head->ptr[size-1];
     
    // Update root value with the last element
    head->ptr[0] = last_element;
 
    // Now remove the last element, by decreasing the size
    head->size--;
    size--;
 
    // We need to call heapify(), to maintain the min-heap
    // property
    head = heapify(head, 0);
    return head;
}


/* Deallocates (frees) pq. Shallow destruction,
meaning nodes in the pq are not recursively freed. */
void pq_destroy(pq *head)
{
  free(head);
}



