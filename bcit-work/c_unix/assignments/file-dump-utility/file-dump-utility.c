/* -----------------------------------------------------------------------------
	COMP2510 ASSIGNMENT 2 - FILE DUMP UTILITY
	Written by Kevin Csapko
----------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ON  1
#define OFF 0
#define LINESIZE 1024

int checkArgs(int index, char *argv[], int *flags, int *values);
int checkLengthOffsetArgs(int index, char *argv[]);
void processDump(int *flags, int *values, FILE *fp);
void dumpHex(FILE *fp, int *values);
void dumpOct(FILE *fp, int *values);
void dumpOctPrt(FILE *fp, int *values);
void dumpHexAsc(FILE *fp);

/*
	Main method.
*/
int main(int argc, char *argv[])
{
	/* Hexadecimal, Octal, Character, Hexadecimal and ASCII, Length, Offset */
	int optionFlags[] = {ON, OFF, OFF, OFF, OFF, OFF};
	
	/* Length bytes of input to interpret, Offset bytes from beginning */
	int optionValues[] = {0, 0};
	
	int *flags = optionFlags;
	int *values = optionValues;
	int i = 1;
	int checkArgsValidation = 0;
	
	if(argv[1] == NULL)
	{
		printf("No arguments specified. Qutting program...\n");
		
		return 1;
	}
	
	for(i = 1; i < argc; i++)
	{	
		checkArgsValidation = checkArgs(i, argv, flags, values);
	
		if(checkArgsValidation == 0)
		{
			break;
		}
	}
	
	return 0;
}

/*
	Checks the command line arguments and activates/deactivates flags
	accordingly. Also checks for cases where the command line arguments
	are invalid.
*/
int checkArgs(int index, char *argv[], int *flags, int *values)
{	
	int foundSwitch = OFF;
	int foundSwitchEnd = OFF;
	int foundFile = OFF;
	FILE *fp;
	
	if(argv[index][0] == '-')
	{
		foundSwitch = ON;
	}
	
	if(foundSwitch == ON)
	{
		switch(argv[index][1])
		{
			case 'b':
				flags[0] = OFF;
				flags[1] = ON;
				flags[2] = OFF;
				flags[3] = OFF;
				break;
				
			case 'c':
				flags[0] = OFF;
				flags[1] = OFF;
				flags[2] = ON;
				flags[3] = OFF;
				break;
				
			case 'C':
				flags[0] = OFF;
				flags[1] = OFF;
				flags[2] = OFF;
				flags[3] = ON;
				break;
				
			case 'n':
				values[0] = checkLengthOffsetArgs(index, argv);
				flags[4] = ON;
				break;
				
			case 's':
				values[1] = checkLengthOffsetArgs(index, argv);
				flags[5] = ON;
				break;
				
			case '-':
				foundSwitchEnd = ON;
				foundSwitch = OFF;
				break;
				
			default:
				printf("Invalid\n");
				return 2;
		}
	}
	
	if((foundSwitchEnd == ON) && (argv[index+1] == NULL))
	{
		printf("Invalid");
		
		return 2;
	}
	
	/* If the switch end (--) argument is found */
	if((foundSwitchEnd == ON))
	{
		foundFile = ON;
		
		if((fp = fopen(argv[index], "r")) == 0)
		{
			perror("fopen");
		
			return 3;
		}
		
		processDump(flags, values, fp);
		
		return 0;
	}
	
	/* If the switch end (--) is not specified */
	if((foundSwitch == OFF) && (foundSwitchEnd == OFF))
	{
		foundFile = ON;
		
		if((fp = fopen(argv[index], "r")) == 0)
		{
			perror("fopen");
		
			return 3;
		}
		
		processDump(flags, values, fp);
		
		return 0;
	}
	
	return 1;
}

/*
	In the case that a value flag is set, such as the offset or length flags,
	function determines the value and returns it in decimal form given the
	input value is either hexadecimal, octal, or decimal.
*/
int checkLengthOffsetArgs(int index, char *argv[])
{
	unsigned int nonDecimalValue;
	int value;
	char stringValue[LINESIZE];
	size_t i, j;
	
	/* If specified value is hexadecimal... */
	if((argv[index][2] == '0') && (argv[index][3] == 'x'))
	{
		for(i = 2, j = 0; argv[index][i] != '\0'; i++, j++)
		{
			stringValue[j] = argv[index][i];
		}
		
		stringValue[j] = '\0';
		
		sscanf(stringValue, "%x", &nonDecimalValue);
		
		return nonDecimalValue;
	}
	
	/* If specified value is octal... */
	if(argv[index][2] == '0')
	{
		for(i = 2, j = 0; argv[index][i] != '\0'; i++, j++)
		{
			stringValue[j] = argv[index][i];
		}
		
		stringValue[j] = '\0';
		
		sscanf(stringValue, "%o", &nonDecimalValue);
		
		return nonDecimalValue;
	}
	
	/* If specified value is decimal... */
	for(i = 2, j = 0; argv[index][i] != '\0'; i++, j++)
	{
		stringValue[j] = argv[index][i];
	}	
	
	stringValue[j] = '\0';
	
	sscanf(stringValue, "%d", &value);
	
	return value;
}

