
typedef struct pq pq;


/* Allocates and initializes a new pq */
pq* pq_create();

/* Adds value to pq based on numerical order of key */
void pq_push(pq *head, double key, void *value);

/* Returns value from pq having the minimum key */
void* pq_pop(pq *head);

/* Deallocates (frees) pq. Shallow destruction,
meaning nodes in the pq are not recursively freed. */
void pq_destroy();

pq* heapify(pq* head, int index);

int right_child(int i);

int left_child(int i);

int parent(int i);

//void print_heap(pq* heap);
//void print_link(pq *head);
//void InsertionSort(pq *head);

