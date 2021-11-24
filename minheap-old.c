#include "pq.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct pq {
   void *ptr;
   double key;
   // Current Size of the minheap
   int size;
   // Maximum capacity of the minheap
   int capacity;
  // pq * parent;
   pq * left;
   pq * right;
};

struct pq *head_o = NULL; //node head

void printme(pq* heap, char str1[7]){
    
    if(heap && heap->ptr != NULL){       

         printme(heap->left,"left");

         printme(heap->right,"right");

         printf("%s: %g -- capacity %d -- size %d \n", str1,*(double *)heap->ptr, heap->capacity, heap->size); 
    }  

}

void print_heap(pq* heap) {     
      printme(heap, "root");
}

//swap two nodes
void swapNode(pq *x, pq *y){        
        // printf("i am here %g -- %g\n", *(double *)x->ptr, y->key);
        if(*(double *)x->ptr > 0 && y->key > 0){
                                 
                        void *temp1 = x->ptr;
                        double temp2 = x->key;

                            x->ptr = y->ptr;
                            x->key = y->key;

                        y->ptr = temp1;
                        y->key = temp2;
                        
        }                               

}


// Count the number of nodes
  int countNodes(struct pq *root) {
    if (root == NULL){
      return (0);
    }    
    return (1 + countNodes(root->left) + countNodes(root->right));
  }

// Check if the tree is a complete binary tree
  bool checkComplete(struct pq *root, int index, int numberNodes) {
    // Check if the tree is complete
    if (root == NULL)
      return true;

    if (index >= numberNodes)
      return false;

    return (checkComplete(root->left, 2 * index + 1, numberNodes) && checkComplete(root->right, 2 * index + 2, numberNodes));
  }

  int parentNode(int i) {
      // Get the index of the parent
      return (i - 1) / 2;
  }
  
  int left_child(int i) {
      return (2*i + 1);
  }
  
  int right_child(int i) {
      return (2*i + 2);
  }

  int hasBothChild(pq* temp)
  {
      return temp && temp->left && temp->right;
  }

  void insertToParentNode(pq* heap, int parentIndex, double key, void *value, int capacity){
  
        if(!heap || heap->ptr == NULL){  
              return;
        }         
        if(heap->size == parentIndex){
               bool swapTheNodes = false;
               if(*(double *)heap->ptr > key){
                  swapTheNodes = true;
                }

              struct pq* nodeToAdd = (pq*)malloc(sizeof(pq));	
              nodeToAdd->ptr = value;
              nodeToAdd->key = key;
              nodeToAdd->left = NULL;
              nodeToAdd->right = NULL;
             // nodeToAdd->parent = heap->ptr;
              nodeToAdd->size = capacity;//heap->capacity; //this gives the index of each node               

              if(heap->left == NULL){
                heap->left = nodeToAdd; 
                  if(swapTheNodes){
                     //swap parent for right node
                     // setNewParent(heap, heap->right,heap->left,1);
                      swapNode(heap,heap->left);                     
                  }              
              }
              else{
                heap->right = nodeToAdd; 
                  if(swapTheNodes){
                     //swap parent for left node
                    // setNewParent(heap, heap->left,heap->right,0);
                      swapNode(heap,heap->right);                     
                  }
              }              
        
          }

         insertToParentNode(heap->left, parentIndex, key, value, capacity);
         insertToParentNode(heap->right, parentIndex, key, value, capacity);
  }

    void heapifyMe(pq* heap){

         if(!heap || heap->ptr == NULL){  
              return;
          }

         double smallest = *(double *)head_o->ptr;

        
        if(smallest > *(double *)heap->ptr){         
          swapNode(head_o,heap); 
          //printf("i came here %g\n", *(double *)heap->ptr);
        }
     
        heapifyMe(heap->left);
        heapifyMe(heap->right);

    }

  
/* Allocates and initializes a new pq */
pq* pq_create()
{
      head_o = (pq*)malloc(sizeof(pq));
      head_o->left = NULL;
      head_o->right = NULL;
      head_o->capacity = 0;
      head_o->size = 0;

      return head_o;
}

/* Adds value to pq based on numerical order of key */
void pq_push(pq *head, double key, void *value)
{
    head->capacity++;

    if (head && !(head->ptr)){
      head_o->ptr = value;
      head_o->left = NULL;
      head_o->right = NULL;
     // head_o->parent = value;
      head_o->size = head->capacity;
    }
    else{

         struct pq* current = (pq*)malloc(sizeof(pq));	
         struct pq* parent = NULL;	

          current = head_o;
          int isLeft = 0;

         int parentIndex = parentNode(head->capacity-1);
         insertToParentNode(head, (parentIndex+1), key, value, head_o->capacity); 
    }

    //sortHeap(head_o);

   // heapifyMe(head_o);
          
}

/* Returns value from pq having the minimum key */
void* pq_pop(pq *head)
{
  void *p = head->ptr;
  head->ptr = NULL;
  return p;
  
}


/* Deallocates (frees) pq. Shallow destruction,
meaning nodes in the pq are not recursively freed. */
void pq_destroy(pq *head)
{
  free(head);
}



