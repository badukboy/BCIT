#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LINESIZE 1024

int menu(const char * choices[], const char * prompt);
int enterData(FILE * fileInput, FILE * standardInput, const char * prompt);
int displayData(FILE * fileInput);

int main(void)
{
	FILE * fp;
	const char * choices[] = {"Enter data", "Display data", "Quit", 0};
	int menuChoice;
	
	if((fp = fopen("data.txt", "w+")) == 0)
	{
		perror("fopen");
		
		return 1;
	}
	
	while((menuChoice = menu(choices, "> ")) != 3)
	{
		switch(menuChoice)
		{
			case 1:
				printf("Entering data...\n");
				while((enterData(fp, stdin, "> ")) == 1)
				{
				}
				break;
			case 2:
				printf("Displaying data...\n");
				displayData(fp);
				break;
			default:
				break;
		}
	}
	
	printf("Quitting program...");

	fclose(fp);
	
	return 0;
}

/* Displays an interactive main menu for the program */
int menu(const char * choices[], const char * prompt)
{
	size_t i;
	int validation;
	
	int menuCounter = 1;
	char userChoice[LINESIZE];
	int userIntChoice;
	
	for(i = 0; choices[i] != 0; i++, menuCounter++)
	{
		printf("%d. %s\n", menuCounter, choices[i]);
	}
	
	printf("Please pick a menu option:\n");
	printf("%s", prompt);
	
	while(fgets(userChoice, LINESIZE, stdin) != NULL)
	{
		if((validation = sscanf(userChoice, "%d", &userIntChoice)) == 1)
		{
			if((userIntChoice > 0) && (userIntChoice < menuCounter))
			{
				return userIntChoice;
			}
			
			printf("*** ERROR: Invalid option! *** \n");
			printf("Please pick a menu option:\n");
			printf("%s", prompt);
			continue;
		}
		
		printf("*** ERROR: Invalid option! ***\n");
		printf("Please pick a menu option:\n");
		printf("%s", prompt);
	}
	
	clearerr(stdin);
	
	return 0;
}

/* Lets the user enter student names to the text file */
int enterData(FILE * fileInput, FILE * standardInput, const char * prompt)
{
	char inputLine[LINESIZE];
	char firstName[LINESIZE];
	char lastName[LINESIZE];
	int studentScore;
	int validation;
	int junk;
	
	printf("Please enter a student name (type !! to quit):\n");
	printf("%s", prompt);
	
	while(fgets(inputLine, LINESIZE, standardInput) != NULL)
	{
		/* Validation format is an error if there are numbers in the name */
		if((validation = sscanf(inputLine, " %[a-zA-Z-] %[a-zA-Z-] %d ", firstName, lastName, &junk)) == 3)
		{
			printf("*** ERROR: Invalid name! ***\n");
			
			printf("Please enter a student name (type !! to quit):\n");
			printf("%s", prompt);
			
			continue;
		}
		
		/* Validation format is an error if there are numbers in the name */
		if((validation = sscanf(inputLine, " %[a-zA-Z-] , %[a-zA-Z-] %d ", lastName, firstName, &junk)) == 3)
		{
			printf("*** ERROR: Invalid name! ***\n");
			
			printf("Please enter a student name (type !! to quit):\n");
			printf("%s", prompt);
			
			continue;
		}
	
		/* Validation format for 'lastName, firstName' */
		if((validation = sscanf(inputLine, " %[a-zA-Z-] , %[a-zA-Z-] ", lastName, firstName)) == 2)
		{
		
			printf("Please enter a score between 0 and 100 inclusive for this student:\n");
			printf("%s", prompt);
		
			while(fgets(inputLine, LINESIZE, standardInput) != NULL)
			{
				if((validation = sscanf(inputLine, "%d", &studentScore)) == 1)
				{
					if((studentScore >= 0) && (studentScore <= 100))
					{
						fprintf(fileInput, "%s %s %d\r\n", firstName, lastName, studentScore);
				
						return 1;
					}
			
					printf("*** ERROR: Invalid score! ***\n");
			
					printf("Please enter a score between 0 and 100 inclusive for this student:\n");
					printf("%s", prompt);
			
					continue;
				}
		
				printf("*** ERROR: Invalid score! ***\n");
			
				printf("Please enter a score between 0 and 100 inclusive for this student:\n");
				printf("%s", prompt);
			}
	
			clearerr(standardInput);
	
			return 0;
		}
		
		/* Validation format for 'firstName lastName' */
		if((validation = sscanf(inputLine, " %[a-zA-Z-] %[a-zA-Z-] ", firstName, lastName)) == 2)
		{		
			printf("Please enter a score between 0 and 100 inclusive for this student:\n");
			printf("%s", prompt);
		
			while(fgets(inputLine, LINESIZE, standardInput) != NULL)
			{
				if((validation = sscanf(inputLine, "%d", &studentScore)) == 1)
				{
					if((studentScore >= 0) && (studentScore <= 100))
					{
						fprintf(fileInput, "%s %s %d\r\n", firstName, lastName, studentScore);
				
						return 1;
					}
			
					printf("*** ERROR: Invalid score! ***\n");
			
					printf("Please enter a score between 0 and 100 inclusive for this student:\n");
					printf("%s", prompt);
			
					continue;
				}
		
				printf("*** ERROR: Invalid score! ***\n");
			
				printf("Please enter a score between 0 and 100 inclusive for this student:\n");
				printf("%s", prompt);
			}
	
			clearerr(standardInput);
	
			return 0;
		}
		
		/* Validation format for returning to the main menu */
		if((validation = sscanf(inputLine, "%s", firstName)) == 1)
		{
			if(strcmp(firstName, "!!") == 0)
			{
				printf("Returning to the main menu...\n");
			
				return 0;
			}
		}
		
		printf("*** ERROR: Invalid name! ***\n");
			
		printf("Please enter a student name (type !! to quit):\n");
		printf("%s", prompt);
			
		continue;
	}
	
	clearerr(standardInput);
	
	return 0;
}

int displayData(FILE * fileInput)
{
	char inputLine[LINESIZE];
	char lastName[LINESIZE];
	char firstName[LINESIZE];
	int score;
	int minScore = 101;
	int maxScore = -1;
	double sumScores = 0;
	double totalScores = 0;
	int validation;
	size_t n = 1;
	
	if(fseek(fileInput, 0, SEEK_SET) != 0)
	{
		perror("fseek");
		
		return 0;
	}
	
	while(fgets(inputLine, LINESIZE, fileInput) != NULL)
	{
		if((validation = sscanf(inputLine, "%s %s %d", firstName, lastName, &score)) == 3)
		{
			lastName[0] = (toupper((unsigned char)lastName[0]));
			firstName[0] = (toupper((unsigned char)firstName[0]));
			
			for(n = 1; n != '\n'; n++)
			{
				lastName[n] = (tolower((unsigned char)lastName[n]));
				firstName[n] = (tolower((unsigned char)firstName[n]));
			}
			
			sumScores = sumScores + (double)score;
			totalScores = totalScores + 1.0;
			
			if(score < minScore)
			{
				minScore = score;
			}
			
			if(score > maxScore)
			{
				maxScore = score;
			}
	
			fprintf(stderr, "%s, %s: %3d\n", lastName, firstName, score);
		}
	}
	
	fprintf(stderr, "Min: %3d, Max: %3d, Ave:  %.2f\n", minScore, maxScore, sumScores / totalScores);
	
	printf("Returning to main menu...\n");
	
	return 1;
}
