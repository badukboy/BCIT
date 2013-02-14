#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NLINES 256
#define LINESIZE 128

int ascending(const void *p, const void *q);
int descending(const void *p, const void *q);

int main(int argc, char *argv[])
{
	char lines[NLINES][LINESIZE];
	char buffer[LINESIZE];
	int numberOfLines = 0;
	int i = 0;
	
	while(fgets(buffer, LINESIZE, stdin))
	{
		if(numberOfLines <= NLINES)
		{	
			strcpy(lines[numberOfLines], buffer);
			
			numberOfLines++;
		}
		else
		{
			break;
		}
	}
	
	printf("\n");
	
	if(argc == 2)
	{
		if(argv[1][1] == 'r')
		{
			qsort(lines, numberOfLines, sizeof(lines[0]), descending);
		}
	}
	else
	{
		qsort(lines, numberOfLines, sizeof(lines[0]), ascending);
	}
	
	for(i = 0; i < numberOfLines; i++)
	{
		printf("%s", lines[i]);
	}
	
	return 0;
}

int ascending(const void *p, const void *q)
{
	return (*(char*)p - *(char*)q);
}

int descending(const void *p, const void *q)
{
	return (*(char*)q - *(char*)p);
}
