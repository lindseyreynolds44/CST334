// Name: Lindsey Reynolds
// Date: 03/31/20
// Title: Lab 4 – FIFO file
// Description: This program reads in a file of "pages" and the 
// size of a cache and simulates a FIFO replacement policy cache. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "queue.h"
#include "node.h"

int main(int argc, char *argv[]){

	int MAX_CACHE = atoi(argv[1]); // Size of Cache passed by user 
    char pageCache[100]; // Cache that holds the input from test file
    int totalFaults = 0; // Keeps track of the total page faults
    int cache_length = 0; // Efficient way to keep track of the length of the cache
    int total_pages = 0; // Keeps track of how many pages are read in by the file
    struct queue* cache_queue = queue_create(); // The fifo queue

    while (fgets(pageCache, 100, stdin)){
    	int page_num = atoi(pageCache); // Stores number read from file as an int

        // Check if this page is not currently in the cache
        if(queue_find(cache_queue, page_num) == NULL){
            // Check if the cache is at max capacity
            if(cache_length >= MAX_CACHE){
                dequeue(cache_queue);
                enqueue(cache_queue, page_num);
            } 
            else {
                enqueue(cache_queue, page_num);
                cache_length++;
            }
            totalFaults++;
        }
        total_pages++;
    }

    // Free all the queue memory
    queue_destroy(cache_queue);

    printf("Total Pages Read: %d\n", total_pages);
    printf("Total Page Faults: %d\n", totalFaults);
    return 0;

}
