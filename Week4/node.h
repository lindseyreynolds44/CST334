// Name: Lindsey Reynolds
// Date: 03/31/20
// Title: Lab 4 – node header file
// Description: This file defines the node struct

#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

struct node* createNode(int data);
int getNodeData(struct node* n);
struct node* getNodeNext(struct node* n);
void destroyNode(struct node* n);

#endif // NODE_H //
