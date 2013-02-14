#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void dumpHex(FILE *filePointer);
void dumpOct(FILE *filePointer);

int main(void)
{
	FILE * fp;
	
	if((fp = fopen("data.txt", "r")) == 0)
	{
		perror("fopen");
		
		return 1;
	}
	
	printf("HEXADECIMAL DUMP:\n\n");
	dumpHex(fp);
	
	printf("\n\n");
	
	if(fseek(fp, 0, SEEK_SET) != 0)
	{
		perror("fseek");
		
		return 1;
	}
	
	printf("OCTAL DUMP:\n\n");
	dumpOct(fp);
	
	fclose(fp);
	
	return 0;
}

void dumpHex(FILE *filePointer)
{
	int c;
	int characterCount = 0;
	
	while((c = fgetc(filePointer)) != EOF)
	{	
		if(characterCount % 16 == 0)
		{
			printf("\n");
			fprintf(stdout, "%07x ", characterCount);
		}
	
		fprintf(stdout, "%03x ", c);
		
		characterCount++;
	}
	
	fprintf(stdout, "\n%07x ", characterCount);
}

void dumpOct(FILE *filePointer)
{
	int c;
	int characterCount = 0;

	while((c = fgetc(filePointer)) != EOF)
	{	
		if(characterCount % 16 == 0)
		{
			printf("\n");
			fprintf(stdout, "%07x ", characterCount);
		}
	
		fprintf(stdout, "%03o ", c);
		
		characterCount++;
	}
	
	fprintf(stdout, "\n%07x ", characterCount);
}
