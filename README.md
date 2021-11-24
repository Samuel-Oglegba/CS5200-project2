# CS5200-project2

## building test file

 gcc main.c pq.h pq-null.c -o test.exe
  ./test.exe

  gcc sieve.c -o sieveExecutable


  #### Task 1 #########
  gcc -O2 main.c pq.h pq-minheap.c -o pq-minheap

  ########## Task 2 ############
  gcc -O2 main.c pq.h pq-minheap.c -S pq-minheap
