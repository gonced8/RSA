#include <stdio.h>
#include <string.h>

#define FILENAME 20
#define TEXT 250
#define ASCII 250*3
#define DECIMAL 3

int text_to_ascii(int argc, char **argv)
{
	int mode=-1;
	FILE *read = NULL;
	char filename[FILENAME] = {'\0'};
	char text[TEXT] = {'\0'};
	char ascii[ASCII] = {'\0'};
	char c;
	char dec[DECIMAL+1] = {'\0'};
	int i=0;
	int len=0;
	
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
			printf("Input text:\n");
			getchar(); /* To clean buffer */
			fgets(text, TEXT, stdin);
			text[strlen(text)-1]='\0';			
			break;
	}
		
	while(1)
	{
		if(mode==1)
		{
			c=getc(read);
			if(c==EOF)
				break;
		}
		else if(mode==2)
		{
			c=text[i];
			if(c=='\0')
				break;
		}
		
		sprintf(dec, "%d", (int)c);
		dec[DECIMAL]='\0';
		
		len=strlen(dec);
		if(len<DECIMAL)
		{
			memmove(&dec[DECIMAL-len], dec, len*sizeof(char));
			memset(dec, '0', DECIMAL-len);
		}
		
		memmove(&ascii[i*DECIMAL], dec, DECIMAL*sizeof(char));
		
		i=i+1;
	}
	
	printf("\nASCII:\n%s\n", ascii);
		
	if(mode==1)
		fclose(read);
	
	return 0;
}


