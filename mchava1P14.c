//BY MIGUEL CHAVARRIA UIN 652215109 mchava1@uic.ed
#include "LinkedList.h"
#include <string.h>

void displayInstructions(void)
{
	printf("q - quit the program\n");
	printf("i <int1> - insert a integer value into the linked list\n");
	printf("d <int1> - delete the integer value from the linked list\n");
	printf("c <int1> - display a message stating whether the given integer value is contained in the link list\n");
	printf("e - empty all values from the link list\n");
	printf("l - list the items contained in the link list\n");
	printf("r - list the items contained in the link list in reverse order\n");
	printf("? - print the valid input commands\n\n");
}	

int getOneNumber(int * number1,char *copy)
{
	char *tok = copy;
	char *tok1;
	tok = strtok(tok, " ");
	tok1 = strtok(NULL, " ");
	if(tok1 == NULL)
		return 0;
	*number1 = atoi(tok1);
	if(number1 == NULL)
		return 0;
	free(tok);
	return 1;
	//free(tok1);
}

int main(int argc,char ** argv)
{
	int dflag = 0;
	if(argc!=1 && argc!=2)
	{
		printf("You did not enter your arguments in correctly when you ran this program.  This program will terminate\n");
		exit(0);
	}
	if(argc == 2)
	{
		if(strcmp(argv[1],"-d")!=0)
		{
			printf ("error - invalid arguement, program will terminate\n");
			exit(0); 
		}
		dflag = 1;
			
	}	
	struct Node *head;
	head = NULL;
	//int start, end;
	int boolean, aNumber;
	int booleanTwo;
	size_t len = 25;
	char * line = (char *)malloc(len*sizeof(char));
	ssize_t read;
	int proceed = 1;
	printf("In this program you enter numbers in a link list:\n");
	displayInstructions();
	
	while (proceed)
	{
		read = getline(&line, &len, stdin);
		char * copy = (char *)malloc((read+1)*sizeof(char));
		strcpy(copy,line);
		//free(line);
		char choice = copy[0];
		switch (choice)
		{
			case 'q':
			proceed = 0;
			empty(&head,dflag);
			break;
			case 'i':
			boolean = getOneNumber(&aNumber,copy);
			if(!boolean)
			{
				printf("You did not type in a correct option.  Try again.\n");
				break;
			}
			insert(&head,aNumber,dflag);
			break;
			case 'd':
			boolean = getOneNumber(&aNumber,copy);
			if(!boolean)
			{
				printf("You did not type in a correct option.  Try again.\n");
				break;
			}
			booleanTwo = delete(&head,aNumber,booleanTwo,dflag);
			if(!booleanTwo)
			{
				printf("That number is not in the list. \n");
				break;
			}	
			booleanTwo = 0;
			break;
			case 'c':
			boolean = getOneNumber(&aNumber,copy);
			if(!boolean)
			{
				printf("You did not type in a correct option.  Try again.\n");
				break;
			}
			booleanTwo = contains(head,aNumber,dflag);
			if(booleanTwo)
				printf("The number: %d, is IN the list\n",aNumber);
			else
				printf("The number: %d, is NOT in the list\n",aNumber);
			break;
			case 'e':
			empty(&head,dflag);
			break;
			case 'l':
			list(head,dflag);
			break;
			case 'r':
			listReverse(head,dflag);
			break;
			case '?':
			displayInstructions();
			break;
					
			default:
			printf("You did not type in a correct option.  Try again.\n");
			break;
		}	
	}
}	