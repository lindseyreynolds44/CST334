// Name: Lindsey Reynolds
// Date: 03/31/20
// Title: Lab 4 – queue file
// Description: This file implements the functionality of a fifo queue

#include <stdint.h>
#include <stdbool.h>
#include "queue.h"
#include "node.h"

struct queue* queue_create(){
    struct queue* temp = (struct queue*)malloc(sizeof(struct queue));
    temp->head = NULL;
    temp->tail = NULL;
    return temp;
}

/**
* Adds a node to the end of the queue
* q: the queue 
* data: the data to be added into the new node
* returns: a pointer to the node that was just added
*/
struct node* enqueue(struct queue* q, int data){
    struct node* tempNode = createNode(data);

    //Check if the head node has a value
    if (q->head == NULL){
        q->head = tempNode;
    } 
    //Check if the tail node has a value
    else if (q->tail == NULL){
        q->tail = tempNode;
        q->head->next = tempNode;
    } 
    //If the head and tail have values, add to the end
    else {
        q->tail->next = tempNode;
        q->tail = tempNode;
    }
    return tempNode;
}

/**
* Deletes the node at the beginning of the queue
* q: the queue 
*/
void dequeue(struct queue* q){
    struct node* headNode = q->head;
    
    if(headNode != NULL){
        q->head = getNodeNext(headNode);
        destroyNode(headNode);
    }
}

/**
* Gets the length of the queue by counting all the nodes
* q: the queue 
* returns: the length of the queue
*/
int queue_length(struct queue* q){
    struct node* currNode = q->head;
    int sum = 0;

    while(currNode != NULL){
        sum++;
        currNode = getNodeNext(currNode);
    }
    return sum;
}

/**
* Traverses over the queue, printing the data from each node
* q: the queue 
*/
void queue_traverse(struct queue* q){
    struct node* currNode = q->head;
    int index = 0;

    while(currNode != NULL){
        printf("%d %d\n", index, getNodeData(currNode));
        currNode = getNodeNext(currNode);
        index++;
    }
}

/**
* Deletes all nodes from the queue
* q: the queue 
*/
void queue_destroy(struct queue* q){
    struct node* currNode = q->head;
    struct node* nextNode;

    //Loop through the queue, destroying each node
    while(currNode != NULL){
        nextNode = getNodeNext(currNode);
        destroyNode(currNode);
        currNode = nextNode;
    }
    q->head = NULL;
}

/**
* Gets the length of the queue by counting all the nodes
* q: the queue 
* returns: the length of the queue
*/
struct node* queue_find(struct queue* q, int data){
    struct node* currNode = q->head;

    //Scan through queue to find data
    while(currNode != NULL){
        if(getNodeData(currNode) == data){
            return currNode;
        }
        currNode = getNodeNext(currNode);;
    }
    return NULL;
}

void queue_delete(struct queue* q, int data){
    struct node* firstNode = q->head;
    struct node* nextNode;
    bool found = false;

    //Check head node
    if (firstNode != NULL && getNodeData(firstNode) == data){
            destroyNode(firstNode);
            found = true;
        }

    //Search through the rest of the queue
    while(firstNode != NULL && found == false){
        nextNode = getNodeNext(firstNode);
        if (getNodeData(firstNode) == data){

            destroyNode(firstNode);
            found = true;
        }
        //Move to the next node in the queue
        firstNode = getNodeNext(firstNode);
    }
}

