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
	char *a[NLINES];
	int numberOfLines = 0;
	int i = 0;
	
	while(fgets(buffer, LINESIZE, stdin))
	{
		if(numberOfLines <= NLINES)
		{	
			strcpy(lines[numberOfLines], buffer);
			a[numberOfLines] = lines[numberOfLines];
			
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
			qsort(a, numberOfLines, sizeof(a[0]), descending);
		}
	}
	else
	{
		qsort(a, numberOfLines, sizeof(a[0]), ascending);
	}
	
	for(i = 0; i < numberOfLines; i++)
	{
		printf("%s", a[i]);
	}
	
	return 0;
}

int ascending(const void *p, const void *q)
{
	char **pp = (char **)p;
	char **qq = (char **)q;
	return strcmp(*pp, *qq);
}

int descending(const void *p, const void *q)
{
	char **pp = (char **)p;
	char **qq = (char **)q;
	return strcmp(*qq, *pp);
}
