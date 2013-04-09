#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LINESIZE 1024

int menu(const char *choices[], const char *prompt);

int main(void)
{
	const char *choices[] = {"Enter data", "Display data", "Quit", 0};
	
	menu(choices, "> ");
	
	return 0;
}

int menu(const char *choices[], const char *prompt)
{
	size_t i;
	int n;
	int menuCounter = 1;
	char userChoice[LINESIZE];
	int userIntChoice;
	
	for(i = 0; choices[i] != 0; i++, menuCounter++)
	{
		printf("%d. %s\n", menuCounter, choices[i]);
	}
	
	printf("%s", prompt);

	while(fgets(userChoice, LINESIZE, stdin) != NULL)
	{
		if((n = sscanf(userChoice, "%d", &userIntChoice)) == 1)
		{
			if((userIntChoice > 0) && (userIntChoice < menuCounter))
			{
				printf("Your choice: %d", userIntChoice);
				return userIntChoice;
			}
			
			printf("Invalid choice! Please retry:\n");
			printf("%s", prompt);
			continue;
		}
		
		printf("Invalid choice! Please retry:\n");
		printf("%s", prompt);
	}

	clearerr(stdin);
	return 0;
}
