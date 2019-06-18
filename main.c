#include <stdio.h>

int ascii_to_text(int argc, char **argv);
int generate_keys (int argc, char **argv);
int text_to_ascii(int argc, char **argv);
int encrypt(int argc, char **argv);
int decrypt(int argc, char **argv);
int modular_exponentiation(char a[], char b[], char m[], char r[]);


int main (int argc, char **argv)
{
	int mode=-1;
	
	while(mode!=0)
	{
		printf("\n********************\n");
		printf("\ntext_ascii\n");
		printf("\nSelect mode:\n");
		printf("1: Convert text to ascii\n");
		printf("2: Convert ascii to text\n");
		printf("3: Generate keys\n");
		printf("4: Encrypt message\n");
		printf("5: Decrypt message\n");
		printf("0: Exit\n");
		
		scanf("%d", &mode);
		
		switch (mode)
		{
			case 1:
				printf("\nConvert text to ascii\n");
				text_to_ascii(argc, argv);
				break;
				
			case 2:
				printf("\nConvert ascii to text\n");
				ascii_to_text(argc, argv);
				break;
				
			case 3:
				printf("\nGenerate keys\n");
				generate_keys(argc, argv);
				break;
				
			case 4:
				printf("\nEncrypt message\n");
				encrypt(argc, argv);
				break;
				
			case 5:
				printf("\nDecrypt message\n");
				decrypt(argc, argv);
				break;
				
			case 0:
				return 0;
				break;
				
			default:
				printf("\nInvalid input. Try again\n");
				return 1;
		}
	}
	
	return 0;	
}

