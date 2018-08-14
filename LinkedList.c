//BY MIGUEL CHAVARRIA UIN 652215109 mchava1@uic.edu
#include <string.h>
#include "LinkedList.h"

int delete(struct Node **ptr,int number,int boolean,int dflag)
{
	if(dflag)	
		printf("Entering delete\n");
	if(*ptr == NULL)
	{
		if(dflag)
			printf("Leaving delete\n");	
		if(boolean)
			return 1;
		else
			return 0;
	}	
	if((*ptr)->number!=number && (*ptr)->next == NULL)
	{
		if(dflag)
			printf("Leaving delete\n");
		if(boolean)					
			return 1;
		else
			return 0;
	}	
	if((*ptr)->number!=number && boolean == 1)
	{
		if(dflag)
			printf("Leaving delete\n");		
		return 1;
	}	
	if((*ptr)->number == number)
	{
		struct Node *temp;
		temp = *ptr;
		
		if((*ptr)->next != NULL)
		{
			*ptr = (*ptr)->next;
			free(temp);
			if(dflag)
				printf("Leaving delete\n");	
			return delete(ptr,number,1,dflag);
		}
		else if((*ptr)->next==NULL)
		{
			free(temp);
			*ptr = NULL;
			if(dflag)
				printf("Leaving delete\n");	
			return 1;
		}			
	}
	if(dflag)
		printf("Leaving delete\n");	
	return delete(&((*ptr)->next),number,0,dflag);	
}	





void insert(struct Node **ptr,int number,int dflag)
{
	//struct Node *iterator = *ptr;
	if(dflag)
		printf("Entering insert\n");
	//Node *tempPtr = *ptr;
	if(*ptr==NULL)
	{
		struct Node * temp = (struct Node *)malloc(1*sizeof(struct Node));
		temp->number = number;
		temp->next = NULL;
		*ptr = temp;
	}
	else if((*ptr)->number <= number && (*ptr)->next==NULL)
	{
		struct Node *temp = (struct Node *)malloc(1*sizeof(struct Node));
		temp->number = number;
		temp->next = NULL;
		(*ptr)->next = temp;
	}
	else if((*ptr)->number > number)
	{
		struct Node * temp = (struct Node *)malloc(1*sizeof(struct Node));
		temp->number = number;
		temp->next = *ptr;
		*ptr = temp;	
	}
	else if((*ptr)->number <= number && (*ptr)->next != NULL)
	{
		//iterator = iterator->next;	
		insert(&((*ptr)->next),number,dflag);
	}	
	
	if(dflag)
		printf("Leaving insert\n");
	return;			
}

void empty(struct Node **ptr,int dflag)
{
	if(dflag)
		printf("Entering empty\n");
	if(*ptr==NULL)
	{	
		if(dflag)
			printf("Leaving empty\n");
		return;
	}	
	struct Node * temp = *ptr;
	*ptr = (*ptr)->next;
	free(temp);
	if(dflag)
		printf("Leaving empty\n");
	empty(ptr,dflag);
}

int contains(struct Node *ptr,int number,int dflag)
{
	if(dflag)
		printf("Just entered contains\n");
	if(ptr==NULL)
	{
		if(dflag)
			printf("Leaving contains\n");	
		return 0;
	}	
	if(ptr->number == number)
	{	
		if(dflag)
			printf("Leaving contains\n");
		return 1;
	}	
	if(dflag)
		printf("Leaving contains\n");
	return contains(ptr->next,number,dflag);
}	

void list(struct Node *ptr,int dflag)
{
	if(dflag)
		printf("Just entered list\n");
	if(ptr==NULL)
	{	
		if(dflag)
			printf("Leaving list\n");
		return;
	}	
	if(dflag)
		printf("Leaving list\n");
	printf(" %d\n",ptr->number);
	list(ptr->next,dflag);
}
	
void listReverse(struct Node *ptr,int dflag)
{
	if(dflag)
		printf("Just entered listReverse\n");
	if(ptr==NULL)
	{
		if(dflag)
			printf("Leaving listReverse\n");	
		return;
	}
	if(dflag)
		printf("Leaving listReverse\n");	
	listReverse(ptr->next,dflag);
	printf(" %d\n",ptr->number);
	if(dflag)
		printf("Leaving listReverse\n");
}	