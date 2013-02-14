#include <stdio.h>

/* 
	Returns the value of the largest integer in the integer array a of n elements
	precondition: n >= 1 
*/
int array_max(const int a[], size_t n);

/*
	Returns the index of the largest integer in the integer array a or n elements;
	if the largest integer occurs more than once in the array, returns the inex of its
	first ocurrence
	precondition: n >= 1
*/
size_t array_index_of_first_max(const int a[], size_t n);

/* 
	Returns the index of the largest integer in the integer array a of n elements;
	if the largest integer ocurrs more than once in the array, returns the index of its
	last ocurrences
	precondition: n >= 1 
*/
size_t array_index_of_last_max(const int a[], size_t n);

/* 
	Returns 1 if all corresponding elements of the two arrays a & b, each containing
	n integers, are equal; otherwise, returns 0 
*/
int array_equal(const int a[], const int b[], size_t n);

int main(void)
{
	int a[] = {3, 2, 7, 8, 6};
	int b[] = {5, 8, 9, 13, 3};
	int c[] = {1, 2, 3, 4, 5};
	int d[] = {7, 7, 4, 6, 3};
	int e[] = {3, 2, 7, 8, 6};
	
	/* Testing array_max() */
	printf("%d\n", array_max(a, 5) == 8);
	printf("%d\n", array_max(b, 5) == 13);
	printf("%d\n\n", array_max(c, 5) == 5);
	
	/* Testing array_index_of_first_max() */
	printf("%d\n", array_index_of_first_max(a, 5) == 3);
	printf("%d\n", array_index_of_first_max(b, 5) == 3);
	printf("%d\n\n", array_index_of_first_max(d, 5) == 0);
	
	/* Testing array_index_of_last_max() */
	printf("%d\n", array_index_of_last_max(c, 5) == 4);
	printf("%d\n", array_index_of_last_max(d, 5) == 1);
	printf("%d\n\n", array_index_of_last_max(b, 5) == 3);
	
	/* Tesing array_equal() */
	printf("%d\n", array_equal(a, b, 5) == 0);
	printf("%d\n", array_equal(a, e, 5) == 1);
	printf("%d\n\n", array_equal(b, c, 5) == 0);
	
	return 0;
}

int array_max(const int a[], size_t n)
{
	int max = a[0];
	size_t i = 0;
	
	for(i = 0; i < n; i++)
	{
		if(a[i] > max)
		{
			max = a[i];
		}
	}
	
	return max;
}

size_t array_index_of_first_max(const int a[], size_t n)
{
	int max = a[0];
	size_t i = 0;
	size_t first_max_index = 0;
	
	for(i = 0; i < n; i++)
	{
		if(a[i] > max)
		{
			max = a[i];
			first_max_index = i;
		}
	}
	
	return first_max_index;
}

size_t array_index_of_last_max(const int a[], size_t n)
{
	int max = a[0];
	size_t i = 0;
	size_t last_max_index = 0;
	
	for(i = 0; i < n; i++)
	{
		if(a[i] >= max)
		{
			max = a[i];
			last_max_index = i;
		}
	}
	
	return last_max_index;
}

int array_equal(const int a[], const int b[], size_t n)
{
	size_t i = 0;
	
	for(i = 0; i < n; i++)
	{
		else
		if(a[i] != b[i])
		{
			return 0;
		}
	}
	
	return 1;
}
