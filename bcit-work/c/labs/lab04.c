#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LINESIZE 1024

int get_last_first(FILE *fp);
int get_first_last(FILE *fp);

int main(void)
{
	int i, n;
	double d;
	char s1[32], s2[32];
	
	n = sscanf("hello", "%4s", s1);
	printf("A: %d conversions\n", n);
	n = sscanf("12345 32 12abc", "%2d %lf %*d %s", &i, &d, s1);
	printf("B: %d conversions\n", n);
	n = sscanf("12 / 345", "%d/%lf", &i, &d);
	printf("C: %d conversions\n", n);
	n = sscanf("12/345", "%d/%lf", &i, &d);
	printf("D: %d conversions\n", n);
	n = sscanf("dos2unix", "%[a-z] %s", s1, s2);
	printf("E: %d conversions\n", n);
	
	printf("Please enter your name, starting with your last name:\n");
	get_last_first(stdin);
	
	printf("Please enter your name, starting with your first name:\n");
	get_first_last(stdin);

	return 0;
}

int get_last_first(FILE *fp)
{
	char line[LINESIZE];
	char firstName[LINESIZE];
	char lastName[LINESIZE];
	int n;
	
	if(!fgets(line, LINESIZE, fp))
	{
		clearerr(fp);
		
		printf("Input error\n");
		
		return 0;
	}
		
	if((n = sscanf(line, " %[a-zA-Z-] , %[a-zA-Z-] ", lastName, firstName)) == 2)
	{
		printf("%s %s\n", firstName, lastName);
		
		return 1;
	}
		
	printf("Invalid input\n");
	
	return -1;
}

int get_first_last(FILE *fp)
{
	char line[LINESIZE];
	char firstName[LINESIZE];
	char lastName[LINESIZE];
	int n;
	
	if(!fgets(line, LINESIZE, fp))
	{
		clearerr(fp);
		
		printf("Input error\n");
		
		return 0;
	}
		
	if((n = sscanf(line, " %[a-zA-Z-] %[a-zA-Z-] ", firstName, lastName)) == 2)
	{
		printf("%s %s\n", lastName, firstName);
		
		return 1;
	}
		
	printf("Invalid input\n");
	
	return -1;
}
