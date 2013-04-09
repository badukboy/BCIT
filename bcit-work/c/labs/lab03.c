#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int c;
	int spaceCount = 0;
	int newLineCount = 0;
	
	while((c = getchar()) != EOF)
	{	
		/* Replace tabs with spaces */
		if(c == '\t')
		{
			c = ' ';
		}
		
		/* Replace 2 or more spaces with 1 space */
		if(c == ' ')
		{	
			if(++spaceCount < 2)
			{
				putchar(c);
			}
			
			continue;
			
			
		}
		
		spaceCount = 0;
		
		/* Replace 2 or more newlines with 1 newline */
		if(c == '\n')
		{	
			if(++newLineCount < 3)
			{	
				putchar(c);
			}

			continue;
		}
		
		newLineCount = 0;
		
		putchar(c);
	}
	
	return 0;
}
