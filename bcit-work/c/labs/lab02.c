#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
	returns 1 if the string s consists entirely of alphabets; otherwise, returns 0
*/
int str_all_alphabets(const char s[]);

/*
	returns 1 if the string s contains an alphabet; otherwise, returns 0
*/
int str_has_alphabet(const char s[]);

/*
	replaces all occurrences of the character oldc in the string s by the character newc
	returns the number of replacements
*/
size_t str_replace_all(char s[], int oldc, int newc);

/*
	replaces only the first occurrence of oldc in the string s by newc
	returns 1 if a replacement has been made; otherwise returns 0
*/
int str_replace_first(char s[], int oldc, int newc);

/*
	replaces only the last occurrence of oldc in the string s by newc
	returns 1 if a replacement has been made; otherwise returns 0
*/
int str_replace_last(char s[], int oldc, int newc);

int main(void)
{
	char s1[] = "hello";
	char s2[] = "he11o";
	char s3[] = "helloWORLD";
	char s4[] = "123456789";
	
	/* Testing str_all_alphabets() */
	printf("%d\n", str_all_alphabets(s1) == 1);
	printf("%d\n", str_all_alphabets(s2) == 0);
	printf("%d\n\n", str_all_alphabets(s3) == 1);
	
	/* Testing str_has_alphabet() */
	printf("%d\n", str_has_alphabet(s1) == 1);
	printf("%d\n", str_has_alphabet(s3) == 1);
	printf("%d\n\n", str_has_alphabet(s4) == 0);
	
	/* Testing str_replace_all() */
	printf("%d\n", str_replace_all(s1, 'l', 'x') == 2);
	printf("%d\n", str_replace_all(s3, 'W', 'P') == 1);
	printf("%d\n\n", str_replace_all(s4, '9', '1') == 1);
	
	/* Testing str_replace_first() */
	printf("%d\n", str_replace_first(s1, 'h', 'j') == 1);
	printf("%d\n", str_replace_first(s2, 'j', 'e') == 0);
	printf("%d\n\n", str_replace_first(s3, 'o', 'y') == 1);
	
	/* Testing str_replace_last() */
	printf("%d\n", str_replace_last(s1, 'e', 'j') == 1);
	printf("%d\n", str_replace_last(s1, 'o', 'j') == 1);
	printf("%d\n\n", str_replace_last(s4, '0', 'a') == 0);
	
	return 0;
}

int str_all_alphabets(const char s[])
{
	size_t i;
	
	for(i = 0; s[i] != '\0'; i++)
	{
		if(!isalpha((int)s[i]))
		{
			return 0;
		}
	}
	
	return 1;
}

int str_has_alphabet(const char s[])
{
	size_t i;
	
	for(i = 0; s[i] != '\0'; i++)
	{
		if(isalpha((int)s[i]))
		{
			return 1;
		}
	}
	
	return 0;
}

size_t str_replace_all(char s[], int oldc, int newc)
{
	size_t i;
	int numReplacements = 0;
	
	for(i = 0; s[i] != '\0'; i++)
	{
		if(s[i] == oldc)
		{
			s[i] = newc;
			numReplacements++;
		}
	}
	
	return numReplacements;
}

int str_replace_first(char s[], int oldc, int newc)
{
	size_t i;
	
	for(i = 0; s[i] != '\0'; i++)
	{
		if(s[i] == (char)oldc)
		{
			s[i] = (char)newc;
			
			return 1;
		}
	}
	
	return 0;
}

int str_replace_last(char s[], int oldc, int newc)
{
	size_t i;
	int index = -1;
	
	for(i = 0; i != '\0'; i++)
	{
		if(s[i] == oldc)
		{
			index = i;
			
		}
	}
	
	if(index != -1)
	{
		s[index] = newc;
		
		return 1;
	}

	return 0;
}
