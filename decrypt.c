#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME 20
#define TEXT 250
#define PRIME1 1024
#define PRIME2 1024
#define PUBLIC 50

int modular_exponentiation(char a[], char b[], char m[], char r[]);


int decrypt(int argc, char **argv)
{
	int mode=-1;
	FILE *read = NULL;
	char filename[FILENAME] = {'\0'};
	char before[PRIME1+PRIME2+1] = {'\0'};
	char after[TEXT] = {'\0'};
	char private[PRIME1+PRIME2+1]={'\0'};
	char n[PRIME1+PRIME2+1]={'0'};
	
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
			fgets(before, PRIME1+PRIME2+1, stdin);
			before[strlen(before)-1]='\0';
			break;
	}
	
	printf("\nInsert private key:\n");
	fgets(private, PRIME1+PRIME2, stdin);
	private[strlen(private)-1]='\0';
	
	printf("\nInsert n:\n");
	fgets(n, PRIME1+PRIME2, stdin);
	n[strlen(n)-1]='\0';
	
	modular_exponentiation(before, private, n, after);
	
	printf("\nDecrypted message:\n%s\n", after);
	
	if(mode==0)
		fclose(read);
	
	return 0;
}

