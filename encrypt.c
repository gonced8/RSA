#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME 20
#define TEXT 250
#define PRIME1 1024
#define PRIME2 1024
#define PUBLIC 50

int modular_exponentiation(char a[], char b[], char m[], char r[]);


int encrypt(int argc, char **argv)
{
	int mode=-1;
	FILE *read = NULL;
	char filename[FILENAME] = {'\0'};
	char before[TEXT] = {'\0'};
	char after[PRIME1+PRIME2+1] = {'\0'};
	char public[PUBLIC+1]={'\0'};
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
			fgets(before, TEXT, stdin);
			before[strlen(before)-1]='\0';
			while(before[0]=='0')
			{
				memmove(before, before+1, (strlen(before)-1)*sizeof(char));
				before[strlen(before)-1]='\0';
			}
			break;
	}
	
	while(1)
	{
		printf("\nInsert public key:\n");
		fgets(public, PRIME1, stdin);
		public[strlen(public)-1]='\0';
		
		
		printf("\nInsert n:\n");
		fgets(n, PRIME1+PRIME2, stdin);
		n[strlen(n)-1]='\0';
		
		
		if(strlen(n)<strlen(before))
		{
			printf("\nn can't have less digits than message. Try again:\n\n");
			memset(public, '\0', strlen(public)*sizeof(char));
			memset(n, '\0', strlen(n)*sizeof(char));
			continue;
		}
		
		break;
	}
	
	modular_exponentiation(before, public, n, after);
	
	printf("\nEncrypted message:\n%s\n", after);
	
	if(mode==0)
		fclose(read);
	
	return 0;
}

