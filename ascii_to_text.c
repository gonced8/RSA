#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME 20
#define TEXT 250
#define ASCII 250*3
#define DECIMAL 3

int ascii_to_text(int argc, char **argv)
{
	int mode=-1;
	FILE *read = NULL;
	char filename[FILENAME] = {'\0'};
	char text[TEXT] = {'\0'};
	char ascii[ASCII] = {'\0'};
	char c;
	char dec[DECIMAL+1] = {'\0'};
	int i=0;
	int t=1;
	int len=DECIMAL+1;
	
	printf("\nSelect option\n");
	printf("1: Convert from text file\n");
	printf("2: Convert from input text\n");
	scanf("%d", &mode);
	
	switch (mode)
	{
		case 1:
			printf("\nConvert from text file\n");
			printf("Input text file name:\n");
			scanf("%s", filename);
			read=fopen(strcat(filename, ".txt"), "r");
			
			while(read==NULL)
			{
				printf("Invalid filename. Insert file name to try again.\n");
				memset(filename, '\0', FILENAME);
				scanf("%s", filename);
				read=fopen(strcat(filename, ".txt"), "r");
			}
			
			printf("%s opened.\n", filename);
			break;
			
		case 2:
			printf("\nConvert from input text\n");
			printf("Input ascii:\n");
			getchar(); /* To clean buffer */
			fgets(ascii, ASCII, stdin);
			ascii[strlen(ascii)-1]='\0';
			
			while(strlen(ascii)%DECIMAL!=0)
			{
				memmove(ascii+1, ascii, strlen(ascii)*sizeof(char));
				ascii[0]='0';
			}
			break;
	}
	
	while(t)
	{
		if(mode==1)
		{
			fgets(dec, len, read);
			if(feof(read))
				break;
		}	
		else if(mode==2)
		{
			if(ascii[i*DECIMAL]=='\0')
				break;
			memmove(dec, &ascii[i*DECIMAL], DECIMAL*sizeof(char));
		}
		
		c=atoi(dec);
		
		text[i]=c;
		
		i=i+1;
		
		if(i==TEXT-1)
			break;
	}	
	
	printf("\nTEXT:\n%s\n", text);

	if(mode==1)
		fclose(read);

	return 0;
}

