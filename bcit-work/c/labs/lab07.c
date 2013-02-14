#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LINESIZE 1024

int get_word(const char prompt[], char word[], size_t n);
int get_int(const char prompt[], int min, int max, int *pnum);

int main(void)
{
	int theNumber;
	char inputPrompt[] = ">";
	int n = 12345567;
	char word1[5];
	char word2[7];
	char word3[13];
	
	/*
	printf("Enter a word:\n");
	get_word(inputPrompt, word1, 5);
	printf("%s\n", word1);
	printf("Enter a word:\n");
	get_word(inputPrompt, word2, 7);
	printf("%s\n", word2);
	printf("Enter a word:\n");
	get_word(inputPrompt, word3, 13);
	printf("%s\n", word3);
	*/
	
	printf("Enter an integer\n");
	get_int(inputPrompt, 0, 10, &theNumber);
	printf("%d\n", theNumber);
	printf("Enter an integer\n");
	get_int(inputPrompt, 0, 100, &theNumber);
	printf("%d\n", theNumber);
	printf("Enter an integer\n");
	get_int(inputPrompt, 5, 6, &theNumber);
	printf("%d\n", theNumber);
	
	return 0;
}

/*
	returns 0 on end-of-file, 1 if a word is successfully read & stored in the
	array word of n characters
*/
int get_word(const char prompt[], char word[], size_t n)
{
	char inputLine[LINESIZE];
	char inputWord[LINESIZE];
	int validation;
	
	printf("%s ", prompt);
	
	while(fgets(inputLine, LINESIZE, stdin) != NULL)
	{
		if((validation = sscanf(inputLine, "%s", inputWord)) == 1)
		{
			if((strlen(inputWord)) < n)
			{
				strcpy(word, inputWord);
				
				printf("Value of n: %d\n", n);
				printf("Good job!\n");
				
				return 1;
			}
			
			printf("Invalid input, please try again:\n");
			printf("%s ", prompt);
			
			continue;
		}
		
		printf("Invalid input, please try again:\n");
		printf("%s ", prompt);
	}
	
	printf("Goodbye!\n");
	clearerr(stdin);
	
	return 0;
}

/*
	returns 0 on end-of-file, 1 if an integer between min and max is successfully
	read & stored through the point pnum
*/

int get_int(const char prompt[], int min, int max, int *pnum)
{
	char inputLine[LINESIZE];
	int inputInteger;
	int validation;
	
	printf("%s ", prompt);
	
	while(fgets(inputLine, LINESIZE, stdin) != NULL)
	{
		if((validation = sscanf(inputLine, "%d", &inputInteger)) == 1)
		{
			if((inputInteger >= min) && (inputInteger <= max))
			{
				pnum = &inputInteger;
				
				printf("Good job!\n");
				
				return 1;
			}
			
			printf("Invalid input, please try again:\n");
			printf("%s ", prompt);
			
			continue;
		}
		
		printf("Invalid input, please try again:\n");
		printf("%s ", prompt);
			
		continue;
	}
	
	printf("Goodbye!\n");
	clearerr(stdin);
	
	return 0;
}
