#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NAMESIZE 20
#define LINESIZE 1024

typedef struct name name;
struct name
{
	char last[NAMESIZE];			/* last name */
	char first[NAMESIZE];			/* first name */
};

typedef struct record record;
struct record
{
	name name;
	int score;
};

typedef struct node node;
struct node							/* a node of the linked list */
{
	record data;
	node *next;
};

typedef node *record_list;			/* a record_list is represented by the pointer to the first node */

void list_init(record_list *list);
void list_destroy(record_list *list);
int list_insert(record_list *list, const record *rec);
void list_print(record_list list);
int input_record(record *rec);

int main(void)
{
	record_list list;
	record r;
	int n;
	list_init(&list);
	
	while((n = input_record(&r)) != 0)
	{
		if(n == 1)
		{
			if(!list_insert(&list, &r))
			{
				break;
			}
		}
	}
	
	list_destroy(&list);
	
	return 0;
}

void list_init(record_list *list)
{
	node *p;

	for(p = *list; p != 0; p = p -> next)
	{
		p = 0;
	}
}

void list_destroy(record_list *list)
{
	node *p, *q;
	
	for(p = *list; p != 0; p = q)
	{
		q = p -> next;
		free(p);
	}
}

int list_insert(record_list *list, const record *rec)
{	
	node **tracer;
	node *newnode = malloc(sizeof(node));
	if(newnode == 0)
	{
		return 0;
	}
	newnode -> rec = rec;
	for(tracer = list; *tracer != 0; tracer = &(*tracer) -> next)
	{
		if((*tracer) -> rec >= rec)
		{
			break;
		}
	}
	newnode -> next = *tracer;
	*tracer = newnode;
	return 1;
}

int input_record(record *rec)
{
	char userInput[LINESIZE];
	int inputValidation;
	
	char firstName[LINESIZE];
	char lastName[LINESIZE];
	int studentScore;
	
	if(!fgets(userInput, LINESIZE, stdin))
	{
		/* Error: EOF */
		return 0;
	}
	
	if((inputValidation = sscanf(userInput, "%[a-zA-Z-] %[a-zA-Z-] %d", firstName, lastName, &studentScore)) == 3)
	{
		inputValidation = 0;
				
		if(strlen(firstName) < NAMESIZE)
		{
			inputValidation++;
			strcpy(rec -> name.first, firstName);
		}
				
		if(strlen(lastName) < NAMESIZE)
		{
			inputValidation++;
			strcpy(rec -> name.last, lastName);
		}
				
		if(studentScore >= 0 && studentScore <= 100)
		{
			inputValidation++;
			rec -> score = studentScore;
		}
				
		if(inputValidation != 3)
		{
			/* Error: invalid input */
			return -1;
		}
				
		return 1;
	}
	
	/* Error: EOF */
	return 0;
}
