// Name: Lindsey Reynolds
// Date: 04/07/20
// Title: Lab 5 – Step 1
// Description: This program creates 10 threads
// using for loops, but contains a critical bug.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *go(void *);
#define NTHREADS 10
pthread_t threads[NTHREADS];
int main()
{
    int i;
    for (i = 0; i < NTHREADS; i++)
    {
        pthread_create(&threads[i], NULL, go, &i);
    }

    for (i = 0; i < NTHREADS; i++)
    {
        printf("Thread %d returned\n", i);
        pthread_join(threads[i], NULL);
    }

    printf("Main thread done.\n");
    return 0;
}
void *go(void *arg)
{
    printf("Hello from thread %d with iteration %d\n", (int)pthread_self(), *(int *)arg);
    return 0;
}