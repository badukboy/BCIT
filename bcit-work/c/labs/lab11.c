#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define NAMESIZE 20
#define LINESIZE 1024

typedef struct name name;
struct name
{
	char last[NAMESIZE];	/* last name */
	char first[NAMESIZE];	/* first name*/
};

typedef struct record record;
struct record
{
	name name;
	int score;
};

typedef struct record_list record_list;
struct record_list
{
	record *data;	/* the dynamic array of records */
	size_t nalloc;	/* number of records allocated */
	size_t nused;	/* number of records in use */
};

void list_init(record_list *list);
void list_destroy(record_list *list);
int list_insert(record_list *list, const record *rec);
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
	list -> data = 0;
	list -> nalloc = 0;
	list -> nused = 0;
}

void list_destroy(record_list *list)
{
	free(list);

	list -> data = 0;
	list -> nalloc = 0;
	list -> nused = 0;
}

int list_insert(record_list *list, const record *rec)
{	
	size_t newSize;
	record *tmp;
	
	if(list -> nalloc == list -> nused)
	{
		if(list -> nalloc == 0)
		{
			newSize = 1;
		}
		else
		{
			newSize = 2 * list -> nalloc;
		}
		
		tmp = realloc(list -> data, newSize * sizeof(record));
			
		if(tmp == 0)
		{
			return 0;
		}
		
		list -> data = tmp;
		list -> nalloc = newSize;
	}
	
	list -> data[list -> nused++] = *rec;
		
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
