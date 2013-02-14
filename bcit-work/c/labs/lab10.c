#include <stdio.h>
#include <string.h>
#include <ctype.h>

int *arr_last_max(const int *a, size_t n);
size_t str_replace_all(char *s, int oldc, int newc);
char *str_find_last(const char *s, int c);

int main(void)
{
	int a[] = {3, 2, 7, 6, 8};
	int b[] = {8, 6, 7, 2, 3};
	int c[] = {3, 2, 8, 7, 6, 8};
	
	char d[] = "Hello";
	char e[] = "World";
	char f[] = "Goodbye";
	
	printf("%d\n\n", arr_last_max(c, 5)-c);
	
	printf("%d\n", str_replace_all(d, 'l', 'x') == 2);
	printf("%d\n", str_replace_all(e, 'W', 'M') == 1);
	printf("%d\n\n", str_replace_all(f, 'o', 'u') == 2);
	
	printf("%d\n", str_find_last(d, 'o')-d == 4);
	printf("%d\n", str_find_last(e, 'r')-e == 2);
	printf("%d\n", str_find_last(f, 'y')-f == 5);
	
	return 0;
}

/*
	- returns a pointer to the last largest integer in the integer array a of n
	  elements;
	- precondition: n >= 1
*/
int *arr_last_max(const int *a, size_t n)
{
	int max = a[0];
	int *maxPtr = &max;
	const int *p;
	
	for(p = a; p < a + n; p++)
	{
		if(*p > *maxPtr)
		{
			*maxPtr = *p;
		}
	}
	
	return (int *)maxPtr;
}

/*
	- replaces all occurences of the character oldc in the string s by the character
	  newc
	- returns the number of replacements
*/
size_t str_replace_all(char *s, int oldc, int newc)
{
	char *p;
	size_t numReplacements = 0;
	
	for(p = s; *p != '\0'; p++)
	{
		if(*p == oldc)
		{
			*p = newc;
			numReplacements++;
		}
	}
	
	return numReplacements;
}

/*
	- returns a pointer to the last occurence of the character c in the string s
	  if found; otherwise returns the null pointer
*/
char *str_find_last(const char *s, int c)
{
	const char *p;
	const char *q = 0;
	
	for(p = s; *p != '\0'; p++)
	{
		if(*p == c)
		{
			q = p;
		}
	}
	
	return (char *)q;
}


