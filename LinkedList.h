//BY MIGUEL CHAVARRIA UIN 652215109 mchava1@uic.edu
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int number;
	struct Node *next;
};


int delete(struct Node **ptr,int number,int boolean,int dflag);
void insert(struct Node **ptr,int number,int dflag);
void empty(struct Node **ptr,int dflag);
int contains(struct Node *ptr,int number,int dflag);
void list(struct Node *ptr,int dflag);
void listReverse(struct Node *ptr,int dflag);