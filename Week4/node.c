// Name: Lindsey Reynolds
// Date: 03/31/20
// Title: Lab 4 – node file
// Description: This file implements the functionality of a node

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node* createNode(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int getNodeData(struct node* n){
    return n->data;
}

struct node* getNodeNext(struct node* n){
    return n->next;
}

void destroyNode(struct node* n){
    free(n);
}