/*
	Determines how to proceed with the file dump based on finalized
	command-line arguments.
*/
void processDump(int *flags, int *values, FILE *fp)
{		
	if(flags[0] == ON)
	{
		dumpHex(fp, values);
	}
	
	if(flags[1] == ON)
	{
		dumpOct(fp, values);
	}
	
	if(flags[2] == ON)
	{
		dumpOctPrt(fp, values);
	}
	
	if(flags[3] == ON)
	{
		dumpHexAsc(fp);
	}
	
	if(fclose(fp) != 0)
	{
		perror("fclose");
	}
}

/*
	Dump the file in hexadecimal (default switch).
*/
void dumpHex(FILE *fp, int *values)
{
	int c;
	int characterCount = 0;
	int offsetValue = values[1];
	int lengthValue = values[0];
	
	if(fseek(fp, values[1], SEEK_SET) != 0)
	{
		perror("fseek");
	}
	
	while((c = fgetc(fp)) != EOF)
	{	
		if(characterCount % 16 == 0)
		{
			if(characterCount == 0)
			{
				fprintf(stdout, "%07x", offsetValue);
			}
			else
			{
				fprintf(stdout, "\n%07x", offsetValue);
			}
		}
	
		fprintf(stdout, " %02x", c);
		
		characterCount++;
		offsetValue++;
		
		if(characterCount == lengthValue)
		{
			break;
		}
	}
	
	fprintf(stdout, "\n%07x\n", offsetValue);
}

/*
	Dump the file in octal (-b switch).
*/
void dumpOct(FILE *fp, int *values)
{
	int c;
	int characterCount = 0;
	int offsetValue = values[1];
	int lengthValue = values[0];
	
	if(fseek(fp, values[1], SEEK_SET) != 0)
	{
		perror("fseek");
	}
	
	while((c = fgetc(fp)) != EOF)
	{	
		if(characterCount % 16 == 0)
		{
			if(characterCount == 0)
			{
				fprintf(stdout, "%07x", offsetValue);
			}
			else
			{
				fprintf(stdout, "\n%07x", offsetValue);
			}
		}
	
		fprintf(stdout, " %03o", c);
		
		characterCount++;
		offsetValue++;
		
		if(characterCount == lengthValue)
		{
			break;
		}
	}
	
	fprintf(stdout, "\n%07x\n", offsetValue);
}

/*
	Dump the file in octal/printable characters (-c switch).
*/
void dumpOctPrt(FILE *fp, int *values)
{
	int c;
	int characterCount = 0;
	int offsetValue = values[1];
	int lengthValue = values[0];
	int foundEscapeChar = OFF;
	
	while((c = fgetc(fp)) != EOF)
	{	
		if(characterCount % 16 == 0)
		{
			if(characterCount == 0)
			{
				fprintf(stdout, "%07x", offsetValue);
			}
			else
			{
				fprintf(stdout, "\n%07x", offsetValue);
			}
		}
	
		switch(c)
		{	
			case '\0':
				fprintf(stdout, "  \\0");
				foundEscapeChar = ON;
				break;
		
			case '\a':
				fprintf(stdout, "  \\a");
				foundEscapeChar = ON;
				break;
				
			case '\b':
				fprintf(stdout, "  \\b");
				foundEscapeChar = ON;
				break;
				
			case '\f':
				fprintf(stdout, "  \\f");
				foundEscapeChar = ON;
				break;
				
			case '\n':
				fprintf(stdout, "  \\n");
				foundEscapeChar = ON;
				break;
				
			case '\r':
				fprintf(stdout, "  \\r");
				foundEscapeChar = ON;
				break;
				
			case '\t':
				fprintf(stdout, "  \\t");
				foundEscapeChar = ON;
				break;
				
			case '\v':
				fprintf(stdout, "  \\v");
				foundEscapeChar = ON;
				break;
		}
	
		if(foundEscapeChar == ON)
		{
			foundEscapeChar = OFF;
			
			characterCount++;
			offsetValue++;
			
			continue;
		}
	
		if(isprint(c))
		{
			fprintf(stdout, "   %c", c);
		}
		else
		{
			fprintf(stdout, " %03o", c);
		}
		
		characterCount++;
		offsetValue++;
		
		if(characterCount == lengthValue)
		{
			break;
		}
	}
	
	fprintf(stdout, "\n%07x\n", offsetValue);
}

/*
	Dump file in hexadecimal/ASCII format (-C switch).
*/
void dumpHexAsc(FILE *fp)
{
	int c, d;
	int characterCount = 0;
	int seekPosition = 0;
	int lineCharCount = 0;
	
	while((c = fgetc(fp)) != EOF)
	{	
		if(characterCount % 8 == 0)
		{
			if(characterCount != 0)
			{
				printf(" ");
			}
		}
	
		if(characterCount % 16 == 0)
		{	
			if(characterCount == 0)
			{
				fprintf(stdout, "%07x", characterCount);
			}
			else
			{
				fprintf(stdout, " |");

				if(fseek(fp, seekPosition, SEEK_SET) != 0)
				{
					perror("fseek");
				}
				
				lineCharCount = 0;
				
				while((d = fgetc(fp)) != EOF)
				{
					if(isprint(d))
					{
						fprintf(stdout, "%c", d);
					}
					else
					{
						printf(".");
					}
					
					lineCharCount++;
					
					if(lineCharCount == 16)
					{
						seekPosition += 16;
						
						break;
					}
				}

				fprintf(stdout, "|");
				fprintf(stdout, "\n%07x", characterCount);
			}
		}

		characterCount++;
		fprintf(stdout, " %02x", c);
	}
	
	fprintf(stdout, "\n%07x\n", characterCount);
}
