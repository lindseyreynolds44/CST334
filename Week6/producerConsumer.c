// Name: Lindsey Reynolds
// Date: 04/14/20
// Title: Lab 6 – producerConsumer 
// Description: This program demonstrates the utility of semaphores
// to create producer and consumer threads. The producer thread adds
// the letters of the alphabet to a buffer and the consumer reads
// them out of the buffer, whenever there are letters to read. 
// NOTE: I wrote this to be run on a Mac.

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// Define function headers 
void *producer(void *);
void *consumer();
void put(char);
char get();

// Define global variables 
#define N 26
pthread_t consumer_thread, producer_thread;
sem_t *mutex, *full, *empty; //semaphores
char buffer[N];
int put_index = 0;
int get_index = 0;

int main()
{
    // Initialize the semaphores
    mutex = sem_open("lock", O_CREAT, 0644, 1);
    full = sem_open("full", O_CREAT, 0644, 0);
    empty = sem_open("empty", O_CREAT, 0644, N);

    // Create the producer's input
    char input[] = "abcdefghijklmnopqrstuvwxyz";

    // Create the producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, &input);
    pthread_create(&consumer_thread, NULL, consumer, NULL); 
    
    // Wait until each thread has finished running;
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    printf("Main thread done.\n");

    // Drop the semaphores when finished
    sem_unlink("lock");
    sem_unlink("full");
    sem_unlink("empty");

    return 0;
}

/**
 * Add each letter of the alphabet into the buffer
 * param: the char array containing the alphabet
 */
void *producer(void *arg) {
    char *input = (char *) arg;
    int i = 0;
    char letter;
    
    while(input[i] != '\0')
    {
        letter = input[i];
        printf("Produced: %c\n", letter);
        sem_wait(empty);
        sem_wait(mutex);

        // Add the letter to the buffer
        put(letter);

        sem_post(mutex);
        sem_post(full);
        i++;
    }
}

/**
 * Read each letter of the alphabet from the buffer, as the
 * producer thread adds more letters. 
 */
void *consumer() {
    char letter = '\0';
    int count = 0;
    while(count < N){
        sem_wait(full);
        sem_wait(mutex);

        // Remove next letter from the buffer
        letter = get();

        sem_post(mutex);
        sem_post(empty);

        // Consume the item
        printf("Consumed: %c\n", letter);
        count++;
    }
}

/**
 * Add a letter to the buffer
 * param: the letter to be added
 */
void put(char c)
{
    buffer[put_index] = c;
    put_index = (put_index + 1) % N;
}

/**
 * Remove a letter from the buffer
 * return: the letter
 */
char get()
{
    char temp = buffer[get_index];
    buffer[get_index] = '\0';
    get_index = (get_index + 1) % N;
    return temp;
}
