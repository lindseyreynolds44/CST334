// Name: Lindsey Reynolds
// Date: 04/07/20
// Title: Lab 5 – Step 1
// Description: This program creates 10 threads
// using for loops, but contains a critical bug.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *go(void *);
pthread_t threads;

int main()
{
    int i = 12;

    pthread_create(&threads, NULL, go, &i);

    printf("Thread %d returned\n", i);
    pthread_join(threads, NULL);

    printf("Main thread done.\n");
    return 0;
}
void *go(void *arg)
{
    printf("Hello from thread %d with iteration %d\n", (int)pthread_self(), *(int *)arg);
    return 0;
}