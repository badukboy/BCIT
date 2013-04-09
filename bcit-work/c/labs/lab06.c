#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LINESIZE 1024

int is_permutation(unsigned long n1, unsigned long n2);
int is_permutation_no_strings(unsigned long n1, unsigned long n2);
int is_staggering(unsigned long n);

int main(void)
{
	unsigned long n1 = 743526;
	unsigned long n2 = 237654;
	
	unsigned long n3 = 743526;
	unsigned long n4 = 123765;
	
	unsigned long n5 = 66666;
	unsigned long n6 = 144358;
	
	unsigned long myN = 0;
	int myCount = 0;
	
	printf("%d\n", is_permutation(n1, n2) == 1);
	printf("%d\n\n", is_permutation_no_strings(n1, n2) == 1);
	
	printf("%d\n", is_permutation(n3, n4) == 0);
	printf("%d\n\n", is_permutation_no_strings(n3, n4) == 0);
	
	printf("%d\n", is_staggering(n5) == 1);
	printf("%d\n", is_staggering(n6) == 1);
	printf("%d\n", is_staggering(n1) == 0);
	
	for(myN = 100; myN < 1000000; myN++)
	{
		if(is_staggering(myN) == 0)
		{
			myCount++;
		}
	}
	
	printf("%d", myCount+100);

	return 0;
}

int is_permutation(unsigned long n1, unsigned long n2)
{
	char str1[LINESIZE];
	char str2[LINESIZE];
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int n;
	size_t i, j, k;
	
	sprintf(str1, "%lu", n1);
	sprintf(str2, "%lu", n2);

	for(i = 0; i < strlen(str1); i++)
	{
		n = str1[i] - '0';
		count[n]++;
	}
	
	for(j = 0; j < strlen(str2); j++)
	{
		n = str2[j] - '0';
		count[n]--;
	}
	
	for(k = 0; k < 10; k++)
	{
		if(count[k] != 0)
		{
			return 0;
		}
	}
	
	return 1;
}

int is_permutation_no_strings(unsigned long n1, unsigned long n2)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t k;

	while(n1 != 0)
	{
		count[n1 % 10]++;
		n1 /= 10;
	}
	
	while(n2 != 0)
	{
		count[n2 % 10]--;
		n2 /= 10;
	}
	
	for(k = 0; k < 10; k++)
	{
		if(count[k] != 0)
		{
			return 0;
		}
	}
	
	return 1;
}

int is_staggering(unsigned long n)
{
	int currentInt = 0;
	int previousInt = -1;
	int first = 1;
	int increasingFlag = 0;
	int decreasingFlag = 0;

	while (n != 0)
	{
		currentInt = n % 10;
		n /= 10;
		if (first)
		{
			previousInt = currentInt;
			first = 0;
			continue;
		}
		
		if(previousInt > currentInt)
		{
			decreasingFlag = 1;
		}
		
		if(previousInt < currentInt)
		{
			increasingFlag = 1;
		}
		
		previousInt = currentInt;
	}
	
	return increasingFlag && decreasingFlag;
}
