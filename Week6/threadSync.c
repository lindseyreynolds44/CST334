// Name: Lindsey Reynolds
// Date: 04/14/20
// Title: Lab 6 – threadSync
// Description: This program demonstrates the ability to use a
// binary semaphore in order to create concurrent threads in a 
// process without introducing race conditions

/*********************************************************************
*   threadSyn.c - simple multi-threaded programi with sychronization.*
*   compile with: >gcc -lpthread threadSyn.c -o threadSyn            *
*   Lab6 Step 1                                                     *
*********************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NTHREADS 10
pthread_t threads[NTHREADS];
sem_t *mutex;

void *go(void *arg)
{
  sem_wait(mutex); //entry section -- if mutex != 1, nothing happens
 
  //Here is the critical section of code, but nothing is shared actually, so nothing is critical
  printf("Thread %lu Entered Critical Section..\n", (size_t)arg); //critical section
  sleep(1);
  printf("Thread %lu Finished Critical Section..\n", (size_t)arg);

  sem_post(mutex); //exit section - now the mutex is incremented to 1 from 0

  return (NULL);
}

int main()
{
  //initialize a binary semaphore with value 1
  mutex = sem_open("semaphore", O_CREAT, 0644, 1);

  static int i;
  for (i = 0; i < NTHREADS; i++)
    pthread_create(&threads[i], NULL, go, (void *)(size_t)i); //the last arg is the arg of go
  
  for (i = 0; i < NTHREADS; i++)
  {
    pthread_join(threads[i], NULL);
    printf("Thread %d returned \n", i);
  }

  printf("Main thread done.\n");

  //drop the semaphone when finished.
  sem_unlink("semaphore");

  return 0;
}
